/* p_vmlinz.cpp --

   This file is part of the UPX executable compressor.

   Copyright (C) 1996-2000 Markus Franz Xaver Johannes Oberhumer
   Copyright (C) 1996-2000 Laszlo Molnar
   All Rights Reserved.

   UPX and the UCL library are free software; you can redistribute them
   and/or modify them under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.
   If not, write to the Free Software Foundation, Inc.,
   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

   Markus F.X.J. Oberhumer                   Laszlo Molnar
   markus.oberhumer@jk.uni-linz.ac.at        ml1050@cdata.tvnet.hu
 */


#include "conf.h"

#include "file.h"
#include "packer.h"
#include "p_vmlinz.h"
#include <zlib.h>

static const
#include "stub/l_vmlinz.h"

static const unsigned kernel_entry = 0x100000;
static const unsigned stack_during_uncompression = 0x90000;

// from /usr/src/linux/arch/i386/boot/compressed/Makefile
static const unsigned zimage_offset = 0x1000;
static const unsigned bzimage_offset = 0x100000;


/*************************************************************************
//
**************************************************************************/

PackVmlinuzI386::PackVmlinuzI386(InputFile *f) :
    super(f)
{
    assert(sizeof(boot_sect_t) == 0x218);
}


int PackVmlinuzI386::getCompressionMethod() const
{
    if (M_IS_NRV2B(opt->method))
        return M_NRV2B_LE32;
    if (M_IS_NRV2D(opt->method))
        return M_NRV2D_LE32;
    return opt->level > 1 ? M_NRV2D_LE32 : M_NRV2B_LE32;
}


const int *PackVmlinuzI386::getFilters() const
{
    return NULL;
}


bool PackVmlinuzI386::canPack()
{
    return readFileHeader() == getFormat();
}


/*************************************************************************
// common util routines
**************************************************************************/

int PackVmlinuzI386::readFileHeader()
{
    boot_sect_t h;

    fi->readx(&h, sizeof(h));
    if (h.boot_flag != 0xAA55)
        return -1;
    // FIXME: add more checks for a valid kernel

    setup_size = (1 + (h.setup_sects ? h.setup_sects : 4)) * 0x200;
    if (setup_size > file_size)
        return -1;

    if (memcmp(h.hdrs, "HdrS", 4) == 0 && (h.load_flags & 1) != 0)
        return UPX_F_BVMLINUZ_i386;

    return UPX_F_VMLINUZ_i386;
}


// read full kernel into obuf, gzip-uncompress into ibuf,
// return uncompressed size
int PackVmlinuzI386::uncompressKernel()
{
    // read whole kernel image
    obuf.alloc(file_size);
    fi->seek(0, SEEK_SET);
    fi->readx(obuf, file_size);

    // find gzip/zlib header
    // FIXME - improve this
    int gzoff = setup_size;
    while (gzoff < file_size)
    {
        int off = find(obuf + gzoff, file_size - gzoff, "\x1F\x8B", 2);
        if (off < 0)
            return 0;
        gzoff += off;
        break;
    }
    if (gzoff >= file_size)
        return 0;

    // estimate gzip-uncompressed kernel size
    int isize = file_size - gzoff;
    isize = UPX_MAX(3 * isize, 4*1024*1024);

    // alloc buffer to hold the gzip-uncompressed kernel
    ibuf.alloc(isize);

    // gzip-uncompress
    fi->seek(gzoff, SEEK_SET);
    gzFile zf = gzdopen(fi->getFd(), "r");
    if (zf == 0)
        return 0;
    int klen = gzread(zf, ibuf, isize);
    if (klen <= 0 || klen <= file_size)
        return 0;
    if (klen >= isize)
        throwCantPack("kernel is too big - send a bug report");

    // success
    return klen;
}


void PackVmlinuzI386::readKernel()
{
    int klen = uncompressKernel();
    if (klen <= 0)
        throwCantPack("kernel decompression failed");

    //OutputFile::dump("kernel.img", ibuf, klen);

    // copy the setup boot code
    setup_buf.alloc(setup_size);
    memcpy(setup_buf, obuf, setup_size);

    obuf.free();
    obuf.allocForCompression(ibuf.getSize());

    ph.u_len = klen;
}


/*************************************************************************
// vmlinuz specific
**************************************************************************/

void PackVmlinuzI386::pack(OutputFile *fo)
{
    readKernel();

    if (!compress(ibuf, obuf))
        throwNotCompressible();

    const unsigned clen = ph.c_len;

    initLoader(nrv_loader, sizeof(nrv_loader));

    addLoader("LINUZ000""LZIMAGE0",
              getDecompressor(),
              "LINUZ990""IDENTSTR""UPX1HEAD",
              NULL
             );

    const unsigned lsize = getLoaderSize();
    MemBuffer loader(lsize);
    memcpy(loader, getLoader(), lsize);

    patchPackHeader(loader, lsize);

    patch_le32(loader, lsize, "ESI1", zimage_offset + lsize);

    patch_le32(loader, lsize, "KEIP", kernel_entry);
    patch_le32(loader, lsize, "STAK", stack_during_uncompression);

    boot_sect_t *bs = (boot_sect_t *) ((unsigned char *) setup_buf);
    bs->sys_size = ALIGN_UP(lsize + clen, 16) / 16;

    fo->write(setup_buf, setup_buf.getSize());
    fo->write(loader, lsize);
    fo->write(obuf, clen);
#if 0
    printf("%-13s: setup        : %8ld bytes\n", getName(), (long) setup_buf.getSize());
    printf("%-13s: loader       : %8ld bytes\n", getName(), (long) lsize);
    printf("%-13s: compressed   : %8ld bytes\n", getName(), (long) clen);
#endif

    // finally check the compression ratio
    if (!checkFinalCompressionRatio(fo))
        throwNotCompressible();
}


/*************************************************************************
// bvmlinuz specific
**************************************************************************/

void PackBvmlinuzI386::pack(OutputFile *fo)
{
    readKernel();

    if (!compress(ibuf, obuf))
        throwNotCompressible();

    const unsigned overlapoh = findOverlapOverhead(obuf, 512);

    // align everything to dword boundary - it is easier to handle
    unsigned clen = ph.c_len;
    memset(obuf + clen, 0, 4);
    clen = ALIGN_UP(clen, 4);

    initLoader(nrv_loader, sizeof(nrv_loader));

    addLoader("LINUZ000""LBZIMAGE""IDENTSTR",
              "+40D++++", // align the stuff to 4 byte boundary
              "UPX1HEAD", // 32 byte
              "LZCUTPOI""+0000000",
              getDecompressor(),
              "LINUZ990",
              NULL
             );

    const unsigned lsize = getLoaderSize();
    MemBuffer loader(lsize);
    memcpy(loader, getLoader(), lsize);

    patchPackHeader(loader, lsize);

    const int e_len = getLoaderSectionStart("LZCUTPOI");
    assert(e_len > 0);

    const unsigned d_len4 = ALIGN_UP(lsize - e_len, 4);
    const unsigned decompr_pos = ALIGN_UP(ph.u_len + overlapoh, 16);
    const unsigned copy_size = clen + d_len4;
    const unsigned edi = decompr_pos + d_len4 - 4;          // copy to
    const unsigned esi = ALIGN_UP(clen + lsize, 4) - 4;     // copy from

    unsigned jpos = find_le32(loader, e_len, get_le32("JMPD"));
    patch_le32(loader, e_len, "JMPD", decompr_pos - jpos - 4);

    patch_le32(loader, e_len, "ESI1", bzimage_offset + decompr_pos - clen);
    patch_le32(loader, e_len, "ECX0", copy_size / 4);
    patch_le32(loader, e_len, "EDI0", bzimage_offset + edi);
    patch_le32(loader, e_len, "ESI0", bzimage_offset + esi);

    patch_le32(loader, e_len, "KEIP", kernel_entry);
    patch_le32(loader, e_len, "STAK", stack_during_uncompression);

    boot_sect_t *bs = (boot_sect_t *) ((unsigned char *) setup_buf);
    bs->sys_size = ALIGN_UP(lsize + clen, 16) / 16;

    fo->write(setup_buf, setup_buf.getSize());
    fo->write(loader, e_len);
    fo->write(obuf, clen);
    fo->write(loader + e_len, lsize - e_len);
#if 0
    printf("%-13s: setup        : %8ld bytes\n", getName(), (long) setup_buf.getSize());
    printf("%-13s: entry        : %8ld bytes\n", getName(), (long) e_len);
    printf("%-13s: compressed   : %8ld bytes\n", getName(), (long) clen);
    printf("%-13s: decompressor : %8ld bytes\n", getName(), (long) (lsize - e_len));
#endif

    // verify
    verifyOverlappingDecompression(&obuf, overlapoh);

    // finally check the compression ratio
    if (!checkFinalCompressionRatio(fo))
        throwNotCompressible();
}


/*************************************************************************
// unpack
**************************************************************************/

int PackVmlinuzI386::canUnpack()
{
    return false;
}


void PackVmlinuzI386::unpack(OutputFile *)
{
    // no uncompression support for this format, so that
    // it is possible to remove the original deflate code (>10KB)
    throwCantUnpack("build a new kernel instead :-)");
}


/*
vi:ts=4:et
*/


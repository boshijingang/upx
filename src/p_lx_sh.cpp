/* p_lx_sh.cpp --

   This file is part of the UPX executable compressor.

   Copyright (C) 1996-2001 Markus Franz Xaver Johannes Oberhumer
   Copyright (C) 1996-2001 Laszlo Molnar
   Copyright (C) 2000-2001 John F. Reiser
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

   John F. Reiser
   jreiser@BitWagon.com
 */


#include "conf.h"

#include "file.h"
#include "packer.h"
#include "p_elf.h"
#include "p_unix.h"
#include "p_lx_exc.h"
#include "p_lx_sh.h"

#define PT_LOAD     Elf_LE32_Phdr::PT_LOAD


/*************************************************************************
//
**************************************************************************/

static const
#include "stub/l_sh_n2b.h"
static const
#include "stub/l_sh_n2d.h"


PackLinuxI386sh::PackLinuxI386sh(InputFile *f) :
    super(f), o_shname(0), l_shname(0)
{
}

PackLinuxI386sh::~PackLinuxI386sh()
{
}

const upx_byte *PackLinuxI386sh::getLoader() const
{
    if (M_IS_NRV2B(ph.method))
        return linux_i386sh_nrv2b_loader;
    if (M_IS_NRV2D(ph.method))
        return linux_i386sh_nrv2d_loader;
    return NULL;
}

int PackLinuxI386sh::getLoaderSize() const
{
    if (0 != lsize) {
        return lsize;
    }
    if (M_IS_NRV2B(ph.method))
        return sizeof(linux_i386sh_nrv2b_loader);
    if (M_IS_NRV2D(ph.method))
        return sizeof(linux_i386sh_nrv2d_loader);
    return 0;
}


void PackLinuxI386sh::patchLoader()
{
    lsize = getLoaderSize();
    Elf_LE32_Ehdr *const ehdr = (Elf_LE32_Ehdr *)(void *)loader;
    Elf_LE32_Phdr *const phdr = (Elf_LE32_Phdr *)(1+ehdr);

    patch_le32(loader,lsize,"UPX3",l_shname);
    patch_le32(loader,lsize,"UPX2",o_shname);

    // stub/scripts/setfold.pl puts address of 'fold_begin' in phdr[1].p_offset
    off_t const fold_begin = phdr[1].p_offset;
    assert(fold_begin > 0);
    assert(fold_begin < (off_t)lsize);
    MemBuffer cprLoader(lsize);

    // compress compiled C-code portion of loader
    upx_uint const uncLsize = lsize - fold_begin;
    upx_uint       cprLsize;
    int r = upx_compress(loader + fold_begin, uncLsize, cprLoader, &cprLsize,
                         NULL, ph.method, 10, NULL, NULL);
    if (r != UPX_E_OK || cprLsize >= uncLsize)
        throwInternalError("loaded compression failed");

    set_le32(0+fold_begin+loader, uncLsize);
    set_le32(4+fold_begin+loader, cprLsize);
    memcpy(  8+fold_begin+loader, cprLoader, cprLsize);
    lsize = 8 + fold_begin + cprLsize;
    patchVersion(loader,lsize);

    // Info for OS kernel to set the brk()
    unsigned const brka = getbrk(phdr, ehdr->e_phnum);
    phdr[1].p_offset = 0xfff&brka;
    phdr[1].p_vaddr = brka;
    phdr[1].p_paddr = brka;
    phdr[1].p_filesz = 0;
    phdr[1].p_memsz =  0;

    // The beginning of our loader consists of a elf_hdr (52 bytes) and
    // two sections elf_phdr (2 * 32 byte), so we have 12 free bytes
    // from offset 116 to the program start at offset 128.
    assert(ehdr->e_phoff == sizeof(Elf_LE32_Ehdr));
    assert(ehdr->e_ehsize == sizeof(Elf_LE32_Ehdr));
    assert(ehdr->e_phentsize == sizeof(Elf_LE32_Phdr));
    assert(ehdr->e_phnum == 2);
    assert(ehdr->e_shnum == 0);
    assert(lsize > 128 && lsize < 4096);

    patchLoaderChecksum();
}


bool PackLinuxI386sh::getShellName(char *buf)
{
    exetype = -1;
    l_shname = strcspn(buf, " \t\n\v\f\r");
    buf[l_shname] = 0;
    char const *const basename = 1+strrchr(buf, '/');
    static char const *const shname[] = { // known shells that accept "-c" arg
        "sh", "ash", "bsh", "csh", "ksh", "bash", "tcsh", "pdksh",
        //"python", // FIXME: does python work ???
        NULL
    };
    for (int j=0; 0 != shname[j]; ++j) {
        if (0==strcmp(shname[j], basename)) {
            o_shname += 3;  // space for "-c\x00"
            return super::canPack();
        }
    }
    return false;
}


bool PackLinuxI386sh::canPack()
{
#if defined(__linux__)  //{
    // only compress i386sh scripts when running under Linux
    char buf[512];

    fi->readx(buf, 512);
    fi->seek(0, SEEK_SET);
    buf[511] = 0;
    if (!memcmp(buf, "#!/", 3)) {                       // #!/bin/sh
        o_shname = 2;
        return getShellName(&buf[o_shname]);
    }
    else if (!memcmp(buf, "#! /", 4)) {                 // #! /bin/sh
        o_shname = 3;
        return getShellName(&buf[o_shname]);
    }
#endif  //}
    return false;
}


void PackLinuxI386sh::pack(OutputFile *fo)
{
#define PAGE_MASK (~0<<12)
    opt->unix.blocksize = blocksize = file_size;
    PackUnix::pack(fo);

    // update loader
    Elf_LE32_Phdr *const phdro = (Elf_LE32_Phdr *)(sizeof(Elf_LE32_Ehdr)+loader);
    off_t const totlen = fo->getBytesWritten();
    phdro[0].p_filesz = totlen;
    phdro[0].p_memsz = PAGE_MASK & (~PAGE_MASK + totlen);

    // Try to make brk() work by faking it for exec().
    unsigned const brka = 0x08048000;
    phdro[1].p_offset = 0xfff&brka;
    phdro[1].p_vaddr = brka;
    phdro[1].p_paddr = brka;
    phdro[1].p_filesz = 0;
    phdro[1].p_memsz =  0;

    patchLoaderChecksum();
    fo->seek(0, SEEK_SET);
    fo->rewrite(loader, 0x80);
#undef PAGE_MASK
}


/*
vi:ts=4:et
*/


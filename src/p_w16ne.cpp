/* p_w16ne.cpp --

   This file is part of the UPX executable compressor.

   Copyright (C) 1996-2001 Markus Franz Xaver Johannes Oberhumer
   Copyright (C) 1996-2001 Laszlo Molnar
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
#include "filter.h"
#include "packer.h"
#include "p_w16ne.h"


/*************************************************************************
//
**************************************************************************/

PackW16Ne::PackW16Ne(InputFile *f) :
    super(f)
{
}


const int *PackW16Ne::getCompressionMethods(int method, int level) const
{
    static const int m_nrv2b[] = { M_NRV2B_8, M_NRV2D_8, -1 };
    static const int m_nrv2d[] = { M_NRV2D_8, M_NRV2B_8, -1 };

    if (M_IS_NRV2B(method))
        return m_nrv2b;
    if (M_IS_NRV2D(method))
        return m_nrv2d;
    if (level == 1)
        return m_nrv2b;
    return m_nrv2d;
}


const int *PackW16Ne::getFilters() const
{
    return NULL;
}


int PackW16Ne::buildLoader(const Filter *ft)
{
    // prepare loader
//    initLoader(nrv_loader,sizeof(nrv_loader));
//    addLoader("...");
    if (ft->id)
    {
        assert(ft->calls > 0);
//        addLoader("...");
    }
//
    return getLoaderSize();
}


/*************************************************************************
//
**************************************************************************/

int PackW16Ne::readFileHeader()
{
    // FIXME: identify a win16/ne executable, so that the call
    // for contribution below will get thrown
    return 0;
    //return UPX_F_WIN16_NE;
}


bool PackW16Ne::canPack()
{
    if (!readFileHeader())
        return false;
    throwCantPack("win16/ne is not supported yet; your contribution is welcome");
    return false;
}


/*************************************************************************
//
**************************************************************************/

void PackW16Ne::pack(OutputFile *)
{
    throwCantPack("not yet implemented");
}


/*************************************************************************
//
**************************************************************************/

int PackW16Ne::canUnpack()
{
    if (!readFileHeader())
        return false;
    return false;
}


/*************************************************************************
//
**************************************************************************/

void PackW16Ne::unpack(OutputFile *)
{
    throwCantUnpack("not yet implemented");
}


/*
vi:ts=4:et
*/


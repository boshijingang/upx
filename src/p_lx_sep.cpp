/* p_lx_sep.cpp --

   This file is part of the UPX executable compressor.

   Copyright (C) 1996-2000 Markus Franz Xaver Johannes Oberhumer
   Copyright (C) 1996-2000 Laszlo Molnar
   Copyright (C) 2000 John F. Reiser
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
#include "p_lx_elf.h"
#include "p_lx_sep.h"


/*************************************************************************
//
**************************************************************************/

#define SCRIPT_SIZE     (opt->unix.SCRIPT_MAX + sizeof(l_info))

const upx_byte *PackLinuxI386sep::getLoader() const
{
    static char script[SCRIPT_SIZE];

    memset(script, 0, sizeof(script));
    char const *name = opt->unix.script_name;
    if (0==name) {
        name = "/usr/local/lib/upxX";
    }
    sprintf(script, "#!%s\n", name);
    if (M_IS_NRV2B(opt->method)) {
        script[strlen(script)-2] = 'b';
        return (upx_byte const *)script;
    }
    if (M_IS_NRV2D(opt->method)) {
        script[strlen(script)-2] = 'd';
        return (upx_byte const *)script;
    }
    return NULL;
}

int PackLinuxI386sep::getLoaderSize() const
{
    if (M_IS_NRV2B(opt->method))
        return SCRIPT_SIZE;
    if (M_IS_NRV2D(opt->method))
        return SCRIPT_SIZE;
    return 0;
}

int PackLinuxI386sep::getLoaderPrefixSize() const
{
    return opt->unix.SCRIPT_MAX;
}

void PackLinuxI386sep::patchLoader()
{
    patchLoaderChecksum();
}

/*
vi:ts=4:et
*/


/*
;  l_tmt.asm -- loader & decompressor for the tmt/adam format
;
;  This file is part of the UPX executable compressor.
;
;  Copyright (C) 1996-2006 Markus Franz Xaver Johannes Oberhumer
;  Copyright (C) 1996-2006 Laszlo Molnar
;  All Rights Reserved.
;
;  UPX and the UCL library are free software; you can redistribute them
;  and/or modify them under the terms of the GNU General Public License as
;  published by the Free Software Foundation; either version 2 of
;  the License, or (at your option) any later version.
;
;  This program is distributed in the hope that it will be useful,
;  but WITHOUT ANY WARRANTY; without even the implied warranty of
;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;  GNU General Public License for more details.
;
;  You should have received a copy of the GNU General Public License
;  along with this program; see the file COPYING.
;  If not, write to the Free Software Foundation, Inc.,
;  59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
;
;  Markus F.X.J. Oberhumer              Laszlo Molnar
;  <mfx@users.sourceforge.net>          <ml1050@users.sourceforge.net>
;
*/

#include        "arch/i386/macros2.ash"

                CPU     386

// =============
// ============= ENTRY POINT
// =============

start:
section         TMTMAIN1
                mov     edi, 0          // relocated
                push    edi
                lea     esi, [edi + copy_source]
                lea     edi, [edi + copy_dest]
                mov     ecx, offset bytes_to_copy

                std
                rep
                movsb
                cld

                lea     esi, [edi + 1]
                pop     edi
                or      ebp, -1
                push    edi
section         TMTCALT1
                push    edi
section         TMTMAIN2
                jmp     decompressor

#include        "include/header2.ash"

section TMTCUTPO
decompressor:

// =============
// ============= DECOMPRESSION
// =============

//#include      "arch/i386/nrv2b_d32.ash"
//#include      "arch/i386/nrv2d_d32.ash"
#include        "arch/i386/nrv2e_d32_2.ash"
//#include      "arch/i386/lzma_d.ash"

section         TMTMAIN5
                pop     ebp
                mov     esi, edi
                sub     esi, [edi - 4]

// =============
// ============= CALLTRICK
// =============

section         TMTCALT2
                pop     edi
                cjt32   ebp

// =============
// ============= RELOCATION
// =============

section         TMTRELOC
                lea     edi, [ebp - 4]
                reloc32 esi, edi, ebp

section         TMTJUMP1
                jmp     original_entry

// vi:ts=8:et:nowrap

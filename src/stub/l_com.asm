;  l_com.asm -- loader & decompressor for the dos/com format
;
;  This file is part of the UPX executable compressor.
;
;  Copyright (C) 1996-2000 Markus Franz Xaver Johannes Oberhumer
;  Copyright (C) 1996-2000 Laszlo Molnar
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
;  Markus F.X.J. Oberhumer                   Laszlo Molnar
;  markus.oberhumer@jk.uni-linz.ac.at        ml1050@cdata.tvnet.hu
;


%define         COM     1
%define         CJT16   1
%define         jmps    jmp short
%define         jmpl    jmp word
%include        "macros.ash"

                BITS    16
                ORG     0
                SECTION .text

; =============
; ============= ENTRY POINT
; =============

;       __COMMAIN1__
start:
                cmp     sp, 'SP'
                ja      mem_ok
                int     0x20
mem_ok:
                mov     cx, 'CX'        ; size of decomp + sizeof (data) + 1
                mov     si, 'SI'        ; cx + 0x100
                mov     di, 'DI'
                mov     bx, 0x8000

                std
                rep
                movsb
                cld

                xchg    si, di
                sub     si, byte start - cutpoint
;       __COMSUBSI__
                sbb     bp, bp
                push    di
%ifdef  __COMCALLT__
                push    di
%endif; __COMMAIN2__
                jmpl    .1+'JM'
.1:
%include        "header.ash"

cutpoint:
;       __COMCUTPO__


; =============
; ============= DECOMPRESSION
; =============

%include        "n2b_d16.ash"

; =============
; ============= CALLTRICK
; =============


; =============

;       __CORETURN__
                ret
eof:
;       __COMTHEND__
                section .data
                dd      -1
                dw      eof


; vi:ts=8:et:nowrap

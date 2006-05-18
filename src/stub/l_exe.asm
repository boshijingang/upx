;  l_exe.asm -- loader & decompressor for the dos/exe format
;
;  This file is part of the UPX executable compressor.
;
;  Copyright (C) 1996-2004 Markus Franz Xaver Johannes Oberhumer
;  Copyright (C) 1996-2004 Laszlo Molnar
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


%define         EXE
%define         jmps    jmp short
%define         jmpn    jmp near

                BITS    16
                ORG     0
                SECTION .text
                CPU     8086

;       __DEVICEENTRY__

                dd      -1
                dw      0
                dw      strategy        ; .sys header
                dw      0               ; opendos wants this field untouched
original_strategy:
                dw      'ST'
strategy:
                push    cs
                push    word [cs:original_strategy]
                push    ax
                push    bx
                push    cx
                push    dx
                mov     ax, cs
                add     ax, 'OS'        ; calculate normal EXE stack
                mov     bx, 'OP'
                mov     cx, ss
                mov     dx, sp
                mov     ss, ax          ; switch to stack EXE normally has
                mov     sp, bx
                push    cx              ; save device stack on EXE stack
                push    dx
                push    si
                push    di
                push    bp
                push    ds
                push    es
                db      0x72            ; "jc 0xf9" but flag C is 0 => nop
exe_as_device_entry:
                stc                     ; flag C is 1
                pushf

; =============
; ============= ENTRY POINT
; =============
;       __EXEENTRY__
exe_entry:
                mov     cx, 'CX'        ; first_copy_len/2
                mov     si, 'SI'        ; cx*2-2
                mov     di, si
                push    ds
                db      0xa9
do_copy:
                mov     ch, 0x80        ; 64 kbyte
                mov     ax, cs
addaxds:
                add     ax, 'DS'        ; MSB is referenced by the "sub" below
                mov     ds, ax
                add     ax, 'ES'
                mov     es, ax

                std
                rep
                movsw
                cld
;       __DEVICESUB__
                sub     [byte cs:si + addaxds + 4], byte 0x10
;       __EXESUB__
                sub     [byte cs:si + addaxds - exe_entry + 4], byte 0x10
;       __JNCDOCOPY__
                jnc     do_copy
                xchg    ax, dx
                scasw
                lodsw
%ifdef  __EXERELPU__
                push    cs
%endif; __EXEMAIN4__
                push    cs
                push    cs
                push    es
                pop     ds
                pop     es
                push    ss
                mov     bp, 'BP'        ; entry point [0x1,0x10]
                mov     bx, 'BX'        ; 0x800F + 0x10*bp - 0x10
                push    bp
                retf

%include        "header.ash"

;       __EXECUTPO__

; =============
; ============= DECOMPRESSION
; =============

                CPU     286
%include        "n2b_d8e.ash"
%include        "n2d_d8e.ash"
%include        "n2e_d8e.ash"
                CPU     8086

; =============
; ============= RELOCATION
; =============
;       __EXEMAIN5__
                pop     bp
%ifdef  __EXERELOC__
%ifdef  __EXEADJUS__
                mov     ax, es
                sub     ah, 0x6        ; MAXRELOCS >> 12
                mov     ds, ax
%else;  __EXENOADJ__
                push    es
                pop     ds
%endif; __EXERELO1__
                lea     si, [di+'RS']
                lodsw

                pop     bx

                xchg    ax, cx          ; number of 0x01 bytes (not exactly)
                lodsw
                xchg    ax, dx          ; seg_hi
reloc_0:
                lodsw
                xchg    ax, di
                lodsw
                add     bx, ax
                mov     es, bx
                xor     ax, ax
reloc_1:
                add     di, ax
                add     [es:di], bp
reloc_2:
                lodsb
                dec     ax
                jz      reloc_5
                inc     ax
                jnz     reloc_1
%ifdef  __EXEREL9A__
                inc     di
reloc_4:
                inc     di
                cmp     byte [es:di], 0x9a
                jne     reloc_4
                cmp     [es:di+3], dx
                ja      reloc_4
                mov     al, 3
                jmps    reloc_1
%endif; __EXERELO2__
reloc_5:
                add     di, 0xfe
%ifdef  __EXEREBIG__
                jc      reloc_0
%endif; __EXERELO3__
                loop    reloc_2
%endif; __EXEMAIN8__

; =============

                pop     es
                push    es
                pop     ds

;       __DEVICEEND__
                popf
                jc      loaded_as_exe
                pop     es
                pop     ds
                pop     bp
                pop     di
                pop     si
                pop     bx              ; get original device SS:SP
                pop     ax
                mov     ss, ax          ; switch to device driver stack
                mov     sp, bx
                pop     dx
                pop     cx
                pop     bx
                pop     ax
                retf                    ; return to original strategy

loaded_as_exe:
%ifdef  __EXESTACK__
                lea     ax, ['SS'+bp]
                mov     ss, ax
%endif; __EXEDUMMS__
%ifdef  __EXESTASP__
                mov     sp, 'SP'
%endif; __EXEDUMMP__

; =============

%ifdef  __EXEJUMPF__
                jmp     'CS':'IP'
%else;  __EXERETUR__
%ifdef  __EXERCSPO__
                add     bp, 'CS'
%endif; __EXERETIP__
                push    bp
                mov     ax, 'IP'
                push    ax
                retf
%endif; __EXEDUMMZ__
eof:
;       __EXETHEND__
                section .data
                dd      -1
                dw      eof


; vi:ts=8:et:nowrap

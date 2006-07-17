/* powerpc-linux.elf-entry.h -- created from powerpc-linux.elf-entry.bin, 3279 (0xccf) bytes

   This file is part of the UPX executable compressor.

   Copyright (C) 1996-2006 Markus Franz Xaver Johannes Oberhumer
   Copyright (C) 1996-2006 Laszlo Molnar
   Copyright (C) 2000-2006 John F. Reiser
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

   Markus F.X.J. Oberhumer              Laszlo Molnar
   <mfx@users.sourceforge.net>          <ml1050@users.sourceforge.net>
 */


#define LINUX_ELFPPC32_LOADER_SIZE    3279
#define LINUX_ELFPPC32_LOADER_ADLER32 0x58e8917b
#define LINUX_ELFPPC32_LOADER_CRC32   0x99385f7d

unsigned char linux_elfppc32_loader[3279] = {
127, 69, 76, 70,  1,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,   /* 0x   0 */
  0,  1,  0, 20,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,   /* 0x  10 */
  0,  0,  3,172,  0,  0,  0,  0,  0, 52,  0,  0,  0,  0,  0, 40,   /* 0x  20 */
  0, 15,  0, 12, 72,  0,  0,125,124,  0, 41,236,125,168,  2,166,   /* 0x  30 */
 40,  7,  0,  8, 64,130,  1, 60,144,166,  0,  0,124,132, 26, 20,   /* 0x  40 */
 60,  0,128,  0, 61, 32,128,  0, 56, 99,255,255, 56,165,255,255,   /* 0x  50 */
 57, 64,255,255, 72,  0,  1, 12, 57, 32,  0,  1,125, 41, 28, 44,   /* 0x  60 */
 56, 99,  0,  4,124,  9,  0, 64,125, 41, 72, 20, 97, 41,  0,  1,   /* 0x  70 */
 78,128,  0, 32,141,  3,  0,  1,157,  5,  0,  1,124,  9,  0, 64,   /* 0x  80 */
125, 41, 74, 20, 65,162,255,213, 65,129,255,236, 56,224,  0,  1,   /* 0x  90 */
 72,  0,  0, 20, 56,231,255,255,125, 41, 72, 21, 65,162,255,189,   /* 0x  a0 */
124,231, 57, 20,125, 41, 72, 21, 65,162,255,177,124,231, 57, 20,   /* 0x  b0 */
124,  9,  0, 64,125, 41, 74, 20, 65,162,255,161, 65,160,255,216,   /* 0x  c0 */
 57,  0,  0,  0, 52,231,255,253, 84,231, 64, 46, 65,128,  0, 32,   /* 0x  d0 */
140, 67,  0,  1,124,234, 16,249,125, 74, 14,112, 65,130,  0,  0,   /* 0x  e0 */
112, 66,  0,  1, 65,162,  0, 80, 72,  0,  0, 20,124,  9,  0, 64,   /* 0x  f0 */
125, 41, 74, 20, 65,162,255,101, 65,161,  0, 60, 57,  0,  0,  1,   /* 0x 100 */
124,  9,  0, 64,125, 41, 74, 20, 65,162,255, 81, 65,161,  0, 40,   /* 0x 110 */
125, 41, 72, 21, 65,162,255, 69,125,  8, 65, 20,124,  9,  0, 64,   /* 0x 120 */
125, 41, 74, 20, 65,162,255, 53, 65,160,255,232, 57,  8,  0,  2,   /* 0x 130 */
 72,  0,  0, 16,125, 41, 72, 21, 65,162,255, 33,125,  8, 65, 20,   /* 0x 140 */
 32,234,250,255, 57,  8,  0,  2,125,  8,  1,148,124,234, 42, 20,   /* 0x 150 */
125,  9,  3,166,141,  7,  0,  1,157,  5,  0,  1, 66,  0,255,248,   /* 0x 160 */
 56,224,  1,  0,124,  7, 41,236,124,  7, 26, 44, 75,255,255, 16,   /* 0x 170 */
124,  0, 41,236,125,168,  2,166, 40,  7,  0,  2, 64,130,  0,228,   /* 0x 180 */
144,166,  0,  0,124,132, 26, 20, 60,  0,128,  0, 61, 32,128,  0,   /* 0x 190 */
 56, 99,255,255, 56,165,255,255, 57, 64,255,255, 72,  0,  0,180,   /* 0x 1a0 */
124,  9,  0, 64,125, 41, 72, 20, 76,162,  0, 32, 57, 32,  0,  1,   /* 0x 1b0 */
125, 41, 28, 44, 56, 99,  0,  4,124,  9,  0, 64,125, 41, 73, 20,   /* 0x 1c0 */
 78,128,  0, 32,141,  3,  0,  1,157,  5,  0,  1, 75,255,255,213,   /* 0x 1d0 */
 65,129,255,244, 56,224,  0,  1, 75,255,255,201,124,231, 57, 21,   /* 0x 1e0 */
 75,255,255,193, 65,160,255,244, 52,231,255,253, 57,  0,  0,  0,   /* 0x 1f0 */
 65,128,  0, 20,140, 67,  0,  1, 84,231, 64, 46,124,234, 16,249,   /* 0x 200 */
 65,130,  0,  0, 75,255,255,157,125,  8, 65, 21, 75,255,255,149,   /* 0x 210 */
125,  8, 65, 21, 56,224,  0,  1, 64,130,  0, 28, 56,224,  0,  3,   /* 0x 220 */
 57,  0,  0,  1, 75,255,255,125,125,  8, 65, 21, 75,255,255,117,   /* 0x 230 */
 65,160,255,244, 32, 74,242,255,125,  8, 57, 20,124,234, 42, 20,   /* 0x 240 */
125,  9,  3,166,141,  7,  0,  1,157,  5,  0,  1, 66,  0,255,248,   /* 0x 250 */
 56,224,  1,  0,124,  7, 41,236,124,  7, 26, 44, 75,255,255,112,   /* 0x 260 */
128,  6,  0,  0,125,168,  3,166, 56,165,  0,  1, 56, 99,  0,  1,   /* 0x 270 */
124,160, 40, 80,124,100, 24, 80,144,166,  0,  0, 78,128,  0, 32,   /* 0x 280 */
 72,  0,  0,  1, 80, 82, 79, 84, 95, 69, 88, 69, 67,124, 80, 82,   /* 0x 290 */
 79, 84, 95, 87, 82, 73, 84, 69, 32,102, 97,105,108,101,100, 46,   /* 0x 2a0 */
 10,  0,  0,  0, 56,160,  0, 30,124,136,  2,166, 56, 96,  0,  2,   /* 0x 2b0 */
 56,  0,  0,  4, 68,  0,  0,  2, 56, 96,  0,127, 56,  0,  0,  1,   /* 0x 2c0 */
 68,  0,  0,  2,127,200,  2,166, 57,  0,  0,  0, 56,224,255,255,   /* 0x 2d0 */
128,126,  0,  4, 56,192,  0, 50, 56,160,  0,  7, 56,128, 16,  0,   /* 0x 2e0 */
124, 99,242, 20, 56,  0,  0, 90, 56, 99, 16, 11, 84, 99,  0, 38,   /* 0x 2f0 */
 68,  0,  0,  2, 65,131,  0, 32,127,233,  3,166,128, 30,  0,  0,   /* 0x 300 */
136,254,  0,  8, 56,193,  0,124,144,  1,  0,124,124,101, 27,120,   /* 0x 310 */
124,104,  3,166,128,158,  0,  4, 56,126,  0, 12, 78,128,  4, 32,   /* 0x 320 */
124,128,  0,  8,148, 33,255,128,188, 65,  0,  4,127,232,  2,166,   /* 0x 330 */
 75,255,255,149,  0, 46,115,121,109,116, 97, 98,  0, 46,115,116,   /* 0x 340 */
114,116, 97, 98,  0, 46,115,104,115,116,114,116, 97, 98,  0, 46,   /* 0x 350 */
114,101,108, 97, 69, 76, 70, 77, 65, 73, 78, 88,  0, 78, 82, 86,   /* 0x 360 */
 95, 67, 79, 77, 77, 79, 78,  0, 46,114,101,108, 97, 78, 82, 86,   /* 0x 370 */
 50, 69,  0, 46,114,101,108, 97, 78, 82, 86, 50, 66,  0, 46,114,   /* 0x 380 */
101,108, 97, 69, 76, 70, 77, 65, 73, 78, 89,  0, 46,114,101,108,   /* 0x 390 */
 97, 69, 76, 70, 77, 65, 73, 78, 90,  0,  0,  0,  0,  0,  0,  0,   /* 0x 3a0 */
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,   /* 0x 3b0 */
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,   /* 0x 3c0 */
  0,  0,  0,  0,  0,  0,  0, 32,  0,  0,  0,  1,  0,  0,  0,  0,   /* 0x 3d0 */
  0,  0,  0,  0,  0,  0,  0, 52,  0,  0,  0,  4,  0,  0,  0,  0,   /* 0x 3e0 */
  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0, 27,   /* 0x 3f0 */
  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,140,   /* 0x 400 */
  0,  0,  0, 12,  0,  0,  0, 13,  0,  0,  0,  1,  0,  0,  0,  4,   /* 0x 410 */
  0,  0,  0, 12,  0,  0,  0, 41,  0,  0,  0,  1,  0,  0,  0,  0,   /* 0x 420 */
  0,  0,  0,  0,  0,  0,  0, 56,  0,  0,  0,  0,  0,  0,  0,  0,   /* 0x 430 */
  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0, 57,   /* 0x 440 */
  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 56,   /* 0x 450 */
  0,  0,  1, 72,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,   /* 0x 460 */
  0,  0,  0,  0,  0,  0,  0, 52,  0,  0,  0,  4,  0,  0,  0,  0,   /* 0x 470 */
  0,  0,  0,  0,  0,  0,  6,152,  0,  0,  0, 12,  0,  0,  0, 13,   /* 0x 480 */
  0,  0,  0,  4,  0,  0,  0,  4,  0,  0,  0, 12,  0,  0,  0, 68,   /* 0x 490 */
  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,128,   /* 0x 4a0 */
  0,  0,  0,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,   /* 0x 4b0 */
  0,  0,  0,  0,  0,  0,  0, 63,  0,  0,  0,  4,  0,  0,  0,  0,   /* 0x 4c0 */
  0,  0,  0,  0,  0,  0,  6,164,  0,  0,  0, 12,  0,  0,  0, 13,   /* 0x 4d0 */
  0,  0,  0,  6,  0,  0,  0,  4,  0,  0,  0, 12,  0,  0,  0, 79,   /* 0x 4e0 */
  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,112,   /* 0x 4f0 */
  0,  0,  0, 68,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,   /* 0x 500 */
  0,  0,  0,  0,  0,  0,  0, 74,  0,  0,  0,  4,  0,  0,  0,  0,   /* 0x 510 */
  0,  0,  0,  0,  0,  0,  6,176,  0,  0,  0, 12,  0,  0,  0, 13,   /* 0x 520 */
  0,  0,  0,  8,  0,  0,  0,  4,  0,  0,  0, 12,  0,  0,  0, 93,   /* 0x 530 */
  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,180,   /* 0x 540 */
  0,  0,  0,144,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,   /* 0x 550 */
  0,  0,  0,  0,  0,  0,  0, 88,  0,  0,  0,  4,  0,  0,  0,  0,   /* 0x 560 */
  0,  0,  0,  0,  0,  0,  6,188,  0,  0,  0, 12,  0,  0,  0, 13,   /* 0x 570 */
  0,  0,  0, 10,  0,  0,  0,  4,  0,  0,  0, 12,  0,  0,  0, 17,   /* 0x 580 */
  0,  0,  0,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3, 68,   /* 0x 590 */
  0,  0,  0,102,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,   /* 0x 5a0 */
  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  2,  0,  0,  0,  0,   /* 0x 5b0 */
  0,  0,  0,  0,  0,  0,  6,  4,  0,  0,  0,128,  0,  0,  0, 14,   /* 0x 5c0 */
  0,  0,  0,  7,  0,  0,  0,  4,  0,  0,  0, 16,  0,  0,  0,  9,   /* 0x 5d0 */
  0,  0,  0,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,132,   /* 0x 5e0 */
  0,  0,  0,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,   /* 0x 5f0 */
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,   /* 0x 600 */
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,   /* 0x 610 */
  3,  0,  0,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,   /* 0x 620 */
  3,  0,  0, 10,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,   /* 0x 630 */
  3,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,   /* 0x 640 */
  3,  0,  0,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,   /* 0x 650 */
  3,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,   /* 0x 660 */
  3,  0,  0,  6,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,   /* 0x 670 */
 16,  0,  0,  1,  0, 95,115,116, 97,114,116,  0,  0,  0,  0,  0,   /* 0x 680 */
  0,  0,  2, 10,  0,  0,  0,124,  0,  0,  0,180,  0,  0,  1, 11,   /* 0x 690 */
  0,  0,  0,  0,  0,  0,  0,144,  0,  0,  1, 11,  0,  0,  0,  0,   /* 0x 6a0 */
  0,  0,  0, 32,  0,  0,  2, 10,  0,  0,  0,  0,  0,  0,  0, 80,   /* 0x 6b0 */
  0,  0,  1, 11,  0,  0,  0, 32, 10,116,109,112, 47,112,111,119,   /* 0x 6c0 */
101,114,112, 99, 45,108,105,110,117,120, 46,101,108,102, 45,101,   /* 0x 6d0 */
110,116,114,121, 46, 98,105,110, 58, 32, 32, 32, 32, 32,102,105,   /* 0x 6e0 */
108,101, 32,102,111,114,109, 97,116, 32,101,108,102, 51, 50, 45,   /* 0x 6f0 */
112,111,119,101,114,112, 99, 10, 10, 83,101, 99,116,105,111,110,   /* 0x 700 */
115, 58, 10, 73,100,120, 32, 78, 97,109,101, 32, 32, 32, 32, 32,   /* 0x 710 */
 32, 32, 32, 32, 32, 83,105,122,101, 32, 32, 32, 32, 32, 32, 86,   /* 0x 720 */
 77, 65, 32, 32, 32, 32, 32, 32, 32, 76, 77, 65, 32, 32, 32, 32,   /* 0x 730 */
 32, 32, 32, 70,105,108,101, 32,111,102,102, 32, 32, 65,108,103,   /* 0x 740 */
110, 32, 32, 70,108, 97,103,115, 10, 32, 32, 48, 32, 69, 76, 70,   /* 0x 750 */
 77, 65, 73, 78, 88, 32, 32, 32, 32, 32, 32, 48, 48, 48, 48, 48,   /* 0x 760 */
 48, 48, 52, 32, 32, 48, 48, 48, 48, 48, 48, 48, 48, 32, 32, 48,   /* 0x 770 */
 48, 48, 48, 48, 48, 48, 48, 32, 32, 48, 48, 48, 48, 48, 48, 51,   /* 0x 780 */
 52, 32, 32, 50, 42, 42, 50, 32, 32, 67, 79, 78, 84, 69, 78, 84,   /* 0x 790 */
 83, 44, 32, 82, 69, 76, 79, 67, 44, 32, 82, 69, 65, 68, 79, 78,   /* 0x 7a0 */
 76, 89, 10, 32, 32, 49, 32, 78, 82, 86, 95, 67, 79, 77, 77, 79,   /* 0x 7b0 */
 78, 32, 32, 32, 32, 48, 48, 48, 48, 48, 48, 48, 48, 32, 32, 48,   /* 0x 7c0 */
 48, 48, 48, 48, 48, 48, 48, 32, 32, 48, 48, 48, 48, 48, 48, 48,   /* 0x 7d0 */
 48, 32, 32, 48, 48, 48, 48, 48, 48, 51, 56, 32, 32, 50, 42, 42,   /* 0x 7e0 */
 50, 32, 32, 67, 79, 78, 84, 69, 78, 84, 83, 44, 32, 82, 69, 65,   /* 0x 7f0 */
 68, 79, 78, 76, 89, 10, 32, 32, 50, 32, 78, 82, 86, 50, 69, 32,   /* 0x 800 */
 32, 32, 32, 32, 32, 32, 32, 32, 48, 48, 48, 48, 48, 49, 52, 56,   /* 0x 810 */
 32, 32, 48, 48, 48, 48, 48, 48, 48, 48, 32, 32, 48, 48, 48, 48,   /* 0x 820 */
 48, 48, 48, 48, 32, 32, 48, 48, 48, 48, 48, 48, 51, 56, 32, 32,   /* 0x 830 */
 50, 42, 42, 50, 32, 32, 67, 79, 78, 84, 69, 78, 84, 83, 44, 32,   /* 0x 840 */
 82, 69, 76, 79, 67, 44, 32, 82, 69, 65, 68, 79, 78, 76, 89, 10,   /* 0x 850 */
 32, 32, 51, 32, 78, 82, 86, 50, 66, 32, 32, 32, 32, 32, 32, 32,   /* 0x 860 */
 32, 32, 48, 48, 48, 48, 48, 48,102, 48, 32, 32, 48, 48, 48, 48,   /* 0x 870 */
 48, 48, 48, 48, 32, 32, 48, 48, 48, 48, 48, 48, 48, 48, 32, 32,   /* 0x 880 */
 48, 48, 48, 48, 48, 49, 56, 48, 32, 32, 50, 42, 42, 50, 32, 32,   /* 0x 890 */
 67, 79, 78, 84, 69, 78, 84, 83, 44, 32, 82, 69, 76, 79, 67, 44,   /* 0x 8a0 */
 32, 82, 69, 65, 68, 79, 78, 76, 89, 10, 32, 32, 52, 32, 69, 76,   /* 0x 8b0 */
 70, 77, 65, 73, 78, 89, 32, 32, 32, 32, 32, 32, 48, 48, 48, 48,   /* 0x 8c0 */
 48, 48, 52, 52, 32, 32, 48, 48, 48, 48, 48, 48, 48, 48, 32, 32,   /* 0x 8d0 */
 48, 48, 48, 48, 48, 48, 48, 48, 32, 32, 48, 48, 48, 48, 48, 50,   /* 0x 8e0 */
 55, 48, 32, 32, 50, 42, 42, 50, 32, 32, 67, 79, 78, 84, 69, 78,   /* 0x 8f0 */
 84, 83, 44, 32, 82, 69, 76, 79, 67, 44, 32, 82, 69, 65, 68, 79,   /* 0x 900 */
 78, 76, 89, 10, 32, 32, 53, 32, 69, 76, 70, 77, 65, 73, 78, 90,   /* 0x 910 */
 32, 32, 32, 32, 32, 32, 48, 48, 48, 48, 48, 48, 57, 48, 32, 32,   /* 0x 920 */
 48, 48, 48, 48, 48, 48, 48, 48, 32, 32, 48, 48, 48, 48, 48, 48,   /* 0x 930 */
 48, 48, 32, 32, 48, 48, 48, 48, 48, 50, 98, 52, 32, 32, 50, 42,   /* 0x 940 */
 42, 50, 32, 32, 67, 79, 78, 84, 69, 78, 84, 83, 44, 32, 82, 69,   /* 0x 950 */
 76, 79, 67, 44, 32, 82, 69, 65, 68, 79, 78, 76, 89, 10, 83, 89,   /* 0x 960 */
 77, 66, 79, 76, 32, 84, 65, 66, 76, 69, 58, 10, 48, 48, 48, 48,   /* 0x 970 */
 48, 48, 48, 48, 32,108, 32, 32, 32, 32,100, 32, 32, 69, 76, 70,   /* 0x 980 */
 77, 65, 73, 78, 89,  9, 48, 48, 48, 48, 48, 48, 48, 48, 32, 69,   /* 0x 990 */
 76, 70, 77, 65, 73, 78, 89, 10, 48, 48, 48, 48, 48, 48, 48, 48,   /* 0x 9a0 */
 32,108, 32, 32, 32, 32,100, 32, 32, 69, 76, 70, 77, 65, 73, 78,   /* 0x 9b0 */
 90,  9, 48, 48, 48, 48, 48, 48, 48, 48, 32, 69, 76, 70, 77, 65,   /* 0x 9c0 */
 73, 78, 90, 10, 48, 48, 48, 48, 48, 48, 48, 48, 32,108, 32, 32,   /* 0x 9d0 */
 32, 32,100, 32, 32, 69, 76, 70, 77, 65, 73, 78, 88,  9, 48, 48,   /* 0x 9e0 */
 48, 48, 48, 48, 48, 48, 32, 69, 76, 70, 77, 65, 73, 78, 88, 10,   /* 0x 9f0 */
 48, 48, 48, 48, 48, 48, 48, 48, 32,108, 32, 32, 32, 32,100, 32,   /* 0x a00 */
 32, 78, 82, 86, 95, 67, 79, 77, 77, 79, 78,  9, 48, 48, 48, 48,   /* 0x a10 */
 48, 48, 48, 48, 32, 78, 82, 86, 95, 67, 79, 77, 77, 79, 78, 10,   /* 0x a20 */
 48, 48, 48, 48, 48, 48, 48, 48, 32,108, 32, 32, 32, 32,100, 32,   /* 0x a30 */
 32, 78, 82, 86, 50, 69,  9, 48, 48, 48, 48, 48, 48, 48, 48, 32,   /* 0x a40 */
 78, 82, 86, 50, 69, 10, 48, 48, 48, 48, 48, 48, 48, 48, 32,108,   /* 0x a50 */
 32, 32, 32, 32,100, 32, 32, 78, 82, 86, 50, 66,  9, 48, 48, 48,   /* 0x a60 */
 48, 48, 48, 48, 48, 32, 78, 82, 86, 50, 66, 10, 48, 48, 48, 48,   /* 0x a70 */
 48, 48, 48, 48, 32,103, 32, 32, 32, 32, 32, 32, 32, 69, 76, 70,   /* 0x a80 */
 77, 65, 73, 78, 88,  9, 48, 48, 48, 48, 48, 48, 48, 48, 32, 95,   /* 0x a90 */
115,116, 97,114,116, 10, 10, 10, 82, 69, 76, 79, 67, 65, 84, 73,   /* 0x aa0 */
 79, 78, 32, 82, 69, 67, 79, 82, 68, 83, 32, 70, 79, 82, 32, 91,   /* 0x ab0 */
 69, 76, 70, 77, 65, 73, 78, 88, 93, 58, 10, 79, 70, 70, 83, 69,   /* 0x ac0 */
 84, 32, 32, 32, 84, 89, 80, 69, 32, 32, 32, 32, 32, 32, 32, 32,   /* 0x ad0 */
 32, 32, 32, 32, 32, 32, 86, 65, 76, 85, 69, 32, 10, 48, 48, 48,   /* 0x ae0 */
 48, 48, 48, 48, 48, 32, 82, 95, 80, 80, 67, 95, 82, 69, 76, 50,   /* 0x af0 */
 52, 32, 32, 32, 32, 32, 32, 32, 69, 76, 70, 77, 65, 73, 78, 90,   /* 0x b00 */
 43, 48,120, 48, 48, 48, 48, 48, 48, 55, 99, 10, 10, 10, 82, 69,   /* 0x b10 */
 76, 79, 67, 65, 84, 73, 79, 78, 32, 82, 69, 67, 79, 82, 68, 83,   /* 0x b20 */
 32, 70, 79, 82, 32, 91, 78, 82, 86, 50, 69, 93, 58, 10, 79, 70,   /* 0x b30 */
 70, 83, 69, 84, 32, 32, 32, 84, 89, 80, 69, 32, 32, 32, 32, 32,   /* 0x b40 */
 32, 32, 32, 32, 32, 32, 32, 32, 32, 86, 65, 76, 85, 69, 32, 10,   /* 0x b50 */
 48, 48, 48, 48, 48, 48, 98, 52, 32, 82, 95, 80, 80, 67, 95, 82,   /* 0x b60 */
 69, 76, 49, 52, 32, 32, 32, 32, 32, 32, 32, 69, 76, 70, 77, 65,   /* 0x b70 */
 73, 78, 89, 10, 10, 10, 82, 69, 76, 79, 67, 65, 84, 73, 79, 78,   /* 0x b80 */
 32, 82, 69, 67, 79, 82, 68, 83, 32, 70, 79, 82, 32, 91, 78, 82,   /* 0x b90 */
 86, 50, 66, 93, 58, 10, 79, 70, 70, 83, 69, 84, 32, 32, 32, 84,   /* 0x ba0 */
 89, 80, 69, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,   /* 0x bb0 */
 32, 86, 65, 76, 85, 69, 32, 10, 48, 48, 48, 48, 48, 48, 57, 48,   /* 0x bc0 */
 32, 82, 95, 80, 80, 67, 95, 82, 69, 76, 49, 52, 32, 32, 32, 32,   /* 0x bd0 */
 32, 32, 32, 69, 76, 70, 77, 65, 73, 78, 89, 10, 10, 10, 82, 69,   /* 0x be0 */
 76, 79, 67, 65, 84, 73, 79, 78, 32, 82, 69, 67, 79, 82, 68, 83,   /* 0x bf0 */
 32, 70, 79, 82, 32, 91, 69, 76, 70, 77, 65, 73, 78, 89, 93, 58,   /* 0x c00 */
 10, 79, 70, 70, 83, 69, 84, 32, 32, 32, 84, 89, 80, 69, 32, 32,   /* 0x c10 */
 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 86, 65, 76, 85,   /* 0x c20 */
 69, 32, 10, 48, 48, 48, 48, 48, 48, 50, 48, 32, 82, 95, 80, 80,   /* 0x c30 */
 67, 95, 82, 69, 76, 50, 52, 32, 32, 32, 32, 32, 32, 32, 69, 76,   /* 0x c40 */
 70, 77, 65, 73, 78, 90, 10, 10, 10, 82, 69, 76, 79, 67, 65, 84,   /* 0x c50 */
 73, 79, 78, 32, 82, 69, 67, 79, 82, 68, 83, 32, 70, 79, 82, 32,   /* 0x c60 */
 91, 69, 76, 70, 77, 65, 73, 78, 90, 93, 58, 10, 79, 70, 70, 83,   /* 0x c70 */
 69, 84, 32, 32, 32, 84, 89, 80, 69, 32, 32, 32, 32, 32, 32, 32,   /* 0x c80 */
 32, 32, 32, 32, 32, 32, 32, 86, 65, 76, 85, 69, 32, 10, 48, 48,   /* 0x c90 */
 48, 48, 48, 48, 53, 48, 32, 82, 95, 80, 80, 67, 95, 82, 69, 76,   /* 0x ca0 */
 49, 52, 32, 32, 32, 32, 32, 32, 32, 69, 76, 70, 77, 65, 73, 78,   /* 0x cb0 */
 89, 43, 48,120, 48, 48, 48, 48, 48, 48, 50, 48, 10, 10, 10        /* 0x cc0 */
};

/*
 * Copyright (c) 2015 MediaTek Inc.
 * Author: Qing Li <qing.li@mediatek.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "di_table.h"

UINT32 MA_MOTION_LEVEL_THR[MA_MAX_RES][MAX_MOTION_LEVEL] = {
// zero
  {1000, 10000,  20000,  80000, 172800  },
// 320x240
  {1000, 10000,  20000,  80000, 172800  },
// 720x480
  {1000, 10000,  20000,  80000, 172800  },
// 720x576
  {1200,  12000,  24000,  96000, 207360  },
// 1280x720
  {2666, 53333,  80000, 106666, 460800  },
// 1920x1080
  {6000, 72000, 180000, 240000, 1036800}
};


const MA_THRESHOLD_T MA_THRESHOLDS[MA_MAX_RES][MAX_MOTION_LEVEL] = {
  { // zero
   {100000,  64000,       36000, 22,      3, 18, 0x2A, 0x2A, 0x32, 6, 0x0C, 0x1C, 0x1C, 0x64,         0x04, 0x51,0x32, 4, 54, 50, 0,  54,  6},
   {100000, 64000,  40000,  6,  3, 18, 0x2A, 0x2A, 0x32, 0x4, 0xc, 0x1C, 0x1C, 0x64,    0x04, 0x51,0x32, 4, 54, 50 , 1,  54,  6},
   {100000, 64000,  40000,  6,  3, 18, 0x2A, 0x2A, 0x32, 0x2, 0xc, 0x1C, 0x1C, 0x64,    0x04, 0x51,0x32, 4, 54, 40, 1,  54,  6},
   {100000, 64000,  40000,  6,  3, 18, 0x2A, 0x2A, 0x32, 0x2, 0xc, 0x1C, 0x1C, 0x64,    0x04, 0x51,0x32, 4, 54, 30, 1,  54,  6},
   {100000, 64000,  40000,  6,  3, 18, 0x2A, 0x2A, 0x32, 0x2, 0xc, 0x1C, 0x1C, 0x64,    0x04, 0x51,0x32, 4, 54, 10, 1,  54,  6}

  },
  { // 320x240
   {100000,  64000,       36000, 22,      3, 18, 0x2A, 0x2A, 0x32, 6, 0x0C, 0x1C, 0x1C, 0x64,         0x04, 0x51,0x32, 4, 54, 50, 0,  54,  6},
   {100000, 64000,  40000,  6,  3, 18, 0x2A, 0x2A, 0x32, 0x4, 0xc, 0x1C, 0x1C, 0x64,    0x04, 0x51,0x32, 4, 54, 50 , 1,  54,  6},
   {100000, 64000,  40000,  6,  3, 18, 0x2A, 0x2A, 0x32, 0x2, 0xc, 0x1C, 0x1C, 0x64,    0x04, 0x51,0x32, 4, 54, 40, 1,  54,  6},
   {100000, 64000,  40000,  6,  3, 18, 0x2A, 0x2A, 0x32, 0x2, 0xc, 0x1C, 0x1C, 0x64,    0x04, 0x51,0x32, 4, 54, 30, 1,  54,  6},
   {100000, 64000,  40000,  6,  3, 18, 0x2A, 0x2A, 0x32, 0x2, 0xc, 0x1C, 0x1C, 0x64,    0x04, 0x51,0x32, 4, 54, 10, 1,  54,  6}
  },
  { // 720x480
   {100000,  64000,       36000, 22,      3, 18, 0x2A, 0x2A, 0x32, 6, 0x0C, 0x1C, 0x1C, 0x64,         0x04, 0x51,0x32, 4, 54, 50, 0,  54,  6},
   {100000,  64000,     28000,  10, 4, 18,  34,    34,    50,      6, 12, 28,          28, 100,             4, 81,        50, 4, 54, 50, 1,  54,  6},
   { 30000,  16000,   8000,  2, 1,  3, 10, 14, 50, 1,  3, 11, 10, 100,  3, 17, 50,  2, 17, 50, 1,  54,  6},
   { 30000,  16000,   8000,  2, 1,  3, 10, 14, 50, 1,  3, 11, 10, 100,  3, 17, 50,  2, 17, 50, 1,  54,  6},
   { 30000,  16000,   8000,  2, 1,  3, 10, 14, 50, 1,  3, 11, 10, 100,  3, 17, 50,  2, 17, 50, 1,  54,  6}
  },
  { // 720x576
   {120000, 72000,  40000,  22, 3, 18, 0x2A, 0x2A, 0x32, 0x6, 0xc, 0x1C, 0x1C, 0x64,   0x04, 0x51,0x32,  4, 54, 50, 0,  54,  6},
   {120000,  72000,     30800,  10, 4, 18,  34,    34,    50,      6, 12, 28,          28, 100,             4, 81,        50, 4, 54, 50, 1,  54,  6},
   //{120000, 72000,    44000,  6,  3, 18, 0x2A, 0x2A, 0x32, 0x4, 0xc, 0x1C, 0x1C, 0x64,   0x04, 0x51,0x32,  4, 54, 50, 1,  54,  6},
   { 30000,  16000,   8000,  2, 1,  3, 10, 14, 50, 1,  3, 11, 10, 100,  3, 17, 50,  2, 17, 50, 1,  54,  6},
   { 30000,  16000,   8000,  2, 1,  3, 10, 14, 50, 1,  3, 11, 10, 100,  3, 17, 50,  2, 17, 50, 1,  54,  6},
   { 30000,  16000,   8000,  2, 1,  3, 10, 14, 50, 1,  3, 11, 10, 100,  3, 17, 50,  2, 17, 50, 1,  54,  6}
  },
  { // 1280x720
   {260000, 170000, 53000,  22, 3, 18, 0x2A, 0x2A, 0x32, 0x6, 0xc, 0x1C, 0x1C, 0x64,    0x04, 0x51,0x32,  4, 54, 50, 0,  54,  6},
   {260000, 170000, 53000,  22, 3, 18, 0x2A, 0x2A, 0x32, 0x4, 0xc, 0x1C, 0x1C, 0x64,  0x04, 0x51,0x32,  4, 54, 50, 1,  54,  6},
   {260000, 170000, 53000,  22, 3, 18, 0x2A, 0x2A, 0x32, 0x2, 0xc, 0x1C, 0x1C, 0x64,  0x04, 0x51,0x32,  4, 54, 50, 1,  54,  6},
   {260000, 170000, 53000,  22, 3, 18, 0x2A, 0x2A, 0x32, 0x2, 0xc, 0x1C, 0x1C, 0x64,  0x04, 0x51,0x32,  4, 54, 50, 1,  54,  6},
   {260000, 170000, 53000,  22, 3, 18, 0x2A, 0x2A, 0x32, 0x2, 0xc, 0x1C, 0x1C, 0x64,  0x04, 0x51,0x32,  4, 54, 50, 1,  54,  6}
  },
  { // 1920x1080
    {530000, 381600, 120000, 14, 4, 18, 30, 60, 50, 6, 12, 28, 50, 100, 10, 81, 50, 15, 54, 50, 0,  54,  6},
    {370000, 118400,  80000,  4, 3, 14, 20, 32, 50, 3,  8, 15, 40, 100,  8, 35, 50,  8, 45, 50, 1,  54,  6},
    {250000, 110000,  60000,  3, 2,  8, 15, 20, 50, 2,  5, 12, 22, 100,  5, 25, 50,  4, 27, 50, 1,  54,  6},
    {150000,  80000,  40000,  2, 1,  3, 10, 14, 50, 1,  3,  6, 10, 100,  3, 17, 50,  2, 17, 50, 1,  54,  6},
    {150000,  80000,  40000,  2, 1,  3, 10, 14, 50, 1,  3,  6, 10, 100,  3, 17, 50,  2, 17, 50, 1,  54,  6}
  }
};

MA_THRESHOLD_T MA_FHD_TH = {
	.H_ED_TH = 0x32,
	.TH_NM_YW = 0x2,
	.MA_EDGE_MODE6 = 0x1,
};

MA_THRESHOLD_T MA_HD_TH = {
	.H_ED_TH = 0x10,
	.TH_NM_YW = 0x2,
	.MA_EDGE_MODE6 = 0x1,
};

MA_THRESHOLD_T MA_PAL_TH = {
	.H_ED_TH = 0x10,
	.TH_NM_YW = 0x2,
	.MA_EDGE_MODE6 = 0x1,
};

MA_THRESHOLD_T MA_NTSC_TH = {
	.H_ED_TH = 0x10,
	.TH_NM_YW = 0x2,
	.MA_EDGE_MODE6 = 0x1,
};

MA_THRESHOLD_T MA_OTHER_TH = {
	.H_ED_TH = 0x10,
	.TH_NM_YW = 0x2,
	.MA_EDGE_MODE6 = 0x1,
};

void di_set_h_edge_thr(int thr)
{
	MA_FHD_TH.H_ED_TH = thr;
}

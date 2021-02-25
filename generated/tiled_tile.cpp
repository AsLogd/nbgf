#include "tiled_tile.h"

namespace Tiled {

const GPU_Rect Tile::TileToTextureRect[] = {
	{},	//NONE
	{ 9 * 16, 2 * 16, 16, 16 }, //=1, BG_1, gid=67
	{ 10 * 16, 2 * 16, 16, 16 }, //=2, BG_2, gid=68
	{ 11 * 16, 2 * 16, 16, 16 }, //=3, BG_3, gid=69
	{ 21 * 16, 2 * 16, 16, 16 }, //=4, BG_4, gid=79
	{ 22 * 16, 2 * 16, 16, 16 }, //=5, BG_5, gid=80
	{ 23 * 16, 2 * 16, 16, 16 }, //=6, BG_6, gid=81
	{ 24 * 16, 2 * 16, 16, 16 }, //=7, BG_7, gid=82
	{ 14 * 16, 3 * 16, 16, 16 }, //=8, BG_8, gid=101
	{ 15 * 16, 3 * 16, 16, 16 }, //=9, BG_9, gid=102
	{ 16 * 16, 3 * 16, 16, 16 }, //=10, BG_10, gid=103
	{ 17 * 16, 3 * 16, 16, 16 }, //=11, BG_11, gid=104
	{ 18 * 16, 3 * 16, 16, 16 }, //=12, BG_12, gid=105
	{ 21 * 16, 3 * 16, 16, 16 }, //=13, BG_13, gid=108
	{ 22 * 16, 3 * 16, 16, 16 }, //=14, BG_14, gid=109
	{ 23 * 16, 3 * 16, 16, 16 }, //=15, BG_15, gid=110
	{ 24 * 16, 3 * 16, 16, 16 }, //=16, BG_16, gid=111
	{ 8 * 16, 4 * 16, 16, 16 }, //=17, BG_17, gid=124
	{ 9 * 16, 4 * 16, 16, 16 }, //=18, BG_18, gid=125
	{ 10 * 16, 4 * 16, 16, 16 }, //=19, BG_19, gid=126
	{ 11 * 16, 4 * 16, 16, 16 }, //=20, BG_20, gid=127
	{ 12 * 16, 4 * 16, 16, 16 }, //=21, BG_21, gid=128
	{ 19 * 16, 4 * 16, 16, 16 }, //=22, BG_22, gid=135
	{ 21 * 16, 4 * 16, 16, 16 }, //=23, BG_23, gid=137
	{ 22 * 16, 4 * 16, 16, 16 }, //=24, BG_24, gid=138
	{ 23 * 16, 4 * 16, 16, 16 }, //=25, BG_25, gid=139
	{ 26 * 16, 4 * 16, 16, 16 }, //=26, BG_26, gid=142
	{ 27 * 16, 4 * 16, 16, 16 }, //=27, BG_27, gid=143
	{ 8 * 16, 5 * 16, 16, 16 }, //=28, BG_28, gid=153
	{ 9 * 16, 5 * 16, 16, 16 }, //=29, BG_29, gid=154
	{ 10 * 16, 5 * 16, 16, 16 }, //=30, BG_30, gid=155
	{ 11 * 16, 5 * 16, 16, 16 }, //=31, BG_31, gid=156
	{ 12 * 16, 5 * 16, 16, 16 }, //=32, BG_32, gid=157
	{ 13 * 16, 5 * 16, 16, 16 }, //=33, BG_33, gid=158
	{ 15 * 16, 5 * 16, 16, 16 }, //=34, BG_34, gid=160
	{ 19 * 16, 5 * 16, 16, 16 }, //=35, BG_35, gid=164
	{ 20 * 16, 5 * 16, 16, 16 }, //=36, BG_36, gid=165
	{ 21 * 16, 5 * 16, 16, 16 }, //=37, BG_37, gid=166
	{ 8 * 16, 6 * 16, 16, 16 }, //=38, BG_38, gid=182
	{ 9 * 16, 6 * 16, 16, 16 }, //=39, BG_39, gid=183
	{ 10 * 16, 6 * 16, 16, 16 }, //=40, BG_40, gid=184
	{ 11 * 16, 6 * 16, 16, 16 }, //=41, BG_41, gid=185
	{ 16 * 16, 6 * 16, 16, 16 }, //=42, BG_42, gid=190
	{ 17 * 16, 6 * 16, 16, 16 }, //=43, BG_43, gid=191
	{ 18 * 16, 6 * 16, 16, 16 }, //=44, BG_44, gid=192
	{ 19 * 16, 6 * 16, 16, 16 }, //=45, BG_45, gid=193
	{ 20 * 16, 6 * 16, 16, 16 }, //=46, BG_46, gid=194
	{ 21 * 16, 6 * 16, 16, 16 }, //=47, BG_47, gid=195
	{ 22 * 16, 6 * 16, 16, 16 }, //=48, BG_48, gid=196
	{ 23 * 16, 6 * 16, 16, 16 }, //=49, BG_49, gid=197
	{ 6 * 16, 7 * 16, 16, 16 }, //=50, BG_50, gid=209
	{ 8 * 16, 7 * 16, 16, 16 }, //=51, BG_51, gid=211
	{ 9 * 16, 7 * 16, 16, 16 }, //=52, BG_52, gid=212
	{ 10 * 16, 7 * 16, 16, 16 }, //=53, BG_53, gid=213
	{ 16 * 16, 7 * 16, 16, 16 }, //=54, BG_54, gid=219
	{ 17 * 16, 7 * 16, 16, 16 }, //=55, BG_55, gid=220
	{ 19 * 16, 7 * 16, 16, 16 }, //=56, BG_56, gid=222
	{ 20 * 16, 7 * 16, 16, 16 }, //=57, BG_57, gid=223
	{ 21 * 16, 7 * 16, 16, 16 }, //=58, BG_58, gid=224
	{ 22 * 16, 7 * 16, 16, 16 }, //=59, BG_59, gid=225
	{ 28 * 16, 7 * 16, 16, 16 }, //=60, BG_60, gid=231
	{ 8 * 16, 8 * 16, 16, 16 }, //=61, BG_61, gid=240
	{ 9 * 16, 8 * 16, 16, 16 }, //=62, BG_62, gid=241
	{ 10 * 16, 8 * 16, 16, 16 }, //=63, BG_63, gid=242
	{ 17 * 16, 8 * 16, 16, 16 }, //=64, BG_64, gid=249
	{ 18 * 16, 8 * 16, 16, 16 }, //=65, BG_65, gid=250
	{ 19 * 16, 8 * 16, 16, 16 }, //=66, BG_66, gid=251
	{ 20 * 16, 8 * 16, 16, 16 }, //=67, BG_67, gid=252
	{ 8 * 16, 9 * 16, 16, 16 }, //=68, BG_68, gid=269
	{ 9 * 16, 9 * 16, 16, 16 }, //=69, BG_69, gid=270
	{ 11 * 16, 9 * 16, 16, 16 }, //=70, BG_70, gid=272
	{ 13 * 16, 9 * 16, 16, 16 }, //=71, BG_71, gid=274
	{ 15 * 16, 9 * 16, 16, 16 }, //=72, BG_72, gid=276
	{ 16 * 16, 9 * 16, 16, 16 }, //=73, BG_73, gid=277
	{ 17 * 16, 9 * 16, 16, 16 }, //=74, BG_74, gid=278
	{ 18 * 16, 9 * 16, 16, 16 }, //=75, BG_75, gid=279
	{ 19 * 16, 9 * 16, 16, 16 }, //=76, BG_76, gid=280
	{ 20 * 16, 9 * 16, 16, 16 }, //=77, BG_77, gid=281
	{ 12 * 16, 10 * 16, 16, 16 }, //=78, BG_78, gid=302
	{ 14 * 16, 10 * 16, 16, 16 }, //=79, BG_79, gid=304
	{ 15 * 16, 10 * 16, 16, 16 }, //=80, BG_80, gid=305
	{ 17 * 16, 10 * 16, 16, 16 }, //=81, BG_81, gid=307
	{ 18 * 16, 10 * 16, 16, 16 }, //=82, BG_82, gid=308
	{ 20 * 16, 10 * 16, 16, 16 }, //=83, BG_83, gid=310
	{ 11 * 16, 11 * 16, 16, 16 }, //=84, BG_84, gid=330
	{ 13 * 16, 11 * 16, 16, 16 }, //=85, BG_85, gid=332
	{ 18 * 16, 11 * 16, 16, 16 }, //=86, BG_86, gid=337
	{ 19 * 16, 11 * 16, 16, 16 }, //=87, BG_87, gid=338
	{ 20 * 16, 11 * 16, 16, 16 }, //=88, BG_88, gid=339
	{ 21 * 16, 11 * 16, 16, 16 }, //=89, BG_89, gid=340
	{ 22 * 16, 11 * 16, 16, 16 }, //=90, BG_90, gid=341
	{ 23 * 16, 11 * 16, 16, 16 }, //=91, BG_91, gid=342
	{ 24 * 16, 11 * 16, 16, 16 }, //=92, BG_92, gid=343
	{ 25 * 16, 11 * 16, 16, 16 }, //=93, BG_93, gid=344
	{ 8 * 16, 12 * 16, 16, 16 }, //=94, BG_94, gid=356
	{ 9 * 16, 12 * 16, 16, 16 }, //=95, BG_95, gid=357
	{ 10 * 16, 12 * 16, 16, 16 }, //=96, BG_96, gid=358
	{ 11 * 16, 12 * 16, 16, 16 }, //=97, BG_97, gid=359
	{ 12 * 16, 12 * 16, 16, 16 }, //=98, BG_98, gid=360
	{ 13 * 16, 12 * 16, 16, 16 }, //=99, BG_99, gid=361
	{ 15 * 16, 12 * 16, 16, 16 }, //=100, BG_100, gid=363
	{ 18 * 16, 12 * 16, 16, 16 }, //=101, BG_101, gid=366
	{ 19 * 16, 12 * 16, 16, 16 }, //=102, BG_102, gid=367
	{ 20 * 16, 12 * 16, 16, 16 }, //=103, BG_103, gid=368
	{ 14 * 16, 13 * 16, 16, 16 }, //=104, BG_104, gid=391
	{ 15 * 16, 13 * 16, 16, 16 }, //=105, BG_105, gid=392
	{ 17 * 16, 13 * 16, 16, 16 }, //=106, BG_106, gid=394
	{ 18 * 16, 13 * 16, 16, 16 }, //=107, BG_107, gid=395
	{ 19 * 16, 13 * 16, 16, 16 }, //=108, BG_108, gid=396
	{ 20 * 16, 13 * 16, 16, 16 }, //=109, BG_109, gid=397
	{ 0 * 16, 14 * 16, 16, 16 }, //=110, BG_110, gid=406
	{ 1 * 16, 14 * 16, 16, 16 }, //=111, BG_111, gid=407
	{ 2 * 16, 14 * 16, 16, 16 }, //=112, BG_112, gid=408
	{ 3 * 16, 14 * 16, 16, 16 }, //=113, BG_113, gid=409
	{ 4 * 16, 14 * 16, 16, 16 }, //=114, BG_114, gid=410
	{ 5 * 16, 14 * 16, 16, 16 }, //=115, BG_115, gid=411
	{ 10 * 16, 14 * 16, 16, 16 }, //=116, BG_116, gid=416
	{ 11 * 16, 14 * 16, 16, 16 }, //=117, BG_117, gid=417
	{ 12 * 16, 14 * 16, 16, 16 }, //=118, BG_118, gid=418
	{ 13 * 16, 14 * 16, 16, 16 }, //=119, BG_119, gid=419
	{ 17 * 16, 14 * 16, 16, 16 }, //=120, BG_120, gid=423
	{ 18 * 16, 14 * 16, 16, 16 }, //=121, BG_121, gid=424
	{ 19 * 16, 14 * 16, 16, 16 }, //=122, BG_122, gid=425
	{ 20 * 16, 14 * 16, 16, 16 }, //=123, BG_123, gid=426
	{ 21 * 16, 14 * 16, 16, 16 }, //=124, BG_124, gid=427
	{ 22 * 16, 14 * 16, 16, 16 }, //=125, BG_125, gid=428
	{ 26 * 16, 14 * 16, 16, 16 }, //=126, BG_126, gid=432
	{ 27 * 16, 14 * 16, 16, 16 }, //=127, BG_127, gid=433
	{ 16 * 16, 15 * 16, 16, 16 }, //=128, BG_128, gid=451
	{ 18 * 16, 15 * 16, 16, 16 }, //=129, BG_129, gid=453
	{ 19 * 16, 15 * 16, 16, 16 }, //=130, BG_130, gid=454
	{ 20 * 16, 15 * 16, 16, 16 }, //=131, BG_131, gid=455
	{ 24 * 16, 15 * 16, 16, 16 }, //=132, BG_132, gid=459
	{ 25 * 16, 15 * 16, 16, 16 }, //=133, BG_133, gid=460
	{ 28 * 16, 2 * 16, 16, 16 }, //=134, ONEWAY_1, gid=86
	{ 19 * 16, 3 * 16, 16, 16 }, //=135, ONEWAY_2, gid=106
	{ 20 * 16, 3 * 16, 16, 16 }, //=136, ONEWAY_3, gid=107
	{ 28 * 16, 3 * 16, 16, 16 }, //=137, ONEWAY_4, gid=115
	{ 16 * 16, 4 * 16, 16, 16 }, //=138, ONEWAY_5, gid=132
	{ 17 * 16, 4 * 16, 16, 16 }, //=139, ONEWAY_6, gid=133
	{ 18 * 16, 4 * 16, 16, 16 }, //=140, ONEWAY_7, gid=134
	{ 20 * 16, 4 * 16, 16, 16 }, //=141, ONEWAY_8, gid=136
	{ 28 * 16, 4 * 16, 16, 16 }, //=142, ONEWAY_9, gid=144
	{ 22 * 16, 5 * 16, 16, 16 }, //=143, ONEWAY_10, gid=167
	{ 23 * 16, 5 * 16, 16, 16 }, //=144, ONEWAY_11, gid=168
	{ 25 * 16, 6 * 16, 16, 16 }, //=145, ONEWAY_12, gid=199
	{ 27 * 16, 11 * 16, 16, 16 }, //=146, ONEWAY_13, gid=346
	{ 21 * 16, 12 * 16, 16, 16 }, //=147, ONEWAY_14, gid=369
	{ 22 * 16, 12 * 16, 16, 16 }, //=148, ONEWAY_15, gid=370
	{ 24 * 16, 12 * 16, 16, 16 }, //=149, ONEWAY_16, gid=372
	{ 27 * 16, 12 * 16, 16, 16 }, //=150, ONEWAY_17, gid=375
	{ 28 * 16, 12 * 16, 16, 16 }, //=151, ONEWAY_18, gid=376
	{ 10 * 16, 1 * 16, 16, 16 }, //=152, RSLOPE_1, gid=39
	{ 13 * 16, 1 * 16, 16, 16 }, //=153, RSLOPE_2, gid=42
	{ 23 * 16, 7 * 16, 16, 16 }, //=154, RSLOPE_3, gid=226
	{ 22 * 16, 8 * 16, 16, 16 }, //=155, RSLOPE_4, gid=254
	{ 11 * 16, 1 * 16, 16, 16 }, //=156, LSLOPE_1, gid=40
	{ 12 * 16, 1 * 16, 16, 16 }, //=157, LSLOPE_2, gid=41
	{ 27 * 16, 7 * 16, 16, 16 }, //=158, LSLOPE_3, gid=230
	{ 28 * 16, 8 * 16, 16, 16 }, //=159, LSLOPE_4, gid=260
	{ 10 * 16, 0 * 16, 16, 16 }, //=160, SOLID_1, gid=10
	{ 11 * 16, 0 * 16, 16, 16 }, //=161, SOLID_2, gid=11
	{ 3 * 16, 2 * 16, 16, 16 }, //=162, SOLID_3, gid=61
	{ 12 * 16, 2 * 16, 16, 16 }, //=163, SOLID_4, gid=70
	{ 13 * 16, 2 * 16, 16, 16 }, //=164, SOLID_5, gid=71
	{ 14 * 16, 2 * 16, 16, 16 }, //=165, SOLID_6, gid=72
	{ 15 * 16, 2 * 16, 16, 16 }, //=166, SOLID_7, gid=73
	{ 16 * 16, 2 * 16, 16, 16 }, //=167, SOLID_8, gid=74
	{ 17 * 16, 2 * 16, 16, 16 }, //=168, SOLID_9, gid=75
	{ 18 * 16, 2 * 16, 16, 16 }, //=169, SOLID_10, gid=76
	{ 19 * 16, 2 * 16, 16, 16 }, //=170, SOLID_11, gid=77
	{ 20 * 16, 2 * 16, 16, 16 }, //=171, SOLID_12, gid=78
	{ 8 * 16, 3 * 16, 16, 16 }, //=172, SOLID_13, gid=95
	{ 9 * 16, 3 * 16, 16, 16 }, //=173, SOLID_14, gid=96
	{ 10 * 16, 3 * 16, 16, 16 }, //=174, SOLID_15, gid=97
	{ 11 * 16, 3 * 16, 16, 16 }, //=175, SOLID_16, gid=98
	{ 12 * 16, 3 * 16, 16, 16 }, //=176, SOLID_17, gid=99
	{ 13 * 16, 3 * 16, 16, 16 }, //=177, SOLID_18, gid=100
	{ 15 * 16, 4 * 16, 16, 16 }, //=178, SOLID_19, gid=131
	{ 6 * 16, 6 * 16, 16, 16 }, //=179, SOLID_20, gid=180
	{ 24 * 16, 7 * 16, 16, 16 }, //=180, SOLID_21, gid=227
	{ 25 * 16, 7 * 16, 16, 16 }, //=181, SOLID_22, gid=228
	{ 26 * 16, 7 * 16, 16, 16 }, //=182, SOLID_23, gid=229
	{ 6 * 16, 8 * 16, 16, 16 }, //=183, SOLID_24, gid=238
	{ 23 * 16, 8 * 16, 16, 16 }, //=184, SOLID_25, gid=255
	{ 27 * 16, 8 * 16, 16, 16 }, //=185, SOLID_26, gid=259
	{ 4 * 16, 9 * 16, 16, 16 }, //=186, SOLID_27, gid=265
	{ 22 * 16, 9 * 16, 16, 16 }, //=187, SOLID_28, gid=283
	{ 28 * 16, 9 * 16, 16, 16 }, //=188, SOLID_29, gid=289
	{ 22 * 16, 10 * 16, 16, 16 }, //=189, SOLID_30, gid=312
	{ 28 * 16, 10 * 16, 16, 16 }, //=190, SOLID_31, gid=318
	{ 24 * 16, 13 * 16, 16, 16 }, //=191, SOLID_32, gid=401
	{ 25 * 16, 13 * 16, 16, 16 }, //=192, SOLID_33, gid=402
	{ 24 * 16, 14 * 16, 16, 16 }, //=193, SOLID_34, gid=430
	{ 25 * 16, 14 * 16, 16, 16 }, //=194, SOLID_35, gid=431
	{ 26 * 16, 15 * 16, 16, 16 }, //=195, SOLID_36, gid=461
	{ 27 * 16, 15 * 16, 16, 16 }, //=196, SOLID_37, gid=462
	{ 24 * 16, 1 * 16, 16, 16 }, //=197, BREAKABLE_1, gid=53
	{ 25 * 16, 1 * 16, 16, 16 }, //=198, BREAKABLE_2, gid=54
	{ 4 * 16, 2 * 16, 16, 16 }, //=199, BREAKABLE_3, gid=62
	{},	//SOLID_TRANSPARENT
};

}
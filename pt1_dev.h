/* -*- tab-width: 4; indent-tabs-mode: nil -*- */
#ifndef _PT1_DEV_H_
#define _PT1_DEV_H_


#ifndef FULLAUTO_SEARCH
#define FULLAUTO_SEARCH 1		// 0にする事で以下のDVBデバイス番号テーブルを利用したDVB自動選択に処理を変更できる
#endif

#if FULLAUTO_SEARCH == 0
// DVBデバイス番号テーブル
// 環境により各々違うと思われるので各自で適切に変更すること
//
// DVBデバイス番号を変更する場合は、/etc/modrpobe.d/options-dvb.confを以下の1行を参考に編集してください。
// options earth_pt1 adapter_nr=0,1,2,3			// 衛星0 地上0 衛星1 地上1の順に指定

// BS/CS
int bsdev[] = {
    0,
    2,
    4,
    6,
    8,
    10,
    12,
    14
};
// VHF/UHF/CATV
int isdb_t_dev[] = {
    1,
    3,
    5,
    7,
    9,
    11,
    13,
    15
};

#define NUM_BSDEV				(sizeof(bsdev)/sizeof(int))
#define NUM_ISDB_T_DEV			(sizeof(isdb_t_dev)/sizeof(int))
#endif

#include "ch_conv_table_dvb.h"

#endif

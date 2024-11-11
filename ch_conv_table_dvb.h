//
// 変換テーブル
//
#define  BS_01  0
#define  BS_03  1
#define  BS_05  2
#define  BS_07  3
#define  BS_09  4
#define  BS_11  5
#define  BS_13  6
#define  BS_15  7
#define  BS_17  8
#define  BS_19  9
#define  BS_21  10
#define  BS_23  11
#define  CS_02  12
#define  CS_04  13
#define  CS_06  14
#define  CS_08  15
#define  CS_10  16
#define  CS_12  17
#define  CS_14  18
#define  CS_16  19
#define  CS_18  20
#define  CS_20  21
#define  CS_22  22
#define  CS_24  23

ISDB_T_FREQ_CONV_TABLE    isdb_t_conv_table[] = {
    { BS_01, CHTYPE_SATELLITE, 0, 0x4010, "151"},  /* BS朝日1 */
    { BS_01, CHTYPE_SATELLITE, 1, 0x4011, "161"},  /* BS-TBS */
    { BS_01, CHTYPE_SATELLITE, 1, 0x4011, "162"},  /* BS-TBS */
    { BS_01, CHTYPE_SATELLITE, 2, 0x4012, "171"},  /* BSテレ東 */
    { BS_01, CHTYPE_SATELLITE, 2, 0x4012, "172"},  /* BSテレ東2 */
    { BS_01, CHTYPE_SATELLITE, 2, 0x4012, "777"},  /* 株価情報 */
    { BS_03, CHTYPE_SATELLITE, 0, 0x4030, "191"},  /* WOWOWプライム */
    { BS_03, CHTYPE_SATELLITE, 1, 0x4631, "236"},  /* BSアニマックス */
    { BS_03, CHTYPE_SATELLITE, 2, 0x4632, "251"},  /* BS釣りビジョン */
    { BS_05, CHTYPE_SATELLITE, 0, 0x4450, "192"},  /* WOWOWライブ */
    { BS_05, CHTYPE_SATELLITE, 1, 0x4451, "193"},  /* WOWOWシネマ */
    { BS_09, CHTYPE_SATELLITE, 0, 0x4090, "211"},  /* BS11イレブン */
    { BS_09, CHTYPE_SATELLITE, 2, 0x4092, "222"},  /* BS12トゥエルビ */
    { BS_13, CHTYPE_SATELLITE, 0, 0x40d0, "141"},  /* BS日テレ */
    { BS_13, CHTYPE_SATELLITE, 0, 0x40d0, "142"},  /* BS日テレ */
    { BS_13, CHTYPE_SATELLITE, 1, 0x40d1, "181"},  /* BSフジ・181 */
    { BS_13, CHTYPE_SATELLITE, 1, 0x40d1, "182"},  /* BSフジ・182 */
    { BS_13, CHTYPE_SATELLITE, 2, 0x46d2, "231"},  /* 放送大学テレビ */
    { BS_13, CHTYPE_SATELLITE, 2, 0x46d2, "232"},  /* 放送大学テレビ */
    { BS_13, CHTYPE_SATELLITE, 2, 0x46d2, "531"},  /* 放送大学ラジオ */
    { BS_15, CHTYPE_SATELLITE, 0, 0x40f1, "101"},  /* NHK BS */
    { BS_15, CHTYPE_SATELLITE, 0, 0x40f1, "102"},  /* NHK BS */
    { BS_15, CHTYPE_SATELLITE, 1, 0x40f2, "200"},  /* スターチャンネル */
    { BS_15, CHTYPE_SATELLITE, 1, 0x40f2, "800"},  /* スターチャンネル */
    { BS_19, CHTYPE_SATELLITE, 0, 0x4730, "245"},  /* J SPORTS 4 */
    { BS_19, CHTYPE_SATELLITE, 1, 0x4731, "242"},  /* J SPORTS 1 */
    { BS_19, CHTYPE_SATELLITE, 2, 0x4732, "243"},  /* J SPORTS 2 */
    { BS_19, CHTYPE_SATELLITE, 3, 0x4733, "244"},  /* J SPORTS 3 */
    { BS_21, CHTYPE_SATELLITE, 0, 0x4750, "252"},  /* WOWOWプラス */
    { BS_21, CHTYPE_SATELLITE, 1, 0x4751, "255"},  /* 日本映画専門ch */
    { BS_21, CHTYPE_SATELLITE, 2, 0x4752, "234"},  /* グリーンチャンネル */
    { BS_23, CHTYPE_SATELLITE, 0, 0x4770, "256"},  /* ディズニーch */
    { BS_23, CHTYPE_SATELLITE, 1, 0x4971, "265"},  /* BSよしもと */
    { BS_23, CHTYPE_SATELLITE, 2, 0x4972, "263"},  /* BSJapanext */
    { BS_23, CHTYPE_SATELLITE, 3, 0x4973, "260"},  /* BS松竹東急 */

    { CS_02, CHTYPE_SATELLITE, 0, 0x6020, "CS2" },  /* ND2 */
    { CS_04, CHTYPE_SATELLITE, 0, 0x7040, "CS4" },  /* ND4 */
    { CS_06, CHTYPE_SATELLITE, 0, 0x7060, "CS6" },  /* ND6 */
    { CS_08, CHTYPE_SATELLITE, 0, 0x6080, "CS8" },  /* ND8 */
    { CS_10, CHTYPE_SATELLITE, 0, 0x60a0, "CS10"},  /* ND10 */
    { CS_12, CHTYPE_SATELLITE, 0, 0x70c0, "CS12"},  /* ND12 */
    { CS_14, CHTYPE_SATELLITE, 0, 0x70e0, "CS14"},  /* ND14 */
    { CS_16, CHTYPE_SATELLITE, 0, 0x7100, "CS16"},  /* ND16 */
    { CS_18, CHTYPE_SATELLITE, 0, 0x7120, "CS18"},  /* ND18 */
    { CS_20, CHTYPE_SATELLITE, 0, 0x7140, "CS20"},  /* ND20 */
    { CS_22, CHTYPE_SATELLITE, 0, 0x7160, "CS22"},  /* ND22 */
    { CS_24, CHTYPE_SATELLITE, 0, 0x7180, "CS24"},  /* ND24 */

    { CS_02, CHTYPE_SATELLITE, 0, 0x6020, "296" },  /* TBSチャンネル1 */
    { CS_02, CHTYPE_SATELLITE, 0, 0x6020, "298" },  /* テレ朝チャンネル1 */
    { CS_02, CHTYPE_SATELLITE, 0, 0x6020, "299" },  /* テレ朝チャンネル2 */
    { CS_02, CHTYPE_SATELLITE, 0, 0x6020, "339" },  /* ディズニージュニア */
    { CS_04, CHTYPE_SATELLITE, 0, 0x7040, "250" },  /* スカイA */
    { CS_04, CHTYPE_SATELLITE, 0, 0x7040, "292" },  /* 時代劇専門ch */
    { CS_04, CHTYPE_SATELLITE, 0, 0x7040, "301" },  /* エンタメ〜テレ */
    { CS_04, CHTYPE_SATELLITE, 0, 0x7040, "323" },  /* MTV */
    { CS_06, CHTYPE_SATELLITE, 0, 0x7060, "294" },  /* ホームドラマCH */
    { CS_06, CHTYPE_SATELLITE, 0, 0x7060, "324" },  /* ミュージック・エア */
    { CS_06, CHTYPE_SATELLITE, 0, 0x7060, "329" },  /* 歌謡ポップス */
    { CS_06, CHTYPE_SATELLITE, 0, 0x7060, "331" },  /* カートゥーン */
    { CS_06, CHTYPE_SATELLITE, 0, 0x7060, "340" },  /* ディスカバリー */
    { CS_06, CHTYPE_SATELLITE, 0, 0x7060, "341" },  /* アニマルプラネット */
    { CS_06, CHTYPE_SATELLITE, 0, 0x7060, "354" },  /* CNNj */
    { CS_06, CHTYPE_SATELLITE, 0, 0x7060, "363" },  /* 囲碁・将棋チャンネル */
    { CS_08, CHTYPE_SATELLITE, 0, 0x6080, "218" },  /* 東映チャンネル */
    { CS_08, CHTYPE_SATELLITE, 0, 0x6080, "318" },  /* Mnet */
    { CS_08, CHTYPE_SATELLITE, 0, 0x6080, "349" },  /* 日テレNEWS24 */
    { CS_08, CHTYPE_SATELLITE, 0, 0x6080, "55"  },  /* ショップチャンネル */
    { CS_10, CHTYPE_SATELLITE, 0, 0x60a0, "101" },  /* スカパー！インフォ */
    { CS_10, CHTYPE_SATELLITE, 0, 0x60a0, "219" },  /* 衛星劇場 */
    { CS_10, CHTYPE_SATELLITE, 0, 0x60a0, "317" },  /* KBS World */
    { CS_10, CHTYPE_SATELLITE, 0, 0x60a0, "800" },  /* スポーツライブ＋ */
    { CS_10, CHTYPE_SATELLITE, 0, 0x60a0, "801" },  /* スカチャン1 */
    { CS_12, CHTYPE_SATELLITE, 0, 0x70c0, "254" },  /* GAORA */
    { CS_12, CHTYPE_SATELLITE, 0, 0x70c0, "325" },  /* エムオン！ */
    { CS_12, CHTYPE_SATELLITE, 0, 0x70c0, "330" },  /* キッズステーション */
    { CS_12, CHTYPE_SATELLITE, 0, 0x70c0, "343" },  /* ナショジオ */
    { CS_14, CHTYPE_SATELLITE, 0, 0x70e0, "227" },  /* ザ・シネマ */
    { CS_14, CHTYPE_SATELLITE, 0, 0x70e0, "293" },  /* ファミリー劇場 */
    { CS_14, CHTYPE_SATELLITE, 0, 0x70e0, "310" },  /* スーパー！ドラマTV */
    { CS_14, CHTYPE_SATELLITE, 0, 0x70e0, "342" },  /* ヒストリーチャンネル */
    { CS_16, CHTYPE_SATELLITE, 0, 0x7100, "290" },  /* SKY STAGE */
    { CS_16, CHTYPE_SATELLITE, 0, 0x7100, "311" },  /* アクションチャンネル */
    { CS_16, CHTYPE_SATELLITE, 0, 0x7100, "316" },  /* ミステリーチャンネル */
    { CS_16, CHTYPE_SATELLITE, 0, 0x7100, "321" },  /* スペシャプラス */
    { CS_16, CHTYPE_SATELLITE, 0, 0x7100, "333" },  /* AT−X */
    { CS_16, CHTYPE_SATELLITE, 0, 0x7100, "353" },  /* BBCニュース */
    { CS_18, CHTYPE_SATELLITE, 0, 0x7120, "240" },  /* ムービープラス */
    { CS_18, CHTYPE_SATELLITE, 0, 0x7120, "262" },  /* ゴルフネットワーク */
    { CS_18, CHTYPE_SATELLITE, 0, 0x7120, "305" },  /* チャンネル銀河 */
    { CS_18, CHTYPE_SATELLITE, 0, 0x7120, "314" },  /* LaLaTV */
    { CS_20, CHTYPE_SATELLITE, 0, 0x7140, "307" },  /* フジテレビONE */
    { CS_20, CHTYPE_SATELLITE, 0, 0x7140, "308" },  /* フジテレビTWO */
    { CS_20, CHTYPE_SATELLITE, 0, 0x7140, "309" },  /* フジテレビNEXT */
    { CS_20, CHTYPE_SATELLITE, 0, 0x7140, "322" },  /* スペースシャワーTV */
    { CS_22, CHTYPE_SATELLITE, 0, 0x7160, "161" },  /* QVC */
    { CS_22, CHTYPE_SATELLITE, 0, 0x7160, "297" },  /* TBSチャンネル2 */
    { CS_22, CHTYPE_SATELLITE, 0, 0x7160, "312" },  /* Dlife */
    { CS_22, CHTYPE_SATELLITE, 0, 0x7160, "351" },  /* TBS NEWS */
    { CS_24, CHTYPE_SATELLITE, 0, 0x7180, "223" },  /* 映画・chNECO */
    { CS_24, CHTYPE_SATELLITE, 0, 0x7180, "257" },  /* 日テレジータス */
    { CS_24, CHTYPE_SATELLITE, 0, 0x7180, "295" },  /* MONDO TV */
    { CS_24, CHTYPE_SATELLITE, 0, 0x7180, "300" },  /* 日テレプラス */

    {   0, CHTYPE_GROUND, 0, 0,   "1"}, {   1, CHTYPE_GROUND, 0, 0,   "2"},
    {   2, CHTYPE_GROUND, 0, 0,   "3"}, {   3, CHTYPE_GROUND, 0, 0, "C13"},
    {   4, CHTYPE_GROUND, 0, 0, "C14"}, {   5, CHTYPE_GROUND, 0, 0, "C15"},
    {   6, CHTYPE_GROUND, 0, 0, "C16"}, {   7, CHTYPE_GROUND, 0, 0, "C17"},
    {   8, CHTYPE_GROUND, 0, 0, "C18"}, {   9, CHTYPE_GROUND, 0, 0, "C19"},
    {  10, CHTYPE_GROUND, 0, 0, "C20"}, {  11, CHTYPE_GROUND, 0, 0, "C21"},
    {  12, CHTYPE_GROUND, 0, 0, "C22"}, {  13, CHTYPE_GROUND, 0, 0,   "4"},
    {  14, CHTYPE_GROUND, 0, 0,   "5"}, {  15, CHTYPE_GROUND, 0, 0,   "6"},
    {  16, CHTYPE_GROUND, 0, 0,   "7"}, {  17, CHTYPE_GROUND, 0, 0,   "8"},
    {  18, CHTYPE_GROUND, 0, 0,   "9"}, {  19, CHTYPE_GROUND, 0, 0,  "10"},
    {  20, CHTYPE_GROUND, 0, 0,  "11"}, {  21, CHTYPE_GROUND, 0, 0,  "12"},
    {  22, CHTYPE_GROUND, 0, 0, "C23"}, {  23, CHTYPE_GROUND, 0, 0, "C24"},
    {  24, CHTYPE_GROUND, 0, 0, "C25"}, {  25, CHTYPE_GROUND, 0, 0, "C26"},
    {  26, CHTYPE_GROUND, 0, 0, "C27"}, {  27, CHTYPE_GROUND, 0, 0, "C28"},
    {  28, CHTYPE_GROUND, 0, 0, "C29"}, {  29, CHTYPE_GROUND, 0, 0, "C30"},
    {  30, CHTYPE_GROUND, 0, 0, "C31"}, {  31, CHTYPE_GROUND, 0, 0, "C32"},
    {  32, CHTYPE_GROUND, 0, 0, "C33"}, {  33, CHTYPE_GROUND, 0, 0, "C34"},
    {  34, CHTYPE_GROUND, 0, 0, "C35"}, {  35, CHTYPE_GROUND, 0, 0, "C36"},
    {  36, CHTYPE_GROUND, 0, 0, "C37"}, {  37, CHTYPE_GROUND, 0, 0, "C38"},
    {  38, CHTYPE_GROUND, 0, 0, "C39"}, {  39, CHTYPE_GROUND, 0, 0, "C40"},
    {  40, CHTYPE_GROUND, 0, 0, "C41"}, {  41, CHTYPE_GROUND, 0, 0, "C42"},
    {  42, CHTYPE_GROUND, 0, 0, "C43"}, {  43, CHTYPE_GROUND, 0, 0, "C44"},
    {  44, CHTYPE_GROUND, 0, 0, "C45"}, {  45, CHTYPE_GROUND, 0, 0, "C46"},
    {  46, CHTYPE_GROUND, 0, 0, "C47"}, {  47, CHTYPE_GROUND, 0, 0, "C48"},
    {  48, CHTYPE_GROUND, 0, 0, "C49"}, {  49, CHTYPE_GROUND, 0, 0, "C50"},
    {  50, CHTYPE_GROUND, 0, 0, "C51"}, {  51, CHTYPE_GROUND, 0, 0, "C52"},
    {  52, CHTYPE_GROUND, 0, 0, "C53"}, {  53, CHTYPE_GROUND, 0, 0, "C54"},
    {  54, CHTYPE_GROUND, 0, 0, "C55"}, {  55, CHTYPE_GROUND, 0, 0, "C56"},
    {  56, CHTYPE_GROUND, 0, 0, "C57"}, {  57, CHTYPE_GROUND, 0, 0, "C58"},
    {  58, CHTYPE_GROUND, 0, 0, "C59"}, {  59, CHTYPE_GROUND, 0, 0, "C60"},
    {  60, CHTYPE_GROUND, 0, 0, "C61"}, {  61, CHTYPE_GROUND, 0, 0, "C62"},
    {  62, CHTYPE_GROUND, 0, 0, "C63"}, {  63, CHTYPE_GROUND, 0, 0,  "13"},
    {  64, CHTYPE_GROUND, 0, 0,  "14"}, {  65, CHTYPE_GROUND, 0, 0,  "15"},
    {  66, CHTYPE_GROUND, 0, 0,  "16"}, {  67, CHTYPE_GROUND, 0, 0,  "17"},
    {  68, CHTYPE_GROUND, 0, 0,  "18"}, {  69, CHTYPE_GROUND, 0, 0,  "19"},
    {  70, CHTYPE_GROUND, 0, 0,  "20"}, {  71, CHTYPE_GROUND, 0, 0,  "21"},
    {  72, CHTYPE_GROUND, 0, 0,  "22"}, {  73, CHTYPE_GROUND, 0, 0,  "23"},
    {  74, CHTYPE_GROUND, 0, 0,  "24"}, {  75, CHTYPE_GROUND, 0, 0,  "25"},
    {  76, CHTYPE_GROUND, 0, 0,  "26"}, {  77, CHTYPE_GROUND, 0, 0,  "27"},
    {  78, CHTYPE_GROUND, 0, 0,  "28"}, {  79, CHTYPE_GROUND, 0, 0,  "29"},
    {  80, CHTYPE_GROUND, 0, 0,  "30"}, {  81, CHTYPE_GROUND, 0, 0,  "31"},
    {  82, CHTYPE_GROUND, 0, 0,  "32"}, {  83, CHTYPE_GROUND, 0, 0,  "33"},
    {  84, CHTYPE_GROUND, 0, 0,  "34"}, {  85, CHTYPE_GROUND, 0, 0,  "35"},
    {  86, CHTYPE_GROUND, 0, 0,  "36"}, {  87, CHTYPE_GROUND, 0, 0,  "37"},
    {  88, CHTYPE_GROUND, 0, 0,  "38"}, {  89, CHTYPE_GROUND, 0, 0,  "39"},
    {  90, CHTYPE_GROUND, 0, 0,  "40"}, {  91, CHTYPE_GROUND, 0, 0,  "41"},
    {  92, CHTYPE_GROUND, 0, 0,  "42"}, {  93, CHTYPE_GROUND, 0, 0,  "43"},
    {  94, CHTYPE_GROUND, 0, 0,  "44"}, {  95, CHTYPE_GROUND, 0, 0,  "45"},
    {  96, CHTYPE_GROUND, 0, 0,  "46"}, {  97, CHTYPE_GROUND, 0, 0,  "47"},
    {  98, CHTYPE_GROUND, 0, 0,  "48"}, {  99, CHTYPE_GROUND, 0, 0,  "49"},
    { 100, CHTYPE_GROUND, 0, 0,  "50"}, { 101, CHTYPE_GROUND, 0, 0,  "51"},
    { 102, CHTYPE_GROUND, 0, 0,  "52"}, { 103, CHTYPE_GROUND, 0, 0,  "53"},
    { 104, CHTYPE_GROUND, 0, 0,  "54"}, { 105, CHTYPE_GROUND, 0, 0,  "55"},
    { 106, CHTYPE_GROUND, 0, 0,  "56"}, { 107, CHTYPE_GROUND, 0, 0,  "57"},
    { 108, CHTYPE_GROUND, 0, 0,  "58"}, { 109, CHTYPE_GROUND, 0, 0,  "59"},
    { 110, CHTYPE_GROUND, 0, 0,  "60"}, { 111, CHTYPE_GROUND, 0, 0,  "61"},
    { 112, CHTYPE_GROUND, 0, 0,  "62"},
    { 0, 0, 0, 0, NULL} /* terminate */
};


char *helpChList[] = {
	"101 ch : NHK BS",
	"102 ch : NHK BS",
	"141 ch : BS日テレ",
	"142 ch : BS日テレ",
	"151 ch : BS朝日1",
	"161 ch : BS-TBS",
	"162 ch : BS-TBS",
	"171 ch : BSテレ東",
	"172 ch : BSテレ東2",
	"181 ch : BSフジ・181",
	"182 ch : BSフジ・182",
	"191 ch : WOWOWプライム",
	"192 ch : WOWOWライブ",
	"193 ch : WOWOWシネマ",
	"200 ch : スターチャンネル",
	"211 ch : BS11イレブン",
	"222 ch : BS12トゥエルビ",
	"231 ch : 放送大学テレビ",
	"232 ch : 放送大学テレビ",
	"234 ch : グリーンチャンネル",
	"236 ch : BSアニマックス",
	"242 ch : J SPORTS 1",
	"243 ch : J SPORTS 2",
	"244 ch : J SPORTS 3",
	"245 ch : J SPORTS 4",
	"251 ch : BS釣りビジョン",
	"252 ch : WOWOWプラス",
	"255 ch : 日本映画専門ch",
	"256 ch : ディズニーch",
	"260 ch : BS松竹東急",
	"263 ch : BSJapanext",
	"265 ch : BSよしもと",
	"531 ch : 放送大学ラジオ",
	"777 ch : 株価情報",
	"800 ch : スターチャンネル",
	"",
	" 55 ch : ショップチャンネル",
	"101 ch : スカパー！インフォ",
	"161 ch : QVC",
	"218 ch : 東映チャンネル",
	"219 ch : 衛星劇場",
	"223 ch : 映画・chNECO",
	"227 ch : ザ・シネマ",
	"240 ch : ムービープラス",
	"250 ch : スカイA",
	"254 ch : GAORA",
	"257 ch : 日テレジータス",
	"262 ch : ゴルフネットワーク",
	"290 ch : SKY STAGE",
	"292 ch : 時代劇専門ch",
	"293 ch : ファミリー劇場",
	"294 ch : ホームドラマCH",
	"295 ch : MONDO TV",
	"296 ch : TBSチャンネル1",
	"297 ch : TBSチャンネル2",
	"298 ch : テレ朝チャンネル1",
	"299 ch : テレ朝チャンネル2",
	"300 ch : 日テレプラス",
	"301 ch : エンタメ〜テレ",
	"305 ch : チャンネル銀河",
	"307 ch : フジテレビONE",
	"308 ch : フジテレビTWO",
	"309 ch : フジテレビNEXT",
	"310 ch : スーパー！ドラマTV",
	"311 ch : アクションチャンネル",
	"312 ch : Dlife",
	"314 ch : LaLaTV",
	"316 ch : ミステリーチャンネル",
	"317 ch : KBS World",
	"318 ch : Mnet",
	"321 ch : スペシャプラス",
	"322 ch : スペースシャワーTV",
	"323 ch : MTV",
	"324 ch : ミュージック・エア",
	"325 ch : エムオン！",
	"329 ch : 歌謡ポップス",
	"330 ch : キッズステーション",
	"331 ch : カートゥーン",
	"333 ch : AT−X",
	"339 ch : ディズニージュニア",
	"340 ch : ディスカバリー",
	"341 ch : アニマルプラネット",
	"342 ch : ヒストリーチャンネル",
	"343 ch : ナショジオ",
	"349 ch : 日テレNEWS24",
	"351 ch : TBS NEWS",
	"353 ch : BBCニュース",
	"354 ch : CNNj",
	"363 ch : 囲碁・将棋チャンネル",
	"800 ch : スポーツライブ＋",
	"801 ch : スカチャン1",
	NULL,
};

// created by mkChConvTable.rb (2024-11-11 11:06:48 +0900)
// BS = 35, CS = 55

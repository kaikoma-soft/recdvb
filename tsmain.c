#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <fcntl.h>
#include <sys/stat.h>
#include "config.h"
#include "decoder.h"
#include "tssplitter_lite.h"

#define MAX_READ_SIZE (188 * 100)
/* maximum write length at once */
#define SIZE_CHANK 1316
#define TRUE                1
#define FALSE               0
/**************************************************************************/
/**
 * 引数用構造体
 */
typedef struct {
	char* src;				// 入力ファイル
	char* dst;				// 出力ファイル
	char* sid;				// 出力対象チャンネル番号
} PARAM;
typedef int boolean;

void show_usage();
int AnalyzeParam(int argc, char** argv, PARAM* param);

int execute(PARAM* param);


/**************************************************************************/

/**
 *
 */
int main(
	int argc,							// [in]		引数の個数
	char** argv)						// [in]		引数
{
	PARAM param;

	int result;							// 処理結果

	// パラメータ解析
	result = AnalyzeParam(argc, argv, &param);
	if (TSS_SUCCESS != result)
	{
		return result;
	}

	// 処理実行
	result = execute(&param);

	return result;
}

/**
 * 使用方法メッセージ出力
 */
void show_usage()
{
	fprintf(stderr, "tssplitter_lite - tssplitter_lite program Ver. 0.0.0.1\n");
	fprintf(stderr, "usage: tssplitter_lite srcfile destfile sidlist\n");
	fprintf(stderr, "\n");
    fprintf(stderr, "Remarks:\n");
    fprintf(stderr, "if srcfile is '-', stdin is used for input.\n");
    fprintf(stderr, "if destfile is '-', stdout is used for output.\n");
	fprintf(stderr, "\n");
}

/**
 * パラメータ解析
 */
int AnalyzeParam(
	int argc,							// [in]		引数の個数
	char** argv,						// [in]		引数
	PARAM* param)						// [out]	引数情報データ
{
	// 引数チェック
	if ((3 != argc) && (4 != argc) && (5 != argc))
	{
		show_usage();
		return TSS_ERROR;
	}

	param->src		= argv[1];
	param->dst		= argv[2];
	if (argc > 3) {
	  param->sid = argv[3];
	}
	else {
	  param->sid = NULL;
	}

	return TSS_SUCCESS;
}

/**
 * 実処理
 */
int execute(
	PARAM* param)						// [in]		引数情報データ
{
	int sfd;							// ファイル記述子（読み込み用）
	int wfd;							// ファイル記述子（書き込み用）
	splitter *splitter = NULL;
	static splitbuf_t splitbuf;
	ARIB_STD_B25_BUFFER buf;
	int split_select_finish = TSS_ERROR;
	int code = 0;
	int wc = 0;
	int result = TSS_SUCCESS;							// 処理結果
	static uint8_t buffer[MAX_READ_SIZE];
	boolean use_stdout = TRUE;
	boolean use_stdin = TRUE;

	// 初期化
	splitter = split_startup(param->sid);
	if (splitter->sid_list == NULL) {
		fprintf(stderr, "Cannot start TS splitter\n");
		return 1;
	}

	buf.data = buffer;
	splitbuf.buffer_size = MAX_READ_SIZE;
	splitbuf.buffer = (u_char *)malloc(MAX_READ_SIZE);
	if(splitbuf.buffer == NULL) {
		fprintf(stderr, "split buffer allocation failed\n");
		return 1;
	}

	// 読み込みファイルオープン
	if(!strcmp("-", param->src)){
		sfd = 0; /* stdin */
	}else{
		sfd = open(param->src, O_RDONLY);
		if (sfd < 0){
			fprintf(stderr, "Cannot open input file: %s\n", param->src);
			result = 1;
			goto fin;
		}else
			use_stdin = FALSE;
	}

	// 書き込みファイルオープン
	if(!strcmp("-", param->dst)){
		wfd = 1; /* stdout */
	}else{
		wfd = open(param->dst, (O_RDWR | O_CREAT | O_TRUNC), 0666);
		if (wfd < 0){
			fprintf(stderr, "Cannot open output file: %s\n", param->dst);
			result = 1;
			goto fin;
		}else
			use_stdout = FALSE;
	}

	// ファイル入力
	while ((buf.size = read(sfd, buf.data, MAX_READ_SIZE)) > 0) {
		splitbuf.buffer_filled = 0;

		while(buf.size) {
			/* 分離対象PIDの抽出 */
			if(split_select_finish != TSS_SUCCESS) {
				split_select_finish = split_select(splitter, &buf);
				if(split_select_finish == TSS_NULL) {
					/* mallocエラー発生 */
					fprintf(stderr, "split_select malloc failed\n");
					result = 1;
					goto fin;
				}
				else if (split_select_finish != TSS_SUCCESS) {
//					buf.data = buffer;
					break;
				}
			}

			/* 分離対象以外をふるい落とす */
			code = split_ts(splitter, &buf, &splitbuf);
			if(code == TSS_NULL) {
				fprintf(stderr, "PMT reading..\n");
			}
			else if(code != TSS_SUCCESS) {
				//プログラム上ここには入らない fail safe
				fprintf(stderr, "split_ts failed\n");
				result = TSS_ERROR;
				goto fin;
			}
			break;
		}

		/* write data to output file */
		int size_remain = splitbuf.buffer_filled;
		int offset = 0;

		while(size_remain > 0) {
			int ws = size_remain < SIZE_CHANK ? size_remain : SIZE_CHANK;

			wc = write(wfd, splitbuf.buffer + offset, ws);
			if(wc < 0) {
				perror("write");
				result = 1;
				goto fin;
			}
			size_remain -= wc;
			offset += wc;
		}

//		buf.data = buffer;
	}
fin:
	// 開放処理
	free(splitbuf.buffer);
	split_shutdown(splitter);
	/* close output file */
	if(!use_stdout){
		fsync(wfd);
		close(wfd);
	}
	if(!use_stdin){
		close(sfd);
	}

	return result;
}


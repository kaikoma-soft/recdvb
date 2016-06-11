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
 * �����ѹ�¤��
 */
typedef struct {
	char* src;				// ���ϥե�����
	char* dst;				// ���ϥե�����
	char* sid;				// �����оݥ����ͥ��ֹ�
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
	int argc,							// [in]		�����θĿ�
	char** argv)						// [in]		����
{
	PARAM param;

	int result;							// �������

	// �ѥ�᡼������
	result = AnalyzeParam(argc, argv, &param);
	if (TSS_SUCCESS != result)
	{
		return result;
	}

	// �����¹�
	result = execute(&param);

	return result;
}

/**
 * ������ˡ��å���������
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
 * �ѥ�᡼������
 */
int AnalyzeParam(
	int argc,							// [in]		�����θĿ�
	char** argv,						// [in]		����
	PARAM* param)						// [out]	��������ǡ���
{
	// ���������å�
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
 * �½���
 */
int execute(
	PARAM* param)						// [in]		��������ǡ���
{
	int sfd;							// �ե����뵭�һҡ��ɤ߹����ѡ�
	int wfd;							// �ե����뵭�һҡʽ񤭹����ѡ�
	splitter *splitter = NULL;
	static splitbuf_t splitbuf;
	ARIB_STD_B25_BUFFER buf;
	int split_select_finish = TSS_ERROR;
	int code = 0;
	int wc = 0;
	int result = TSS_SUCCESS;							// �������
	static uint8_t buffer[MAX_READ_SIZE];
	boolean use_stdout = TRUE;
	boolean use_stdin = TRUE;

	// �����
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

	// �ɤ߹��ߥե����륪���ץ�
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

	// �񤭹��ߥե����륪���ץ�
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

	// �ե���������
	while ((buf.size = read(sfd, buf.data, MAX_READ_SIZE)) > 0) {
		splitbuf.buffer_filled = 0;

		while(buf.size) {
			/* ʬΥ�о�PID����� */
			if(split_select_finish != TSS_SUCCESS) {
				split_select_finish = split_select(splitter, &buf);
				if(split_select_finish == TSS_NULL) {
					/* malloc���顼ȯ�� */
					fprintf(stderr, "split_select malloc failed\n");
					result = 1;
					goto fin;
				}
				else if (split_select_finish != TSS_SUCCESS) {
//					buf.data = buffer;
					break;
				}
			}

			/* ʬΥ�оݰʳ���դ뤤��Ȥ� */
			code = split_ts(splitter, &buf, &splitbuf);
			if(code == TSS_NULL) {
				fprintf(stderr, "PMT reading..\n");
			}
			else if(code != TSS_SUCCESS) {
				//�ץ����夳���ˤ�����ʤ� fail safe
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
	// ��������
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


//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include "dataWorker.h"

int readText(char ** text, const char * file_path) {
	FILE * f = NULL;
	f = fopen(file_path, "r");
	if (f == NULL) {
		fprintf(stderr, "File $s don't opened!", file_path);
		return -1;
	}
	char buff[BUFF_SIZE];
	int len = 0;
	(*text) = (char *)malloc(2 * sizeof(char));
	strcpy((*text), "");
	while (!feof(f)) {
		if (fgets(buff, BUFF_SIZE, f) == NULL) {
			fprintf(stderr, "File $s can't read more!", file_path);
			break;
		}
		len += strlen(buff);
		(*text) = (char *)realloc((*text), (len + 1) * sizeof(char));
		strcat((*text), buff);
	}

	fclose(f);
	return len;
}

int writeText(char * text, const char * file_path) {
	FILE * f = NULL;
	f = fopen(file_path, "w");
	if (f == NULL) {
		fprintf(stderr, "File $s don't opened!", file_path);
		return -1;
	}

	fprintf(f, text);
	//if (fputs(text, f) == NULL) {
	//	fprintf(stderr, "File %s can't write!", file_path);
	//	return -1;
	//}

	fclose(f);
	return 1;
}

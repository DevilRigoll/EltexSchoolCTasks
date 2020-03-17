//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dataWorker.h"

int readText(char ** text, const char * file_path) {
	FILE * f = NULL;
	f = fopen(file_path, "r");
	if (f == NULL) {
		fprintf(stderr, "File %s don't opened!", file_path);
		return -1;
	}

	fseek(f, 0L, SEEK_END);
	long pos = ftell(f);
	fseek(f, 0L, SEEK_SET);

	(*text) = (char *)malloc((pos + 1) * sizeof(char));

	int i = 0;
	while (!feof(f))
		(*text)[i++] = fgetc(f);
	(*text)[pos] = '\0';

	fclose(f);
	return pos;
}

int writeText(char * text, const char * file_path) {
	FILE * f = NULL;

	f = fopen(file_path, "wb");
	if (f == NULL) {
		fprintf(stderr, "File %s don't opened!", file_path);
		return -1;
	}

	fputs(text, f);

	fclose(f);
	return 1;
}

char ** getStringsArray(char * text, int * size) {
	int len = strlen(text);
	int ssize = 0;
	for (int i = 0; i < len; ++i)
		if (text[i] == '\n' || text[i] == '\0')
			ssize++;
			

	char * t = strtok(text, "\n");
	if (t == NULL)
		return NULL;

	char ** arr_str = NULL;
	arr_str = (char **)malloc(ssize * sizeof(char *));
	arr_str[0] = t;
	for (int i = 1; i < ssize; ++i) {
		arr_str[i] = strtok(NULL, "\n");
	}

	(*size) = ssize;
	return arr_str;
}

char * getStrFromArray(char * strings[], int size) {
	char * str = NULL;
	int len = 0;

	for (int i = 0; i < size; ++i) {
		len += strlen(strings[i]) + 1;
	}

	str = (char *)malloc((len + 1) * sizeof(char));
	strcpy(str, "");
	for (int i = 0; i < size; ++i) {
		strcat(str, strings[i]);
		strcat(str, "\n");
	}
	return str;
}

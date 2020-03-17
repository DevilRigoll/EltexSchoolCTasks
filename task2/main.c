//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "dataWorker.h"
#include "shellsort.h"

void parse_param(int argc, char * argv[]) {
	setlocale(LC_ALL, "Russian");
	char in_path[256];
	char out_path[256];
	char symbols_path[256];

	char * text = NULL;

	switch (argc) {
	case 1: {
		puts("Enter path to input file:");
		scanf("%s", in_path);
		puts("Enter path to output file:");
		scanf("%s", out_path);
		break;
	}
	case 2: {
		strcpy(in_path, argv[1]);
		puts("Enter path to output file:");
		scanf("%s", out_path);
		break;
	}
	case 3: {
		strcpy(in_path, argv[1]);
		strcpy(out_path, argv[2]);
		break;
	}
	}

	int len = readText(&text, in_path);
	if (len < 0) {
		fprintf(stderr, "Can't read this file %s", in_path);
		exit(0);
	}
	int size = 0;


	char ** strings = getStringsArray(text, &size);

	ShellSort(&strings, size);

	char * res_text = getStrFromArray(strings, size);
	int res = writeText(res_text, out_path);

	free(res_text);
	free(text);
	//for (int i = 0; i < size; ++i)
	//	free(strings[i]);
	free(strings);
}

int main(int argc, char * argv[]) {
	parse_param(argc, argv);
	return 0;
}

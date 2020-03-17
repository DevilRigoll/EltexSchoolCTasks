//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>


void parse_param(int argc, char * argv[]) {
	//setlocale(LC_ALL, "Russian");
	char in_path[256];
	char out_path[256];
	char symbols_path[256];

	char * text = NULL;
	char * symbols = NULL;

	switch (argc) {
	case 1: {
		puts("Enter path to input file:");
		scanf("%s", &in_path);
		puts("Enter path to output file:");
		scanf("%s", &out_path);
		puts("Enter path to special symbol file:");
		scanf("%s", &symbols_path);
		break;
	}
	case 2: {
		strcpy(in_path, argv[1]);
		puts("Enter path to output file:");
		scanf("%s", &out_path);
		puts("Enter path to special symbol file:");
		scanf("%s", &symbols_path);
		break;
	}
	case 3: {
		strcpy(in_path, argv[1]);
		strcpy(out_path, argv[2]);
		puts("Enter path to special symbol file:");
		scanf("%s", &symbols_path);
		break;
	}
	case 4: {
		strcpy(in_path, argv[1]);
		strcpy(out_path, argv[2]);
		strcpy(symbols_path, argv[3]);
		break;
	}
	}

	int len = readText(&symbols, symbols_path);
	if (len < 0) {
		fprintf(stderr, "Can't read this file %s", in_path);
		exit(0);
	}

	len = readText(&text, in_path);
	if (len < 0) {
		fprintf(stderr, "Can't read this file %s", in_path);
		exit(0);
	}
	char * res_text = encrypt(text, len, symbols);

	int res = writeText(res_text, out_path);

	free(res_text);
	free(symbols);
	free(text);
}


int main(int argc, char * argv[]) {
	parse_param(argc, argv);
	return 0;
}

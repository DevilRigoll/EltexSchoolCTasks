//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


#include "dataWorker.h"
#include "list.h"

#include "data.h"

const char * specSymbols = "][.-,!?;)(+*:\"'/@#$%^}{<>|»«\\";
int isSpecSymbol(char c) {
	int len = strlen(specSymbols);
	for (int i = 0; i < len; ++i)
		if (c == specSymbols[i])
			return 1;
	return 0;
}

int SpecSymbolsCount(char * str) {
	int len = strlen(str);
	int count = 0;

	for (int i = 0; i < len; ++i)
		if (isSpecSymbol(str[i]))
			count++;
	return count;
}

void listprint(struct list * lst) {
	struct list *p;
	p = lst;
	do {
		printf("%d \n", p->field.SpecSymbolsCount);
		puts(p->field.str);
		puts("\n");
		p = p->next;
	} while (p != NULL);
}

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

	struct Data d;
	d.SpecSymbolsCount = SpecSymbolsCount(strings[0]);
	d.str = strings[0];
	struct list * lst = listinit(d);
	struct list * p = lst;
	for (int i = 1; i < size; ++i) {
		d.SpecSymbolsCount = SpecSymbolsCount(strings[i]);
		d.str = strings[i];
		p = addelem(p, d);
	}

	//struct list * res = sort(lst);

	char * res_text = getStrFromList(lst);

	int res_c = writeText(res_text, out_path);

	p = lst;
	while (p != NULL)
		p = deletehead(p);

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

#include <stdlib.h>
#include <string.h>

#include "shellsort.h"

const char * specSymbols = ".–,!?;)(+*:\"'@#$%^[]}{<>|\\";

int isSpecSymbol(char c) {
	int len = strlen(specSymbols);
	for (int i = 0; i < len; ++i)
		if (c == specSymbols[i])
			return 1;
	return 0;
}

int wordCount(char string[]) {
	int len = strlen(string);
	int count = 0;
	for (int i = 0; i < len; ++i) {
		int word_len = 0;
		while (string[i] != ' ' && i < len) {
			i++;
			word_len++;
		}
		if (word_len == 1 && isSpecSymbol(string[i - 1]))
			continue;
		if (word_len != 0)
			count++;
	}
	return count;
}

void ShellSort(char ** strings[], int size) {
	for (int step = size / 2; step > 0; step /= 2)
		for (int i = step; i < size; i++)
			for (int j = i - step; j >= 0 && wordCount((*strings)[j]) > wordCount((*strings)[j + step]); j -= step) {
				char * tmp = (*strings)[j];
				(*strings)[j] = (*strings)[j + step];
				(*strings)[j + step] = tmp;
			}
}

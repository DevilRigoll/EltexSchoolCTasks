#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * encrypt(char * text, const int size, const char * spec_symbols) {

	int len = strlen(spec_symbols);
	if (len & 1) {
		fprintf(stderr, "Spec symbol isn't even\n");
		return NULL;
	}

	char * res_str = (char *)malloc(size * sizeof(char));

	for (int i = 0; i < size; ++i) {
		if (text[i] >= 'a' && text[i] <= 'z')
			res_str[i] = 'z' - 25 + 'z' - text[i];
		else if (text[i] >= 'A' && text[i] <= 'Z')
			res_str[i] = 'Z' - 25 + 'Z' - text[i];
		else if (text[i] >= 'à' && text[i] <= 'ÿ')
			res_str[i] = 'ÿ' - 31 + 'ÿ' - text[i];
		else if (text[i] >= 'À' && text[i] <= 'ß')
			res_str[i] = 'ß' - 31 + 'ß' - text[i];
		else {
			int id = 0;
			while (id < len && spec_symbols[id] != text[i])  id++;
			if (id == len) {
				res_str[i] = text[i];
				continue;
			}
			res_str[i] = id & 1 ? spec_symbols[id - 1] : spec_symbols[id + 1];
		}
	}
	return res_str;
}

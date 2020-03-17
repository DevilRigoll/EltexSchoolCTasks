#ifndef MY_DATA_WORKER
#define MY_DATA_WORKER

int readText(char ** text, const char * file_path);
int writeText(char * text, const char * file_path);
char ** getStringsArray(char * text, int * size);
char * getStrFromArray(char * strings[], int size);
#endif

#ifndef MY_DATA_WORKER
#define MY_DATA_WORKER

#define BUFF_SIZE 1024


int readText(char ** text, const char * file_path);
int writeText(char * text, const char * file_path);

#endif
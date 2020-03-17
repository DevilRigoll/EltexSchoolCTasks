#ifndef MY_LIST
#define MY_LIST

#include "data.h"

struct list {
	struct Data field; 
	struct list *next; 
	struct list *prev;
};

struct list * listinit(struct Data);
struct list * addelem(struct list *lst, struct Data);
struct list * deletelem(struct list * lst);
struct list * deletehead(struct list * root);
struct list * sort(struct list * lst);
char * getStrFromList(struct list * lst);
#endif

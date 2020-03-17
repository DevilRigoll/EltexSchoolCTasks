#include "list.h"

#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct list * listinit(struct Data field) {
	struct list * lst;
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = field;
	lst->next = NULL;
	lst->prev = NULL;
	return(lst);
}

struct list * addelem(struct list *lst, struct Data elem) {		
	struct list * curr = (struct list*)malloc(sizeof(struct list));
	curr->field = elem;
	if (elem.SpecSymbolsCount > lst->field.SpecSymbolsCount) {
		struct list * p = lst;
		while (p->next != NULL) {
			if (p->next->field.SpecSymbolsCount > elem.SpecSymbolsCount)
				break;
			p = p->next;
		}
		curr->next = p->next;
		curr->prev = p;
		p->next = curr; 
	} else {
		struct list * p = lst;
                while (p != NULL) {
                        if (p->field.SpecSymbolsCount < elem.SpecSymbolsCount)
                                break;
                        p = p->prev;
                }
                curr->next = p->next;
                curr->prev = p;
                p->next = curr;

	}
	
	
	return curr; 
	
}

struct list * deletehead(struct list * root) {
	struct list *temp;
	temp = root->next;
	if (temp != NULL)
		temp->prev = NULL;
	free(root);   
	return(temp); 
}

char * getStrFromList(struct list * lst) {
	char * str = NULL;
	int len = 0;

	for (struct list * p = lst; p != NULL; p = p->next) {
		len += strlen(p->field.str) + 1;
	}

	str = (char *)realloc(str, (len + 2) * sizeof(char));
	strcpy(str, "");
	for (struct list * p = lst; p != NULL; p = p->next) {
		strcat(str, p->field.str);
		strcat(str, "\n");
	}

	return str;
}

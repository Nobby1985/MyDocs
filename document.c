/*
 * document.c
 *
 *  Created on: 09.06.2011
 *      Author: pascal
 */

#include "document.h"

int compare_id(struct document* d, struct document* dd) {
	if(d->id < dd->id)
		return -1;
	if(d->id > dd->id)
		return 1;
	else
		return 0;
}

struct document* new_document(int id, char* path) {
	struct document* doc = (struct document*)malloc(sizeof(struct document));
	doc->id = id;
	doc->path = path;

	return doc;
}

void print_doc(struct document* d) {
	printf("%d, %s\n", d->id, d->path);
}

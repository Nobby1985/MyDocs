/*
 * document_tree.h
 *
 *  Created on: 09.06.2011
 *      Author: pascal
 */

#ifndef DOCUMENT_TREE_H_
#define DOCUMENT_TREE_H_
#include "types.h"

struct document_node {
	struct document* d;
	struct document_node* left;
	struct document_node* right;
	int (*compare)(struct document*, struct document*);
};

void for_each_inorder(struct document_node*, void (*f)(struct document*));
void document_tree_insert(struct document_node** l, struct document* d, int (*cmp)(struct document*, struct document*));

#endif /* DOCUMENT_TREE_H_ */

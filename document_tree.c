/*
 * document_tree.c
 *
 *  Created on: 09.06.2011
 *      Author: pascal
 */
#include "document_tree.h"

void document_tree_insert(struct document_node** l, struct document* d, int (*cmp)(struct document*, struct document*)) {
	if(*l == NULL) {
		*l = (struct document_node*)malloc(sizeof(struct document_node));
		(*l)->d = d;
		(*l)->left = NULL;
		(*l)->right = NULL;
		(*l)->compare = cmp;
	} else {
		if((*l)->compare(d, (*l)->d) > 0) {
			document_tree_insert(&(*l)->right, d, cmp);
		}

		if((*l)->compare(d, (*l)->d) < 0) {
			document_tree_insert(&(*l)->left, d, cmp);
		}
	}
}




void for_each_inorder(struct document_node* n, void (*f)(struct document*)) {
	if(n->left != NULL)
		for_each_inorder(n->left, f);

	if(n != NULL)
		f(n->d);

	if(n->right != NULL)
		for_each_inorder(n->right, f);
}

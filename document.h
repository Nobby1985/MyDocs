/*
 * document.h
 *
 *  Created on: 09.06.2011
 *      Author: pascal
 */

#ifndef DOCUMENT_H_
#define DOCUMENT_H_
#include <stdio.h>
#include "types.h"

int compare_id(struct document*, struct document*);
struct document* new_document(int, char*);
void print_doc(struct document*);
#endif /* DOCUMENT_H_ */

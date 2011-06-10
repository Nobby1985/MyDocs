#include<stdio.h>
#include<stdlib.h>
#include <sqlite3.h>
#include "types.h"
#include "document.h"
#include "document_tree.h"
#include "db.h"


int main(int argc, char** argv) {
	
	db_open();
	//printf("%p\n", db);
	db_create(db);
	//printf("%p\n", db);

	struct document_node* root = db_get_all_documents();

	close_db();

	for_each_inorder(root, &print_doc);
	
	sqlite3_close(db);

	return EXIT_SUCCESS;
}


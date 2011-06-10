/*
 * db.h
 *
 *  Created on: 09.06.2011
 *      Author: pascal
 */

#ifndef DB_H_
#define DB_H_
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "types.h"
#include "document.h"
#include "document_tree.h"


sqlite3* db;

int db_open();
void close_db();
void db_create(sqlite3* db);
void db_insert_document(struct document*);
void db_insert_recipient(struct recipient*);

struct document_node* db_get_all_documents();

// TODO: implement missing fuctions
void db_insert_address(struct address*);
void db_insert_category(struct category*);
void db_insert_contact(struct contact*);


struct recipient** db_get_all_recipients();
struct address** db_get_all_addresses();
struct category** db_get_all_categories();
struct contact** db_get_all_contacts();


#endif /* DB_H_ */

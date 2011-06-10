/*
 * db.c
 *
 *  Created on: 09.06.2011
 *      Author: pascal
 */
#include "db.h"

int db_open() {
	if(sqlite3_open("docs.db", &db) != SQLITE_OK) {
					printf("Fehler beim öffnen von DB\n");
					return 0;
				}

	return 1;
}

void close_db() {

}

void db_create(sqlite3* db) {
	char* err;

	if(sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS documents (id integer primary key autoincrement, path text);",  NULL, NULL, &err) != SQLITE_OK) {
		printf("Fehler beim erstellen von documents: %s\n", err);
		sqlite3_free(err);
	}

	if(sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS recipients (id integer primary key autoincrement, firstname text, lastname text, company text, address integer, contact integer);", NULL, NULL, &err) != SQLITE_OK) {
		printf("Fehler beiim erstellen von recipients: %s\n", err);
		sqlite3_free(err);
	}

	if(sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS addresses (id integer primary key autoincrement, street text, number text, zip text, city text);", NULL, NULL, &err) != SQLITE_OK) {
		printf("fehler beim erstellen von addresses: %s\n", err);
		sqlite3_free(err);
	}

	if(sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS categories (id integer primary key autoincrement, name text);", NULL, NULL, &err) != SQLITE_OK) {
		printf("Fehler beim erstellen von categories: %s\n", err);
		sqlite3_free(err);
	}
}

void db_insert_document(struct document* doc) {
	sqlite3_stmt* st;

	sqlite3_prepare_v2(db, "INSERT INTO documents(path) VALUES (?);", -1, &st, NULL);
	sqlite3_bind_text(st, 1, doc->path, -1, SQLITE_STATIC);
	sqlite3_step(st);

	sqlite3_finalize(st);
}

void db_insert_recipient(struct recipient* rec) {
	sqlite3_stmt* st;

	sqlite3_prepare_v2(db, "INSERT INTO recipients (firstname, lastname, company, address, contact) VALUES (?, ?, ?, ?, ?);", -1, &st, NULL);
	sqlite3_bind_text(st, 1, rec->firstname, -1, SQLITE_STATIC);
	sqlite3_bind_text(st, 2, rec->lastname, -1, SQLITE_STATIC);
	sqlite3_bind_text(st, 3, rec->company, -1, SQLITE_STATIC);
	sqlite3_bind_int(st, 4, rec->add->id);
	sqlite3_bind_int(st, 5, rec->con->id);
	sqlite3_step(st);

	sqlite3_finalize(st);
}

struct document_node* db_get_all_documents() {
		struct document_node* root;
		sqlite3_stmt* st;

		if(sqlite3_prepare_v2(db, "SELECT id, path FROM documents;", -1, &st, NULL) != SQLITE_OK) {
			printf("Fehler bei prepare\n");
			return NULL;
		}

		sqlite3_reset(st);
		while(sqlite3_step(st) == SQLITE_ROW) {
			int i, n;
			const char* s;
			if(sqlite3_column_int(st, 0))
				i = sqlite3_column_int(st, 0);
			else
				continue;
			if(sqlite3_column_text(st,1)) {
				s = (const char*)sqlite3_column_text(st,1);
				n = sqlite3_column_bytes(st, 1);
			}
			else
				continue;

			struct document* d = new_document(0, NULL);
			d->id = i;
			d->path = (char*)malloc(n*sizeof(char));
			strcpy(d->path, s);
			document_tree_insert(&root, d, &compare_id);
		}
		sqlite3_reset(st);

		return root;
}

struct recipient** db_get_all_recipients() {
	return NULL;
}

struct address** db_get_all_addresses() {
	return NULL;
}

struct category** db_get_all_categories() {
	return NULL;
}

struct contact** db_get_all_contacts() {
	return NULL;
}

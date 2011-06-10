/*
 * types.h
 *
 *  Created on: 09.06.2011
 *      Author: pascal
 */

#ifndef TYPES_H_
#define TYPES_H_
#include <time.h>

struct address {
	int id;
	char* street;
	char* number;
	char* zip;
	char* city;
};

struct contact {
	int id;
	char* phonenumber;
	char* faxnumber;
	char* email;
	char* website;
};

struct recipient {
	char* firstname;
	char* lastname;
	char* company;
	struct address* add;
	struct contact* con;
};

struct category {
	int id;
	char* name;
};

struct document {
	int id;
	char* path;
	time_t doc_date;
	struct recipient* rec;
	struct recipient* sen;
	struct category* cat;
};


#endif /* TYPES_H_ */

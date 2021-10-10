#ifndef BINSEARCH_H
#define BINSEARCH_H

#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 20 

typedef char KeyType;
typedef int OtherType;

typedef struct
{
	KeyType 	key;
	OtherType 	other_data;
}RecordType;

typedef struct
{
	RecordType	r[LIST_SIZE+1];
	int 		length;
}RecordList;

void createlist_(RecordList *l);

int BinSrch(RecordList l, KeyType  k);

#endif // END BINSEARCH_H

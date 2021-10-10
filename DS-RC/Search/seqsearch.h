#ifndef SEQSEARCH_H
#define SEQSEARCH_H

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
	int			length;
}RecordList;

void createlist(RecordList *l);

int SeqSearch(RecordList l, KeyType  k);

int SeqSearch2(RecordList l, KeyType k);

#endif // END SEQSEARCH_H

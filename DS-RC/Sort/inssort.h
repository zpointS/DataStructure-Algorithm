#ifndef INSSORT_H
#define INSSORT_H

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int OtherType;

typedef struct
{
	KeyType 	key;
	OtherType 	other_data;
}RecordType;

void InsSort(RecordType  r[],  int length);

#endif // END INSSORT_H

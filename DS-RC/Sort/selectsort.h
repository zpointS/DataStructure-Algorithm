#ifndef SELECTSORT_H
#define SELECTSORT_H

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int OtherType;

typedef struct
{
	KeyType 	key;
	OtherType 	other_data;
}RecordType;

void  SelectSort(RecordType r[], int length);

#endif // END SELECTSORT_H

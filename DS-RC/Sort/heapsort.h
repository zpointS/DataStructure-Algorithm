#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE 	1
#define FALSE 	0

typedef int KeyType;
typedef int OtherType;

typedef struct
{
	KeyType 	key;
	OtherType 	other_data;
}RecordType;

void sift(RecordType  r[],  int k, int m);

void crt_heap(RecordType r[], int length );

void HeapSort(RecordType  r[],int length);

#endif // END HEAPSORT_H

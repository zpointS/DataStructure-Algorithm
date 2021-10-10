#ifndef MERGE_H
#define MERGE_H

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int OtherType;

typedef struct
{
	KeyType 	key;
	OtherType 	other_data;
}RecordType;

void Merge(RecordType r1[], int low, int mid, int high, RecordType  r2[]);

void MSort(RecordType r1[], int low, int high, RecordType r3[]);

void MergeSort(RecordType r[], int n );

#endif // END MERGE_H

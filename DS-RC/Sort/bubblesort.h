#ifndef BUBBLESORT_H
#define BUBBLESORT_H

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

void BubbleSort(RecordType r[], int length );

#endif // END BUBBLESORT_H 

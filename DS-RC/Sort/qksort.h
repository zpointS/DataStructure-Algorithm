#ifndef QKSORT_H
#define QKSORT_H

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int OtherType;

typedef struct
{
	KeyType 	key;
	OtherType 	other_data;
}RecordType;

int  QKPass(RecordType r[],int left,int right);

void QKSort(RecordType r[],int low, int high );

#endif // END QKSORT_H

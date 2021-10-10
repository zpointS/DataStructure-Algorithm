#ifndef BINSORT_H
#define BINSORT_H

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int OtherType;

typedef struct
{
	KeyType 	key;
	OtherType 	other_data;
}RecordType;

void BinSort (RecordType  r[], int length);

#endif // END BINSORT_H

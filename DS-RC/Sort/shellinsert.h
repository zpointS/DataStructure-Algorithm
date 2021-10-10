#ifndef SHELLINSERT_H
#define SHELLINSERT_H

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int OtherType;

typedef struct
{
	KeyType 	key;
	OtherType 	other_data;
}RecordType;

void ShellInsert(RecordType r[], int length,  int  delta);

void ShellSort(RecordType r[], int length, int delt[], int n);

#endif // END SHELLINSERT_H

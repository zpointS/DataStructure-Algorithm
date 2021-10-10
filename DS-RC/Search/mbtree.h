#ifndef MBTREE_H
#define MBTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define  m  3
//#define NULL 0
#define TRUE 1
#define true 1
#define false 0
typedef	int  Boolean; 
typedef int KeyType;

typedef	struct Mbtnode 
{
	struct Mbtnode	*parent;
	int  			keynum;
	KeyType  		key[m+1];
	struct Mbtnode  *ptr[m+1];
} Mbtnode, *Mbtree;

void insert(Mbtree mbp,	int ipos, 	KeyType key,  Mbtree rp);

void split(Mbtree oldp, Mbtree *newp);

int  search(Mbtree  mbt, KeyType  key );

void ins_mbtree(Mbtree *mbt, KeyType  k,  Mbtree q,  int  i);

void Creatembtree(Mbtree *mbt);

Boolean srch_mbtree (Mbtree  mbt, KeyType k, Mbtree *np, int *pos);

#endif // END MBTREE_H

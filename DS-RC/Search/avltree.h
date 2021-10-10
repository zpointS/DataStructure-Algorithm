#ifndef AVLTREE_H
#define AVLTREE_H

#include <stdio.h>
#include <stdlib.h>

#define ENDKEY 0

typedef int KeyType;

typedef struct  node
{
	KeyType  	key ; /*关键字的值*/
	int 		bf;
	struct node *lchild; 
	struct node *rchild;/*左右指针*/
}AVLTNode, *AVLTree;

void  ins_AVLtree(AVLTree  *avlt ,  KeyType  K);

void  CreateAVLT(AVLTree  *bst);

void  PreOrder_(AVLTree root);

#endif // END AVLTREE_H


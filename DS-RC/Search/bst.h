#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

#define ENDKEY 0

typedef int KeyType;

typedef struct  node
{
	KeyType  	key ; /*关键字的值*/
	struct node *lchild;
	struct node *rchild;/*左右指针*/
}BSTNode, *BSTree;

void InsertBST(BSTree *bst, KeyType key);

void  CreateBST(BSTree  *bst);

void  PreOrder(BSTree root);

BSTree  SearchBST(BSTree bst, KeyType key);

BSTNode  * DelBST(BSTree t, KeyType  k);

#endif // END BST_H

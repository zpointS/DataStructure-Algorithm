#include <stdio.h>
#include <malloc.h>
#include <conio.h>

typedef char DataType;

typedef struct Node
{
	DataType	data;
	int      	Ltag;
	int      	Rtag;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode, *BiTree;

BiTree pre;

void CreateBiTree(BiTree *bt);

void  Inthread(BiTree root);

BiTNode * InPre(BiTNode *p);

BiTNode * InNext(BiTNode * p);

BiTNode* TinFirst(BiTree root);

void TinOrder(BiTree root);

void InsNode(BiTNode *p ,  BiTNode *r);

#ifndef BITREE_H
#define BITREE_H

#define TRUE 		1
#define FALSE 		0
#define ERROR 		0
#define OK    		1
#define NUM 		50
#define Stack_Size 	50
#define MAXSIZE 	50  /*队列的最大长度*/

typedef char DataType;

typedef struct Node
{
	DataType      data;
	struct Node * lchild;
	struct Node * rlhild;
}BiTNode, *BiTree;

typedef BiTree QueueElementType;
typedef BiTree StackElementType;

typedef struct
{
	QueueElementType 	element[MAXSIZE];  /* 队列的元素空间*/
	int					front;             /*头指针指示器*/
	int					rear;              /*尾指针指示器*/
}SeqQueue;

typedef struct
{
	StackElementType	elem[Stack_Size]; /*用来存放栈中元素的一维数组*/
	int					top;          	  /*用来存放栈顶元素的下标，top为-1表示空栈*/
}SeqStack;



/* *************** 树相关操作 ********************** */ 
void CreateBiTree(BiTree *bt);

void Visit(char ch);

void  PreOrder(BiTree root);

void  InOrder(BiTree root);

void  PostOrder(BiTree root);

void  PreOrderLeaves(BiTree root);

int LeafCount(BiTree root);

int LeafCountNonRecursion(BiTree root); 

int PostTreeDepth(BiTree bt);

int PreTreeDepth(BiTree bt, int h);

void PrintTree(BiTree bt,int nLayer);

void InOrderNonRecursion1(BiTree root);

void InOrderNonRecursion2(BiTree root);

void PostOrderNonRecursion(BiTree root);

int  LayerOrder(BiTree bt);

/* *************** 队列相关操作 ********************** */ 
void InitQueue(SeqQueue *Q);

int EnterQueue(SeqQueue *Q, QueueElementType x);

int DeleteQueue(SeqQueue *Q, QueueElementType *x);

int IsEmpty(SeqQueue *Q);

/* *************** 栈相关操作 ********************** */ 
void InitStack(SeqStack *S);

int IsStackEmpty(SeqStack *S);

int IsFull(SeqStack *S);

int Push(SeqStack *S,StackElementType x);

int Pop(SeqStack *S,StackElementType *x);

#endif // END BITREE_H 

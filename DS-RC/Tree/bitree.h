#ifndef BITREE_H
#define BITREE_H

#define TRUE 		1
#define FALSE 		0
#define ERROR 		0
#define OK    		1
#define NUM 		50
#define Stack_Size 	50
#define MAXSIZE 	50  /*���е���󳤶�*/

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
	QueueElementType 	element[MAXSIZE];  /* ���е�Ԫ�ؿռ�*/
	int					front;             /*ͷָ��ָʾ��*/
	int					rear;              /*βָ��ָʾ��*/
}SeqQueue;

typedef struct
{
	StackElementType	elem[Stack_Size]; /*�������ջ��Ԫ�ص�һά����*/
	int					top;          	  /*�������ջ��Ԫ�ص��±꣬topΪ-1��ʾ��ջ*/
}SeqStack;



/* *************** ����ز��� ********************** */ 
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

/* *************** ������ز��� ********************** */ 
void InitQueue(SeqQueue *Q);

int EnterQueue(SeqQueue *Q, QueueElementType x);

int DeleteQueue(SeqQueue *Q, QueueElementType *x);

int IsEmpty(SeqQueue *Q);

/* *************** ջ��ز��� ********************** */ 
void InitStack(SeqStack *S);

int IsStackEmpty(SeqStack *S);

int IsFull(SeqStack *S);

int Push(SeqStack *S,StackElementType x);

int Pop(SeqStack *S,StackElementType *x);

#endif // END BITREE_H 

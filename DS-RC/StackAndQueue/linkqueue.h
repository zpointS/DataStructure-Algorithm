#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define  TRUE 1
#define  FALSE 0

#define MAXSIZE 50  /*���е���󳤶�*/

typedef char QueueElementType;
 
typedef struct Node
{
	QueueElementType	data;     /*������*/
	struct Node			*next;     /*ָ����*/
}LinkQueueNode;

typedef struct 
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;

/*��ʼ��������*/
int LQInitQueue(LinkQueue *Q);

/*��Ӳ�����*/
int LQEnterQueue(LinkQueue *Q,QueueElementType x);

/*���Ӳ�����*/
int LQDeleteQueue(LinkQueue *Q,QueueElementType *x);

int LQGetHead(LinkQueue *Q, QueueElementType *x);

#endif // end LINKQUEUE_H

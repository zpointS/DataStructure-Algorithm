#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define  TRUE 1
#define  FALSE 0

#define MAXSIZE 50  /*队列的最大长度*/

typedef char QueueElementType;
 
typedef struct Node
{
	QueueElementType	data;     /*数据域*/
	struct Node			*next;     /*指针域*/
}LinkQueueNode;

typedef struct 
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;

/*初始化操作。*/
int LQInitQueue(LinkQueue *Q);

/*入队操作。*/
int LQEnterQueue(LinkQueue *Q,QueueElementType x);

/*出队操作。*/
int LQDeleteQueue(LinkQueue *Q,QueueElementType *x);

int LQGetHead(LinkQueue *Q, QueueElementType *x);

#endif // end LINKQUEUE_H

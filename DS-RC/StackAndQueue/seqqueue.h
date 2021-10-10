#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define  TRUE		1
#define  FALSE		0
#define MAXSIZE		50  /*队列的最大长度*/

typedef char QueueElementType;

typedef struct
{
	QueueElementType 	element[MAXSIZE];  /* 队列的元素空间*/
	int					front;  /*头指针指示器*/
	int					rear;  /*尾指针指示器*/
}SeqQueue;

/*初始化操作*/
void InitQueue(SeqQueue *Q);

/*入队操作*/
int EnterQueue(SeqQueue *Q, QueueElementType x);

/*出队操作*/
int DeleteQueue(SeqQueue *Q, QueueElementType *x);

int GetHead(SeqQueue *Q, QueueElementType *x);

int IsEmpty(SeqQueue *Q);

#endif // END SEQQUEUE_H

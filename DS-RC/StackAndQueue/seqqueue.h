#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define  TRUE		1
#define  FALSE		0
#define MAXSIZE		50  /*���е���󳤶�*/

typedef char QueueElementType;

typedef struct
{
	QueueElementType 	element[MAXSIZE];  /* ���е�Ԫ�ؿռ�*/
	int					front;  /*ͷָ��ָʾ��*/
	int					rear;  /*βָ��ָʾ��*/
}SeqQueue;

/*��ʼ������*/
void InitQueue(SeqQueue *Q);

/*��Ӳ���*/
int EnterQueue(SeqQueue *Q, QueueElementType x);

/*���Ӳ���*/
int DeleteQueue(SeqQueue *Q, QueueElementType *x);

int GetHead(SeqQueue *Q, QueueElementType *x);

int IsEmpty(SeqQueue *Q);

#endif // END SEQQUEUE_H

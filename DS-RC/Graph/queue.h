#ifndef QUEUE_H
#define QUEUE_H

#define NULL 0
#define True 1
#define False 0

typedef struct Node
{
	int data;
	struct Node *next;
}LinkQueueNode;

typedef struct
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;

int InitQueue(LinkQueue *Q);

int EnterQueue(LinkQueue *Q,int x);

int DeleteQueue(LinkQueue *Q,int *x);

int IsEmpty(LinkQueue *Q);

#endif // QUEUE_H

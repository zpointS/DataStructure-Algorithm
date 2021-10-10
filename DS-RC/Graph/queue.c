#include "queue.h"

int InitQueue(LinkQueue *Q)
{
	Q->front=(LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if(Q->front!=NULL)
	{
		Q->rear=Q->front;
		Q->front->next=NULL;
		return(True);
	}
	else  
		return(False);
}

int EnterQueue(LinkQueue *Q,int x)
{
	LinkQueueNode *NewNode;
	NewNode=(LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if(NewNode!=NULL)
	{
		NewNode->data=x;
		NewNode->next=NULL;
		Q->rear->next=NewNode;
		Q->rear=NewNode;
		return(True);
	}
	else 
		return(False);
}

int DeleteQueue(LinkQueue *Q,int *x)
{
	LinkQueueNode *p;
	if(Q->front==Q->rear)
		return(False);
	p=Q->front->next;
	Q->front->next=p->next;
    if(Q->rear==p)
		Q->rear=Q->front;
	*x=p->data;
	free(p);
	return(True);
}

int IsEmpty(LinkQueue *Q)
{
	if(Q->front==Q->rear)
		return(True);
	else 
		return(False);
}

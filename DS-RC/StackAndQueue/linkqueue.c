#include "linkqueue.h"

/*初始化操作。*/
int LQInitQueue(LinkQueue *Q)
{ 
	Q->front=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(Q->front!=NULL)
	{
		Q->rear=Q->front;
		Q->front->next=NULL;
 		return(TRUE);
	}
	else return(FALSE);    /* 溢出！*/
}

/*入队操作。*/
int LQEnterQueue(LinkQueue *Q,QueueElementType x)
{  
	/* 将数据元素x插入到队列Q中 */
	LinkQueueNode *NewNode;
	NewNode=(LinkQueueNode * )malloc(sizeof(LinkQueueNode));
	if(NewNode!=NULL)
	{
		NewNode->data=x;
		NewNode->next=NULL;
		Q->rear->next=NewNode;
		Q->rear=NewNode;
		return(TRUE);
	}
	else 
	{
		return(FALSE);    /* 溢出！*/
	} 
}

/* 将队列Q的队头元素出队，并存放到x所指的存储空间中 */
int LQDeleteQueue(LinkQueue *Q,QueueElementType *x)
{  
	
	LinkQueueNode * p;
	if(Q->front==Q->rear)
	{
		return(FALSE);
	}	
	p=Q->front->next;
	Q->front->next=p->next;  /* 队头元素p出队 */
	if(Q->rear==p)  /* 如果队中只有一个元素p，则p出队后成为空队 */
	{
		Q->rear=Q->front;  
	}	
	*x=p->data;
	free(p);   /* 释放存储空间 */
	
	return(TRUE);	
}

/*提取队列的队头元素，用x返回其值*/
int LQGetHead(LinkQueue *Q, QueueElementType *x)
{ 	
	if(Q->front==Q->rear)  /*队列为空*/
	{
		return(FALSE);
	}	
	*x=Q->front->next->data;
	
	return(TRUE);  /*操作成功*/
}

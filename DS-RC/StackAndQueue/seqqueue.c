#include "seqqueue.h"

/*初始化操作*/
void InitQueue(SeqQueue *Q)
{  
	Q->front=Q->rear=0;
}

/*将元素x入队*/
int EnterQueue(SeqQueue *Q, QueueElementType x)
{  
	
	if((Q->rear+1)%MAXSIZE==Q->front)  /*队列已经满了*/
		return(FALSE);
	Q->element[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;  /* 重新设置队尾指针 */
	return(TRUE);  /*操作成功*/
}

/*删除队列的队头元素，用x返回其值*/
int DeleteQueue(SeqQueue *Q, QueueElementType *x)
{ 
	
	if(Q->front==Q->rear)  /*队列为空*/
		return(FALSE);
	*x=Q->element[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;  /*重新设置队头指针*/
	return(TRUE);  /*操作成功*/
}

/*提取队列的队头元素，用x返回其值*/
int GetHead(SeqQueue *Q, QueueElementType *x)
{ 
	if(Q->front==Q->rear)  /*队列为空*/
	{
		return(FALSE);
	}	
	*x=Q->element[Q->front];
	
	return(TRUE);  /*操作成功*/
}

int IsEmpty(SeqQueue *Q)
{ 
	if(Q->front==Q->rear)  /*队列为空*/
	{
		return(TRUE);
	}	
	else
	{
		return(FALSE);  /*操作成功*/
	}	
}


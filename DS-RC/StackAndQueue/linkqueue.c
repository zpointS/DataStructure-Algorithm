#include "linkqueue.h"

/*��ʼ��������*/
int LQInitQueue(LinkQueue *Q)
{ 
	Q->front=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(Q->front!=NULL)
	{
		Q->rear=Q->front;
		Q->front->next=NULL;
 		return(TRUE);
	}
	else return(FALSE);    /* �����*/
}

/*��Ӳ�����*/
int LQEnterQueue(LinkQueue *Q,QueueElementType x)
{  
	/* ������Ԫ��x���뵽����Q�� */
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
		return(FALSE);    /* �����*/
	} 
}

/* ������Q�Ķ�ͷԪ�س��ӣ�����ŵ�x��ָ�Ĵ洢�ռ��� */
int LQDeleteQueue(LinkQueue *Q,QueueElementType *x)
{  
	
	LinkQueueNode * p;
	if(Q->front==Q->rear)
	{
		return(FALSE);
	}	
	p=Q->front->next;
	Q->front->next=p->next;  /* ��ͷԪ��p���� */
	if(Q->rear==p)  /* �������ֻ��һ��Ԫ��p����p���Ӻ��Ϊ�ն� */
	{
		Q->rear=Q->front;  
	}	
	*x=p->data;
	free(p);   /* �ͷŴ洢�ռ� */
	
	return(TRUE);	
}

/*��ȡ���еĶ�ͷԪ�أ���x������ֵ*/
int LQGetHead(LinkQueue *Q, QueueElementType *x)
{ 	
	if(Q->front==Q->rear)  /*����Ϊ��*/
	{
		return(FALSE);
	}	
	*x=Q->front->next->data;
	
	return(TRUE);  /*�����ɹ�*/
}

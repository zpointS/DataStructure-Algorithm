#include "seqqueue.h"

/*��ʼ������*/
void InitQueue(SeqQueue *Q)
{  
	Q->front=Q->rear=0;
}

/*��Ԫ��x���*/
int EnterQueue(SeqQueue *Q, QueueElementType x)
{  
	
	if((Q->rear+1)%MAXSIZE==Q->front)  /*�����Ѿ�����*/
		return(FALSE);
	Q->element[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;  /* �������ö�βָ�� */
	return(TRUE);  /*�����ɹ�*/
}

/*ɾ�����еĶ�ͷԪ�أ���x������ֵ*/
int DeleteQueue(SeqQueue *Q, QueueElementType *x)
{ 
	
	if(Q->front==Q->rear)  /*����Ϊ��*/
		return(FALSE);
	*x=Q->element[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;  /*�������ö�ͷָ��*/
	return(TRUE);  /*�����ɹ�*/
}

/*��ȡ���еĶ�ͷԪ�أ���x������ֵ*/
int GetHead(SeqQueue *Q, QueueElementType *x)
{ 
	if(Q->front==Q->rear)  /*����Ϊ��*/
	{
		return(FALSE);
	}	
	*x=Q->element[Q->front];
	
	return(TRUE);  /*�����ɹ�*/
}

int IsEmpty(SeqQueue *Q)
{ 
	if(Q->front==Q->rear)  /*����Ϊ��*/
	{
		return(TRUE);
	}	
	else
	{
		return(FALSE);  /*�����ɹ�*/
	}	
}


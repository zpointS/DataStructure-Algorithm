#include "linkstack.h"

/*��ջ����*/
int LSPush(LinkStack top, StackElementType x)/* ������Ԫ��xѹ��ջtop�� */ 
{
	LinkStackNode *temp;
	temp=(LinkStackNode *)malloc(sizeof(LinkStackNode));
 	if(temp==NULL)  
 		return(FALSE);   /* ����ռ�ʧ�� */
	temp->data=x;
	temp->next=top->next;
	top->next=temp;   /* �޸ĵ�ǰջ��ָ�� */ 

	return(TRUE);
}

/*��ջ����*/
int LSPop(LinkStack top, StackElementType *x)
{  
	/* ��ջtop��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��� */
	LinkStackNode * temp;
	temp=top->next;
	if(temp==NULL)  /*ջΪ��*/
		return(FALSE);
	top->next=temp->next;
	*x=temp->data;
	free(temp);   /* �ͷŴ洢�ռ� */
	
	return(TRUE);
}

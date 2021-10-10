#include "dqstack.h"

/*��ʼ������*/
void DSInitStack(DqStack *S)
{
	S->top[0]=-1;
	S->top[1]=M;
	memset(S->Stack, '#', M*sizeof(StackElementType));
}

/*��ջ����*/
int DSPush(DqStack *S,StackElementType x,int i)
{
	/*������Ԫ��xѹ��i�Ŷ�ջ*/
	if(S->top[0]+1==S->top[1]) /*ջ����*/
		return(FALSE);
	switch(i)
	{
	case 0:
		S->top[0]++;
		S->Stack[S->top[0]]=x;
		break;
	case 1:
		S->top[1]--;
		S->Stack[S->top[1]]=x;
		break;
	default:  /*��������*/
        return(FALSE);
 	}
 	
	return(TRUE);
}

/*��ջ����*/
int DSPop(DqStack *S,StackElementType *x,int i)
{
	/* ��i �Ŷ�ջ�е���ջ��Ԫ�ز��͵�x�� */
	switch(i)
	{
	case 0:
		if(S->top[0]==-1)  
			return(FALSE);
		*x=S->Stack[S->top[0]];
		S->top[0]--;
		break;
	case 1:
		if(S->top[1]==M)  
			return(FALSE);
		*x=S->Stack[S->top[1]];
		S->top[1]++;
		break;
	default:
		return(FALSE);
	}
	return(TRUE);
}

void Visit(DqStack *S)
{
	int flag;
	
	flag = 0;
	
	while(flag < M)
	{
		printf("%2c", S->Stack[flag]);
		flag ++;
		if(flag % 10 == 0)
		{
			printf("\n");	
		} 
	}
}

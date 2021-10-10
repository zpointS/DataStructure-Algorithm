#include "dqstack.h"

/*初始化操作*/
void DSInitStack(DqStack *S)
{
	S->top[0]=-1;
	S->top[1]=M;
	memset(S->Stack, '#', M*sizeof(StackElementType));
}

/*进栈操作*/
int DSPush(DqStack *S,StackElementType x,int i)
{
	/*把数据元素x压入i号堆栈*/
	if(S->top[0]+1==S->top[1]) /*栈已满*/
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
	default:  /*参数错误*/
        return(FALSE);
 	}
 	
	return(TRUE);
}

/*出栈操作*/
int DSPop(DqStack *S,StackElementType *x,int i)
{
	/* 从i 号堆栈中弹出栈顶元素并送到x中 */
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

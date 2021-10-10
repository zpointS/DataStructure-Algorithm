#include "seqstack.h"

void SSInitStack(SeqStack *S)
{
  	S->top = -1;
}


int IsEmpty(SeqStack *S) 
{
	return(S->top==-1? TRUE : FALSE);
}


int IsFull(SeqStack *S)	
{
	return(S->top==Stack_Size-1?TRUE:FALSE);
}

int SSPush(SeqStack *S,StackElementType x)
{
	if(S->top==Stack_Size-1)  
		return(FALSE); 
	S->top++;
	S->elem[S->top] = x;
	return(TRUE);
}

int SSPop(SeqStack *S,StackElementType *x)
{  
	
	if(S->top == -1)  
		return(FALSE);
	else
	{
  		*x = S->elem[S->top];
		S->top--;    
  		return(TRUE);
	}
}


int GetTop(SeqStack *S,StackElementType *x)
{  
	if(S->top == -1)  
		return(FALSE);
	else
	{
  		*x = S->elem[S->top];
  		
 		return(TRUE);
	}	
}


int Match(char ch,char str)
{		
	if(ch=='(' && str==')')
	{
		return TRUE;
	}
	else if(ch=='[' && str==']')
	{
		return TRUE;
	}
	else if(ch=='{' && str=='}')
	{
		return TRUE;
	}
	else 
		return FALSE;
}

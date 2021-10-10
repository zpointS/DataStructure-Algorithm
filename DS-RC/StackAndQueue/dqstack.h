#ifndef DQSTACK_H
#define DQSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TRUE	1
#define FALSE	0
#define M		100
typedef char StackElementType;
typedef struct
{
	StackElementType Stack[M];
	StackElementType top[2];  /*top[0]��top[1]�ֱ�Ϊ����ջ��ָʾ��*/
}DqStack;

void DSInitStack(DqStack *S);

int DSPush(DqStack *S,StackElementType x,int i);

int DSPop(DqStack *S,StackElementType *x,int i);

void Visit(DqStack *S);

#endif // END DQSTACK_H

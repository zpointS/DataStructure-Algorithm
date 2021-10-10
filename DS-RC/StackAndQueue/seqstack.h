#ifndef SEQSTACK_H
#define SEQSTACK_H 

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TRUE		1
#define FALSE		0
#define Stack_Size	50

typedef char StackElementType; 

/*顺序栈*/
typedef struct
{
	StackElementType	elem[Stack_Size]; /*用来存放栈中元素的一维数组*/
	int					top;          	  /*用来存放栈顶元素的下标，top为-1表示空栈*/
}SeqStack;


/*初始化*/
void SSInitStack(SeqStack *S);

/*判栈空*/
int IsEmpty(SeqStack *S); /*判断栈S为空栈时返回值为真，反之为假*/


/*判栈满*/
int IsFull(SeqStack *S);	/*判断栈S为满栈时返回值为真，反之为假*/


int SSPush(SeqStack *S,StackElementType x);


int SSPop(SeqStack *S,StackElementType *x);


/*取栈顶元素。*/
int GetTop(SeqStack *S,StackElementType *x);


/*进行匹配*/
int Match(char ch,char str);

#endif // END SEQSTACK_H 

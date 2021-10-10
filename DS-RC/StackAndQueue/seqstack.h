#ifndef SEQSTACK_H
#define SEQSTACK_H 

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TRUE		1
#define FALSE		0
#define Stack_Size	50

typedef char StackElementType; 

/*˳��ջ*/
typedef struct
{
	StackElementType	elem[Stack_Size]; /*�������ջ��Ԫ�ص�һά����*/
	int					top;          	  /*�������ջ��Ԫ�ص��±꣬topΪ-1��ʾ��ջ*/
}SeqStack;


/*��ʼ��*/
void SSInitStack(SeqStack *S);

/*��ջ��*/
int IsEmpty(SeqStack *S); /*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/


/*��ջ��*/
int IsFull(SeqStack *S);	/*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/


int SSPush(SeqStack *S,StackElementType x);


int SSPop(SeqStack *S,StackElementType *x);


/*ȡջ��Ԫ�ء�*/
int GetTop(SeqStack *S,StackElementType *x);


/*����ƥ��*/
int Match(char ch,char str);

#endif // END SEQSTACK_H 

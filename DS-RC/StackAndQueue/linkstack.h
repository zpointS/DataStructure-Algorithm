#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define TRUE	1
#define FALSE	0
typedef char StackElementType;
typedef struct node
{
	StackElementType	data;
	struct node			*next;
}LinkStackNode;

typedef LinkStackNode *LinkStack;

/*��ջ����*/
int LSPush(LinkStack top, StackElementType x);

/*��ջ����*/
int LSPop(LinkStack top, StackElementType *x);

#endif // END LINKSTACK_H 

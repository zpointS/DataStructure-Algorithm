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

/*进栈操作*/
int LSPush(LinkStack top, StackElementType x);

/*出栈操作*/
int LSPop(LinkStack top, StackElementType *x);

#endif // END LINKSTACK_H 

#ifndef TOPOSORT_H
#define TOPOSORT_H

#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#define Null	0
#define MAX		20

typedef struct ArcNode
{
	int 			adjvex;
	int 			weight;
	struct ArcNode	*nextarc;
}ArcNode,*AdjList;

typedef struct Graph
{
	AdjList elem[MAX+1];
	int 	vexnum;
	int 	arcnum;
	int 	GraphKind;
}Graph;


typedef struct Stack
{
	int s[MAX];
	int top;
}Stack;

void initStack(Stack *s);

int Push(Stack *s, int e);

int Pop(Stack *s, int *e);

int StackEmpty(Stack s);

void create(Graph *G);

int TopoSort(Graph G);

#endif // END TOPOSORT_H

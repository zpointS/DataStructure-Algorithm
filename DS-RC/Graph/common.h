#define N 10
#define INFINITY  32768
#define True	1
#define False	0
#define Error	-1
#define Ok 		1

#include "stdlib.h"
#include "stdio.h"

typedef enum{DG,DN,UDG,UDN}GraphKind;
typedef char VertexData;

typedef struct Node
{
	int 		data;
	struct Node *next;
}LinkQueueNode;

typedef struct
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;

typedef struct node
{
	char 		data;
	struct node *next;
}Node, *LinkList;

typedef struct node_
{
	char 			data;
	char 			data_;
	struct node_	*next;
}Node_, *LinkList_;

int visited[N];

int InitQueue(LinkQueue *Q);

int EnterQueue(LinkQueue *Q,int x);

int DeleteQueue(LinkQueue *Q,int *x);

int IsEmpty(LinkQueue *Q);

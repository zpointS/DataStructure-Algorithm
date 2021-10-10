#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK		1
#define ERROR	0
#define TRUE	1
#define FALSE	0


typedef int ElemType;

/*结点类型定义*/ 
typedef struct LinkListNode   
{ 
	ElemType		data;
	struct Node		*next;
}LinkListNode, *LinkList, **Link;

typedef struct DNode
{
	ElemType		data;
	struct DNode	*prior;
 	struct DNode	*next;
}DNode,	*DoubleList;

void InitLinkList(LinkList *L); 

void CreateFromHead(LinkList L);

void TravelLinkList(LinkList L); 

void CreateFromTail(LinkList L);

Node *Get(LinkList  L, int i);

Node *Locate( LinkList L,ElemType key);

int	ListLength(LinkList L);

int InsList(LinkList L,int i,ElemType e);

int DelList(LinkList L,int i,ElemType *e);

LinkList MergeLinkList(LinkList LA, LinkList LB);

void CreateCLinkList(LinkList l);

LinkList CreateRCLinkList();

void CreateDList(DoubleList L);

int DlinkIns(DoubleList L, int i, ElemType e);

int	DlinkDel(DoubleList L, int i, ElemType *e);

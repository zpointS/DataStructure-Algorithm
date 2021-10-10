#include "toposort.h"

void initStack(Stack *s)
{
	(*s).top=0;
}

int Push(Stack *s, int e)
{
	if((*s).top>=MAX) 
	{
		return 0;
	}
	else
	{
		(*s).s[(*s).top++]=e;
	} 
}

int Pop(Stack *s, int *e)
{
	if((*s).top<=0)
	{
		return 0;
	} 
	else
	{
		*e=(*s).s[--(*s).top];
	} 
}

int StackEmpty(Stack s)
{
	if(s.top==0)
	{
		return 1;
	}
	else
	{
		return 0;
	} 
}


void create(Graph *G)
{
	int 	i;
	int 	start; 
	int 	end;
	AdjList p;
	for(i=0;i<=MAX;i++)
	{
		(*G).elem[i]=Null;
	}	
	for(i=1;i<=(*G).arcnum;i++)
	{
		fflush(stdin);
		scanf("%d,%d",&start,&end);
		p=(AdjList)malloc(sizeof(ArcNode));
		p->adjvex=end;
		p->nextarc=(*G).elem[start];
		(*G).elem[start]=p;
		if((*G).GraphKind==0)
		{
			p=(AdjList)malloc(sizeof(ArcNode));
			p->adjvex=start;
			p->nextarc=(*G).elem[end];
			(*G).elem[end]=p;
		}
	}
}


int TopoSort(Graph G)
{
	int 	i;
	int 	count;
	int 	indegree[MAX+1];
	AdjList p;
	Stack 	S;
	for(i=1;i<=G.vexnum;i++)
	{
		indegree[i]=0;
	}	
	initStack(&S);
	for(i=1;i<=G.vexnum;i++)
	{
		for(p=G.elem[i];p;p=p->nextarc)
		{
			++indegree[p->adjvex];
		}	
	}	
	for(i=1;i<=G.vexnum;i++)
	{
		if(!indegree[i])
		{
			Push(&S,i);
		} 
	}	
	count=0;
	while(!StackEmpty(S))
	{
		Pop(&S,&i);
		printf("v%d ",i);
		++count;
		for(p=G.elem[i];p;p=p->nextarc)
		{
			if(!(--indegree[p->adjvex])) 
			{
				Push(&S,p->adjvex);
			}
		}	
	}
	if(!count) 
	{
		return 1;
	}
}

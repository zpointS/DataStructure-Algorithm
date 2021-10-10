#include "adjlist.h" 

int LocateVertex_(AdjList *g,VertexData v)
{
	int k;
	int j;
	
	j = Error;
	
	for(k=0;k<g->vexnum_;k++)
	{
		if(g->vertex[k].data==v)
		{
			j=k;
			break;
		}
	}
		
	return(j);
}

int CreateUDG_(AdjList *g)
{
	int 		i;
	int 		j;
	int 		k;
	ArcNode_ 	*p;
	ArcNode_ 	*r;
	VertexData 	data;
	VertexData 	vi;
	VertexData 	vj;
	
	printf("input G->vexnum,G->arcnum:");
	fflush(stdin);
	scanf("%d,%d",&(g->vexnum_),&(g->arcnum_));

	// 定点
	for(i=0;i<g->vexnum_;i++)
	{ 
	    printf("input Vertex[%d]:", i);
	    fflush(stdin);
	    scanf("%c", &data);
		g->vertex[i].data= data;
		g->vertex[i].firstarc=NULL;
	}
	
	// 边信息 
	for(k=0;k<g->arcnum_;k++)
	{
		printf("please input new edge(A,B): ");
		fflush(stdin);
  		scanf("%c,%c", &vi, &vj);
  		i = LocateVertex_(g, vi);
		j = LocateVertex_(g, vj);
  		
  		p = (ArcNode_ *)malloc(sizeof(ArcNode_));
    	p->adjvex = j;
        p->nextarc = g->vertex[i].firstarc;
        g->vertex[i].firstarc = p;
        
        r = (ArcNode_ *)malloc(sizeof(ArcNode_));
        r->adjvex = i;
        r->nextarc = g->vertex[j].firstarc;
        g->vertex[j].firstarc = r;
	}
}

void Visit(AdjList *g){
	int 		k;
	ArcNode_ 	*p;
	for(k=0;k<g->vexnum_;k++)
	{
		printf("Vertex[%d]=%c |", k, g->vertex[k].data);
		p = (ArcNode_ *)malloc(sizeof(ArcNode_));
		p = g->vertex[k].firstarc;
		while(p)
		{	
			printf("->%d",p->adjvex);
			p = p->nextarc;	
		} 
		printf("\n");
	} 
}

void DFS_(AdjList g,int vo)
{
	ArcNode_ *p;
	printf("%c", g.vertex[vo].data);
	visited[vo]=True;
	p=g.vertex[vo].firstarc;
	while(p!=NULL)
	{
		if(!visited[p->adjvex])
		{
			DFS_(g,p->adjvex);
		}	
		p=p->nextarc;
	}
}

void BFS_(AdjList g,int vo)
{
	ArcNode_ 	*p;
	int 		vi;
	LinkQueue 	Q;
	
	InitQueue(&Q);
	visited[vo]=True;
	EnterQueue(&Q,vo);
	while(!IsEmpty(&Q))
	{
		DeleteQueue(&Q,&vi);
		printf("%c",g.vertex[vi].data);
		p=g.vertex[vi].firstarc;
		while(p!=NULL)
		{
			if(!visited[p->adjvex])
			{
				visited[p->adjvex]=True;
				EnterQueue(&Q,p->adjvex);
			}
			p=p->nextarc;
		}
	}
}

void Traverse_(AdjList g)
{
	int vi;
	for(vi=0;vi<g.vexnum_;vi++)
	{
		visited[vi]=False;
	}	
	printf("\nThe order of g Depth\n");
	
	for(vi=0;vi<g.vexnum_;vi++)
	{
		if(!visited[vi])
		{
			DFS_(g,vi); 
			printf("\n");
		}
	}
	
	for(vi=0;vi<g.vexnum_;vi++)
	{
		visited[vi]=False;
	}	
	
	printf("\nThe order of g Breadth\n");
	for(vi=0;vi<g.vexnum_;vi++)
    {
		if(!visited[vi])
		{
			BFS_(g,vi);   
			printf("\n");
		}
	}
}

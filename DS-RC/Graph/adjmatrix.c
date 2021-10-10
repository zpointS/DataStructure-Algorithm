#include "adjmatrix.h"

int LocateVertex(AdjMatrix *g,VertexData v)
{
	int k;
	int j;
	j = Error;
	for(k=0;k<g->vexnum;k++)
	{
		if(g->vexs[k]==v)
		{
			j=k;
			break;
		}
	}
		
	return(j);
}

int CreateUDG(AdjMatrix *g)
{
	int 		i;
	int 		j;
	int 		k;
	VertexData 	v1;
	VertexData 	v2;

	printf("input G->vexnum,G->arcnum:");
	fflush(stdin);
	scanf("%d,%d",&(g->vexnum),&(g->arcnum));
	
	for(i=0;i<g->vexnum;i++)
	{
		for(j=0;j<g->vexnum;j++)
		{
			g->arcs[i][j].adj=0;
		}	
	}	
    
	// 存储定点及其位置信息 
	printf("input G->vexs\n");
	for(i=0;i<g->vexnum;i++)
	{
		fflush(stdin);
		scanf("%c",&(g->vexs[i]));
	}
	
	// 建立定点之间的弧关系 
	for(k=0;k<g->arcnum;k++)
	{ 
	    printf("input arc[%d]=(v1,v2):", k+1);
	    fflush(stdin);
		scanf("%c,%c",&v1,&v2);
		
		i=LocateVertex(g,v1);
		j=LocateVertex(g,v2);
		g->arcs[i][j].adj=1;
		g->arcs[j][i].adj=1;
	}
	return(Ok);
}

void DFS(AdjMatrix g,int vo)
{
	int vj;
	printf("%c",g.vexs[vo]);
	visited[vo]=True;
	for(vj=0;vj<g.vexnum;vj++)
	{
		if((!visited[vj])&&(g.arcs[vo][vj].adj==1))
		{
			DFS(g,vj);
		}	
	}	
}

void BFS(AdjMatrix g,int vo)
{
	int 		vi;
	int 		vj;
	LinkQueue 	Q;
	
	InitQueue(&Q);
	visited[vo]=True;
	EnterQueue(&Q,vo);
	while(!IsEmpty(&Q))
	{
		DeleteQueue(&Q,&vi);
		printf("%c",g.vexs[vi]);
		for(vj=0;vj<g.vexnum;vj++)
		{
			if((!visited[vj])&&(g.arcs[vi][vj].adj==1))
			{
				visited[vj]=True;
				EnterQueue(&Q,vj);
			}
		}	
	}
}

void Traverse(AdjMatrix g)
{
	int vi;
	for(vi=0;vi<g.vexnum;vi++)
	{
		visited[vi]=False;
	}	
	printf("\nThe order of g Depth\n");
	for(vi=0;vi<g.vexnum;vi++)
	{
		if(!visited[vi])
		{
			DFS(g,vi);    
			printf("\n");
		}
	}
	for(vi=0;vi<g.vexnum;vi++)
	{
		visited[vi]=False;
	}	
	printf("\nThe order of g Breadth\n");
	for(vi=0;vi<g.vexnum;vi++)
	{
		if(!visited[vi])
		{
			BFS(g,vi);    
			printf("\n");
		}
	}
}

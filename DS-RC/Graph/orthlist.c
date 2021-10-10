#include "orthlist.h"

int _LocateVertex(OrthList *G,VertexData v)    /*�󶥵�λ�ú���*/
{
	int	j;
	int	k;
	j = Error;
	for(k=0;k<G->vexnum;k++)
		if(G->vertex[k].data==v)
		{ 
			j=k; 
			break; 
		}
	return(j);
}

void  CrtOrthList(OrthList *g)
/*���ն�����n���������Ϣ��e��������Ϣ���Խ���һ������ͼ��ʮ������*/
{
	int		n;
	int		e;
	int		i;
	int		j;
	int		k;
	char 	vt;
	char 	vh;
	ArcNode *p;
	
	printf("�Ӽ�������ͼ�Ķ�������ͻ��ĸ���(e.g. 4,3):");
	fflush(stdin);
	scanf("%d,%d",&n,&e);  /*�Ӽ�������ͼ�Ķ�������ͻ��ĸ���*/
	g->vexnum = n;
	g->arcnum = e;
	for(i=0;i<n;i++) 
	{
		printf("����ͼ�Ķ���:");
		fflush(stdin);
		scanf("%c",&g->vertex[i].data);
		g->vertex[i].firstin=NULL;
		g->vertex[i].firstout=NULL;
	}
	for(k=0;k<e;k++) 
	{
		printf("����һ��������������:");
		fflush(stdin);
		scanf("%c,%c",&vt,&vh);
		i=LocateVertex(g,vt);
		j = LocateVertex(g,vh);
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->tailvex=i;
		p->headvex=j;
		p->tlink=g->vertex[i].firstout;
		g->vertex[i].firstout=p;
		p->hlink=g->vertex[j].firstin;
		g->vertex[j].firstin=p;
    }
}/* CrtOrthList */

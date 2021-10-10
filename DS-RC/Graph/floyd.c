#include "floyd.h"

////////////////邻接矩阵的建立////////////////
AdjGraph *CreateAdjGrahp()
{    
	AdjGraph*	g;
	int 		i;
	int			j;
	int			k;
	int			x;
	
	g=(AdjGraph *)malloc(sizeof(AdjGraph));
	
	printf("Input vexnum and arcnum(格式如:顶点数 边数<Enter>):");
	fflush(stdin); 
	scanf("%d %d",&g->vexnum,&g->arcnum);      //读入顶点个数和边数
	
	for(i=1;i<=g->vexnum;i++)
	{
	    printf("输入顶点%d信息:", i);
		fflush(stdin); 
		scanf("%c",&g->vexs[i]);               //读入顶点信息
	}
		
	for(i=1;i<=g->vexnum;i++)
	{
		for(j=1;j<=g->vexnum;j++)
		{
			g->arcs[i][j]=INFINITY;            //初始化邻接矩阵
		}	
	}		

	printf("顶点<->序号\n");
	for(k=1;k<=g->vexnum;k++)
	{
		printf("%4c<->%d\n",g->vexs[k],k);
	}		

	printf("输入每条边对应的两个顶点的序号及权值,格式为i j x<Enter>:\n");
	for(k=1;k<=g->arcnum;k++)
	{
		fflush(stdin); 
		scanf("%d %d %d",&i,&j,&x);//输入边信息，建立邻接矩阵
		g->arcs[i][j]=x;
	}
	
	return g;
}

/////////////////Floyd算法///////////////
int CenterVex(AdjGraph *g)
{
	int i;
	int j;
	int k;
	int min;
	int len;
	int length[MAX_VEX_NUM+1][MAX_VEX_NUM+1];
	
	for(i=1;i<=g->vexnum;i++)
	{			
		for(j=1;j<=g->vexnum;j++)
		{
			length[i][j]=g->arcs[i][j];	
		}		
		length[i][i]=0;
	}
	
	for(k=1;i<=g->vexnum;k++)
	{
		for(i=1;i<=g->vexnum;i++)
		{
			for(j=0;j<g->vexnum;j++)			
			{
				if(length[i][k]+length[k][j]<length[i][j])				
				{
					length[i][j]=length[i][k]+length[k][j];
				}	
			}		
		}	
	}				
	min=INFINITY;
	k=0;		
	for(i=1;i<=g->vexnum;i++)    // 选择最大短路径长度之和最小的顶点Vk
	{			
		len=0;		
		for(j=0;j<g->vexnum;j++) // 求Vi到其余顶点最短路径长度之和
		{
			len=len+length[i][j];	
		}	
		if(len<min)
		{		
			k=i;		
			min=len;	
		}
	}	
						
	return(k);
}

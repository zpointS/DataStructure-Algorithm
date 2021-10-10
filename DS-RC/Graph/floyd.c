#include "floyd.h"

////////////////�ڽӾ���Ľ���////////////////
AdjGraph *CreateAdjGrahp()
{    
	AdjGraph*	g;
	int 		i;
	int			j;
	int			k;
	int			x;
	
	g=(AdjGraph *)malloc(sizeof(AdjGraph));
	
	printf("Input vexnum and arcnum(��ʽ��:������ ����<Enter>):");
	fflush(stdin); 
	scanf("%d %d",&g->vexnum,&g->arcnum);      //���붥������ͱ���
	
	for(i=1;i<=g->vexnum;i++)
	{
	    printf("���붥��%d��Ϣ:", i);
		fflush(stdin); 
		scanf("%c",&g->vexs[i]);               //���붥����Ϣ
	}
		
	for(i=1;i<=g->vexnum;i++)
	{
		for(j=1;j<=g->vexnum;j++)
		{
			g->arcs[i][j]=INFINITY;            //��ʼ���ڽӾ���
		}	
	}		

	printf("����<->���\n");
	for(k=1;k<=g->vexnum;k++)
	{
		printf("%4c<->%d\n",g->vexs[k],k);
	}		

	printf("����ÿ���߶�Ӧ�������������ż�Ȩֵ,��ʽΪi j x<Enter>:\n");
	for(k=1;k<=g->arcnum;k++)
	{
		fflush(stdin); 
		scanf("%d %d %d",&i,&j,&x);//�������Ϣ�������ڽӾ���
		g->arcs[i][j]=x;
	}
	
	return g;
}

/////////////////Floyd�㷨///////////////
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
	for(i=1;i<=g->vexnum;i++)    // ѡ������·������֮����С�Ķ���Vk
	{			
		len=0;		
		for(j=0;j<g->vexnum;j++) // ��Vi�����ඥ�����·������֮��
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

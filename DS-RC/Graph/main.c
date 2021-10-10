// #include "adjmatrix.h"      
// #include "adjlist.h"         
// #include "orthlist.h"
// #include "prim.h"          
// #include "toposort.h"
// #include "dijkstra.h"
 #include "floyd.h"           // TODO:something should be carefull
// #include "criticalpath.h"

int main(int argc, char *argv[])
{
#ifdef ADJMATRIX_H
	AdjMatrix g;
	CreateUDG(&g);
	Traverse(g);
#endif

#ifdef ADJLIST_H
	AdjList g;
	CreateUDG_(&g);
	//Visit(&g);
	Traverse_(g);
#endif

#ifdef ORTHLIST_H
	OrthList g;
	CrtOrthList(&g);
#endif

#ifdef PRIM_H
	int		u; 
	char	j;
	j = 'y'; 
	printf("��������ʾ����ͼ����С������������\n"); 
	printf("��������ͼ�Ķ������ͻ���.\n��ʽ��������������������:4,4\n"); 
	printf("�������������(��β,��ͷ)�ͻ���Ȩֵ��\n"); 
	printf("��ʽ:��β����ͷ��Ȩֵ������\n1,2,1\n1,3,2\n2,4,3\n3,4,4\n"); 
	printf("���򽫻ṹ���ͼ����С������������\n"); 
	printf("����ʾ����С��������\n1,2\n1,3\n2,4\n"); 

	while(j!='N'&&j!='n') 
	{ 
		// printf("������ͼ�Ķ���ͻ���:"); 
		DefaultCreateGraph(G);                           //CreateGraph(G);//�����ڽӾ���ṹ��ͼ 
		printf("����һ���㿪ʼ:"); 
		fflush(stdin);
		scanf("%d",&u);                                  //��������ķ�㷨�е���ʼ���� 
		PrimMST(G,T,u);                                  //����ķ�㷨����С������ 
		PrintMST(T);                                     //��ӡ��С������ 
		printf("��С����������������ϣ�����������?(Y/N)"); 
		fflush(stdin);
		scanf("%c",&j); 
	}
#endif

#ifdef TOPOSORT_H
	Graph G;
	printf("Please input the number of vex, arc and GraphKind(e.g. 4,3,3):");
	fflush(stdin);
	scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&G.GraphKind);
	printf("Please input the vertex of edge(e.g. start,end):\n");
	create(&G);
	printf("The outcome of TopoSort is:\n");
	TopoSort(G);
#endif

#ifdef DIJKSTRA_H
  int i;
  int k;

  for(i=0; i<VertexNum; i++) { Visited[i] = 0;  path[i] = 1;}
  Dijkstra(1);
  printf("\n\nAll Path-------------------------\n");


  for(i=2; i<VertexNum; i++)
  {
     printf("[%d] ",Distance[i]);
     k = i;
     do
     {
       printf("%d<--",k);
       k  = path[k];
     } while (k!=1);
     printf("1 \n");
  }
#endif

#ifdef FLOYD_H
	int		 k;
	AdjGraph *g;
	g=CreateAdjGrahp();
	k=CenterVex(g);
	printf("���Ķ���Ϊ:%c\n", g->vexs[k]);
#endif

#ifdef CRITICALPATH_H
	char	ch;
	int 	i;
	for(;;)
	{
		do
		{
			system("cls");
			printf("|             ��ӭ������ؼ�·���㷨����              |\n");
			for(i=0;i<80;i++)printf("*");
			printf("%s","(S)tart��ʼ���빤�̵Ľڵ����ݲ�����ؼ�·��\n");
			printf("%s","(E)xit�˳�\n");
			printf("%s","������ѡ��:");
			scanf("%c",&ch);
			ch=toupper(ch);
		}while(ch!='S'&&ch!='E');
		switch(ch)
		{
		case'S':
			seekkeyroot();
			break;
		case'E':
			return 1;
		}
	}
#endif	
	return 0;
}

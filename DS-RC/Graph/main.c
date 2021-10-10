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
	printf("本程序将演示构造图的最小代价生成树。\n"); 
	printf("首先输入图的顶点数和弧数.\n格式：顶点数，弧数；例如:4,4\n"); 
	printf("接着输入各条弧(弧尾,弧头)和弧的权值。\n"); 
	printf("格式:弧尾，弧头，权值；例如\n1,2,1\n1,3,2\n2,4,3\n3,4,4\n"); 
	printf("程序将会构造该图的最小代价生成树。\n"); 
	printf("并显示该最小生成树。\n1,2\n1,3\n2,4\n"); 

	while(j!='N'&&j!='n') 
	{ 
		// printf("请输入图的顶点和弧数:"); 
		DefaultCreateGraph(G);                           //CreateGraph(G);//生成邻接矩阵结构的图 
		printf("从哪一顶点开始:"); 
		fflush(stdin);
		scanf("%d",&u);                                  //输入普里姆算法中的起始顶点 
		PrimMST(G,T,u);                                  //普里姆算法求最小生成树 
		PrintMST(T);                                     //打印最小生成树 
		printf("最小代价生成树构造完毕，继续进行吗?(Y/N)"); 
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
	printf("中心顶点为:%c\n", g->vexs[k]);
#endif

#ifdef CRITICALPATH_H
	char	ch;
	int 	i;
	for(;;)
	{
		do
		{
			system("cls");
			printf("|             欢迎进入求关键路径算法程序              |\n");
			for(i=0;i<80;i++)printf("*");
			printf("%s","(S)tart开始输入工程的节点数据并求出关键路径\n");
			printf("%s","(E)xit退出\n");
			printf("%s","请输入选择:");
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

#include<iostream>
#include<stack>
#include<fstream>

using namespace std;

typedef struct node
{
    int **matrix;      //邻接矩阵 
    int n;                 //顶点数 
    int e;                 //边数 
}MGraph; 

void Dijkstradot(MGraph g, int *path, bool *visited , int vs)
{
	FILE *fp=fopen("Dijkstra.gv","w+");
	fprintf(fp,"digraph Dijkstra {\nnode [shape=ellipse];\n");
	fprintf(fp,"v%d[shape=diamond,color=red,fontcolor=red];\n",vs);
	for (int i = 0; i < g.n && i != vs; i++)
		fprintf(fp,"v%d;\n",i);
		
	for (int i = 0; i < g.n; i++)  
	{  
		for (int j = 0; j <g.n; j++)  
 		{  
 		if(g.matrix[i][j] != 0)
			{
				if(visited[i]==true&&visited[j]==true&&path[j]==i)
				{
					fprintf(fp,"v%d[fontcolor=red,color=red];\n",i);
					fprintf(fp,"v%d[fontcolor=red,color=red];\n",j);
					fprintf(fp,"v%d->v%d[style=bold,label=%d,fontcolor=red,color=red];\n",i,j,g.matrix[i][j]);
				}
				else
				{
					fprintf(fp,"v%d->v%d[style=bold,label=%d];\n",i,j,g.matrix[i][j]);	
				}
			}
  		}  
   	} 
 	fprintf(fp,"}\n");
 	fclose(fp);
}
void DijkstraPath(MGraph g,int *dist,int *path,int vs)   //vs表示源顶点 
{
    int i,j,k;
    bool *visited=(bool *)malloc(sizeof(bool)*g.n);
    for(i=0;i<g.n;i++)     //初始化 
    {
        if(g.matrix[vs][i]>0&&i!=vs)
        {
            dist[i]=g.matrix[vs][i];
            path[i]=vs;     //path记录最短路径上从vs到i的前一个顶点 
        }
        else
        {
            dist[i]=INT_MAX;    //若i不与vs直接相邻，则权值置为无穷大 
            path[i]=-1;
        }
        visited[i]=false;
        path[vs]=vs;
        dist[vs]=0;
    }
    FILE *fp=fopen("Dijkstra.gv","w+");
	fprintf(fp,"digraph Dijkstra {\nnode [shape=ellipse];\n");
	fprintf(fp,"v%d[shape=diamond,color=red,fontcolor=red];\n",vs);
	for (int i = 0; i < g.n && i != vs; i++)
		fprintf(fp,"v%d; ",i);
	for (int i = 0; i < g.n; i++)  
  	{  
       	for (int j = 0; j <g.n; j++)  
       	{  
       		if(g.matrix[i][j] != 0)
			{
				fprintf(fp,"v%d->v%d[style=bold,label=%d];\n",i,j,g.matrix[i][j]);
			}
  		}  
   	} 
	fprintf(fp,"}\n");
	fclose(fp);
	system("sfdp.exe -Tpng Dijkstra.gv -o DijkSetp01.png");
    visited[vs]=true;
    for(i=1; i<g.n; i++)     //循环扩展n-1次 
    {
        int min=INT_MAX;
        int u;
        for(j=0;j<g.n;j++)    //寻找未被扩展的权值最小的顶点 
        {
            if(visited[j]==false&&dist[j]<min)
            {
                min=dist[j];
                u=j;        
            }
        } 
        visited[u]=true;
        for(k=0;k<g.n;k++)   //更新dist数组的值和路径的值 
        {
            if(visited[k]==false&&g.matrix[u][k]>0&&min+g.matrix[u][k]<dist[k])
            {
                dist[k]=min+g.matrix[u][k];
                path[k]=u; 
            }
        }
		Dijkstradot(g,path,visited,vs);
	 	char orderstr[128];
		sprintf(orderstr,"sfdp.exe -Tpng Dijkstra.gv -o DijkSetp%02d.png",i+1);
//		if( i == g.n-1)
			system(orderstr);        
    }    
}

int main(int argc, char *argv[])
{
    if(argc<3)
	{
		printf("Dijkstra.ext [NodeNum] [EdgeNum]");
		return 0x01;
	} 
	MGraph g;
	g.n = atoi(argv[1]);
	g.e = atoi(argv[2]);
	g.matrix = (int **)malloc(sizeof(int *) * g.n);
	for(int i=0; i<g.n; i++)
		g.matrix[i] = (int *)malloc(sizeof(int) * g.n);

    int *dist= new int[g.n];
    int *path= new int[g.n];
	
    for(int i=0; i<g.n; i++)
        for(int j=0; j<g.n; j++)
        	g.matrix[i][j] = 0;
	
	int maxsinglearch, ecounter;
	
	if(g.e >= g.n)
	{
		maxsinglearch = g.n;
		for(int i=0; i<g.n; i++)
			g.matrix[i][(i+1)%g.n] = g.n / 2 + rand() % maxsinglearch;
		ecounter = g.n;		
	}
	else
	 	ecounter = 0;
	
	maxsinglearch = g.n;
   	while( ecounter < g.e)
   	{
   		rand();
	   	int s = rand() % g.n;
	   	int t = rand() % g.n;
	   	
	   	if( s != t && g.matrix[s][t]==0 && ( g.e > 3 * g.n || g.matrix[t][s]==0)) //随机生成没有双向弧的有向图 
	   	{
	   		g.matrix[s][t] = rand() % maxsinglearch;
	   		ecounter++;
	   	}
 	}

	int vs = 0;
	
    FILE *fp=fopen("DijkInitGraph.gv","w+");
	fprintf(fp,"digraph DijkInitGraph {\nnode [shape=ellipse];\n");
	fprintf(fp,"v%d[shape=diamond];\n",vs);
	for (int i = 0; i < g.n && i != vs; i++)
		fprintf(fp,"v%d; ",i);
 	for (int i = 0; i < g.n; i++)
    	for (int j = 0; j <g.n; j++)  
        	if(g.matrix[i][j] != 0)
				fprintf(fp,"v%d->v%d[style=bold,label=%d];\n",i,j,g.matrix[i][j]);
 	fprintf(fp,"}\n");
 	fclose(fp);
 	system("sfdp.exe -Tpng DijkInitGraph.gv -o DijkInitGraph.png"); //fdp sfdp

    DijkstraPath(g,dist,path,vs); // 0 表示输入从 0 号节点开始 

	for(int i=0; i<g.n; i++)
		free(g.matrix[i]);
	free(g.matrix);
		
    return 0;
}
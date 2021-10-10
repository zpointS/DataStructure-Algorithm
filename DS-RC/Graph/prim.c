#include "prim.h"

void Error(char *msg) 
{ 
	printf("%c\n",msg); 
} 
 
void CreateGraph(AdjMatrix G){ 
	int i;
	int j; 
	int start;
	int end;
	int weight; 
	
	for(i=0;i<n;i++)                                  //n为图的顶点数 
	{
		for(j=0;j<n;j++) 
		{
			G[i][j] = INFINITY;                       //INFINITY代表无穷大
		}	 
	}
	
	printf("输入弧和其权值，格式：弧尾，弧头，权值\n"); 
	for(i=0;i<n-1;i++)
	{
	    fflush(stdin); 
		scanf("%d %d %d",&start,&end,&weight); 
		G[start][end]=weight; 
		G[end][start]=weight; 
	} 
} 

void DefaultCreateGraph(AdjMatrix G){ 
	int i;
	int j; 
	for(i=0;i<n;i++)                                  //n为图的顶点数 
	{
		for(j=0;j<n;j++) 
		{
			G[i][j] = INFINITY; 
		}	
	}	
	//0-9 
	G[0][1]=4; 
	G[1][0]=4; 

	G[1][2]=2; 
	G[2][1]=2; 

	G[0][3]=3; 
	G[3][0]=3; 

	G[1][5]=1; 
	G[5][1]=1; 

	G[3][6]=10; 
	G[6][3]=10; 

	G[6][9]=5; 
	G[9][6]=5; 

	G[9][7]=2; 
	G[7][9]=2; 

	G[7][8]=6; 
	G[8][7]=6; 

	G[3][4]=8; 
	G[4][3]=8; 

	G[4][5]=1; 
	G[5][4]=1; 

	G[2][5]=2; 
	G[5][2]=2; 

	G[4][7]=4; 
	G[7][4]=4; 

	G[5][8]=4; 
	G[8][5]=4; 
} 


void InitCandidateSet(AdjMatrix G,MST T,int r){ 
	int i;
	int k;
	
	k = 0; 
	
	for(i=0;i<n;i++)                                   //依次行成每个蓝点i初始的最短紫边存放在T[k]中 
	{
		if(i!=r){                                      //i是蓝点(r,i)是紫边 
			T[k].fromvex = r;                          //紫边的起点为红点 
			T[k].tovex   = i;                          //紫边的终点为蓝点 
			T[k++].length= G[r][i];                    //紫边长度,注:先取k然后再加一 
		}
	}	
} 

//在当前候选轻边集T[k..n-2]中选择最短紫边,k<=n-2 
int SelectLightEdge(MST T,int k){ 

	int min; 
	int i; 
	int minpos; 
	
	min = INFINITY;
	for(i=k;i<n-1;i++)                                 //遍历当前候选轻边集,找一轻边 
	{
		if(T[i].length < min){ 
			min = T[i].length; 
			minpos = i;                                //记录当前最短紫边位置 
		}
	}	
	if(min==INFINITY)                                  //表示图不连通,不能求MST 
	{
		Error("Graph is disconnected!"); 
	}	
	return minpos;                                     //返回找到的轻边T[minpos]的位置 
}

void ModifyCandidateSet(AdjMatrix G,MST T,int k,int v){ 
	int i;
	int d; 
	for(i=k;i<n-1;i++)
	{                                                 //遍历当前候选轻边集T[k..n-2] 
		d = G[v][T[i].tovex];                         //d是新紫边(v,T[i].tovex)的长度 
		if(d<T[i].length)
		{                                             //新紫边长度小于蓝点T[i].tovex原来关联的最短紫边的长度 
			T[i].length = d; 
			T[i].fromvex= v;                          //新紫边取代原最短紫边 
		} 
	} 
}

//求图G的以r为根的MST,r为开始的结点 
void PrimMST(AdjMatrix G,MST T,int r){ 
	int 			k;
	int 			m;
	int 			v; 
	TreeEdgeNode 	e; 

	InitCandidateSet(G,T,r);                           //设置初始的轻边候选集T[0..n-2] 
	for(k=0;k<n-1;k++)								   //依次求MST的第k条树边 
	{                                
		m = SelectLightEdge(T,k);                      //在当前候选轻边集T[k..n-2]中选取轻边T[m] 
		                                               //轻边T[m]和紫边T[k]交换，即把轻边扩充到树中 
		e   = T[m]; 
		T[m]= T[k]; 
		T[k]= e;                                                   
		v   = T[k].tovex;                              //交换后红色树边集为T[0..k]候选边集为T[k+1..n-2] 
		ModifyCandidateSet(G,T,k+1,v);                 //根据新红点v调整候选轻边集T[k+1...n-2]扩充 
	}
}

void PrintMST(MST T){ 
	int i; 
	for(i=0;i<n-1;i++){ 
		printf("(%d,%d)=%d\n",T[i].fromvex,T[i].tovex,T[i].length); 
	} 
} 

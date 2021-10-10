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
	
	for(i=0;i<n;i++)                                  //nΪͼ�Ķ����� 
	{
		for(j=0;j<n;j++) 
		{
			G[i][j] = INFINITY;                       //INFINITY���������
		}	 
	}
	
	printf("���뻡����Ȩֵ����ʽ����β����ͷ��Ȩֵ\n"); 
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
	for(i=0;i<n;i++)                                  //nΪͼ�Ķ����� 
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
	
	for(i=0;i<n;i++)                                   //�����г�ÿ������i��ʼ������ϱߴ����T[k]�� 
	{
		if(i!=r){                                      //i������(r,i)���ϱ� 
			T[k].fromvex = r;                          //�ϱߵ����Ϊ��� 
			T[k].tovex   = i;                          //�ϱߵ��յ�Ϊ���� 
			T[k++].length= G[r][i];                    //�ϱ߳���,ע:��ȡkȻ���ټ�һ 
		}
	}	
} 

//�ڵ�ǰ��ѡ��߼�T[k..n-2]��ѡ������ϱ�,k<=n-2 
int SelectLightEdge(MST T,int k){ 

	int min; 
	int i; 
	int minpos; 
	
	min = INFINITY;
	for(i=k;i<n-1;i++)                                 //������ǰ��ѡ��߼�,��һ��� 
	{
		if(T[i].length < min){ 
			min = T[i].length; 
			minpos = i;                                //��¼��ǰ����ϱ�λ�� 
		}
	}	
	if(min==INFINITY)                                  //��ʾͼ����ͨ,������MST 
	{
		Error("Graph is disconnected!"); 
	}	
	return minpos;                                     //�����ҵ������T[minpos]��λ�� 
}

void ModifyCandidateSet(AdjMatrix G,MST T,int k,int v){ 
	int i;
	int d; 
	for(i=k;i<n-1;i++)
	{                                                 //������ǰ��ѡ��߼�T[k..n-2] 
		d = G[v][T[i].tovex];                         //d�����ϱ�(v,T[i].tovex)�ĳ��� 
		if(d<T[i].length)
		{                                             //���ϱ߳���С������T[i].tovexԭ������������ϱߵĳ��� 
			T[i].length = d; 
			T[i].fromvex= v;                          //���ϱ�ȡ��ԭ����ϱ� 
		} 
	} 
}

//��ͼG����rΪ����MST,rΪ��ʼ�Ľ�� 
void PrimMST(AdjMatrix G,MST T,int r){ 
	int 			k;
	int 			m;
	int 			v; 
	TreeEdgeNode 	e; 

	InitCandidateSet(G,T,r);                           //���ó�ʼ����ߺ�ѡ��T[0..n-2] 
	for(k=0;k<n-1;k++)								   //������MST�ĵ�k������ 
	{                                
		m = SelectLightEdge(T,k);                      //�ڵ�ǰ��ѡ��߼�T[k..n-2]��ѡȡ���T[m] 
		                                               //���T[m]���ϱ�T[k]����������������䵽���� 
		e   = T[m]; 
		T[m]= T[k]; 
		T[k]= e;                                                   
		v   = T[k].tovex;                              //�������ɫ���߼�ΪT[0..k]��ѡ�߼�ΪT[k+1..n-2] 
		ModifyCandidateSet(G,T,k+1,v);                 //�����º��v������ѡ��߼�T[k+1...n-2]���� 
	}
}

void PrintMST(MST T){ 
	int i; 
	for(i=0;i<n-1;i++){ 
		printf("(%d,%d)=%d\n",T[i].fromvex,T[i].tovex,T[i].length); 
	} 
} 

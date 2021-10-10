#ifndef PRIM_H
#define PRIM_H

#include <stdio.h> 
#include <malloc.h> 
#include <limits.h> 
#define INFINITY INT_MAX                              // INT_MAX表示最大整数，请参阅C的limits.h文件 
#define n 10                                          // 图的顶点数，应由用户定义 
typedef int AdjMatrix[n][n];                          // 用二维数组作为邻接矩阵表示 

typedef struct{                                       // 树边结点                                     
	int fromvex;
	int tovex;                                        // 边的起点和终点 
	int length;                                       // 边上的权 
}TreeEdgeNode; 

typedef TreeEdgeNode MST[n-1];                        // 最小生成树类型 

AdjMatrix	G;                                        // 连通网的带权邻接矩阵,作为Prim算法的输入 
MST 		T;                                        // 存放G的最小生成树，作为Prim算法的输出 

void Error(char *msg);                                // 打印错误信息 

void CreateGraph(AdjMatrix G);

void DefaultCreateGraph(AdjMatrix G);

void InitCandidateSet(AdjMatrix G,MST T,int r);       // 构造初始的时候选轻边集T[0...n-2]，树边集TE!=Null,红点集U={r} 
 
int SelectLightEdge(MST T,int k);                     // 在当前候选轻边集中选择一条轻边,即选择长度最短的紫边

void ModifyCandidateSet(AdjMatrix G,MST T,int k,int v);// 调整候选边集 

void PrimMST(AdjMatrix G,MST T,int r);                // 求图G的以r为根的MST,r为开始的结点 

void PrintMST(MST T);

#endif // PRIM_H

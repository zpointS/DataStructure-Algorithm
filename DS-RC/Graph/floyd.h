#ifndef FLOYD_H
#define FLOYD_H

#include <stdio.h>
#include <stdlib.h>

#define INFINITY 	32767  // int型的最大值为∞
#define MAX_VEX_NUM 30     // 最大顶点个数
typedef struct{  
	char	vexs[MAX_VEX_NUM+1]; // 顶点信息
	int		arcs[MAX_VEX_NUM+1][MAX_VEX_NUM+1]; // 邻接矩阵存放权值
    int		vexnum; // 顶点数,
	int 	arcnum; // 弧(边)数
}AdjGraph;

int CenterVex(AdjGraph *g); // 带权图的邻接矩阵建立
AdjGraph *CreateAdjGrahp(); // Floyd算法

#endif // FLOYD_H

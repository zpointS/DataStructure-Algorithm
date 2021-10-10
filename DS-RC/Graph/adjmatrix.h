#ifndef ADJMATRIX_H
#define ADJMATRIX_H

#include "common.h"

typedef struct ArcNode
{
	int adj;
} ArcNode;

typedef struct
{
	VertexData	vexs[N];
	ArcNode		arcs[N][N];
	int			vexnum; 
	int			arcnum;
	GraphKind	kind;
}AdjMatrix;

int LocateVertex(AdjMatrix *g, VertexData v);

int CreateUDG(AdjMatrix *g);

void DFS(AdjMatrix g,int v);

void Traverse(AdjMatrix g);

#endif // END ADJMATRIX_H

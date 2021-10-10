#ifndef ADJLIST_H
#define ADJLIST_H

#include "common.h"

typedef struct ArcNode_   // 边节点 
{
	int 			adjvex;
	struct ArcNode_ *nextarc;
} ArcNode_;   

typedef struct VertexNode // 定点节点 
{
	VertexData	data;
	ArcNode_ 	*firstarc;
}VertexNode;

typedef struct
{
	VertexNode	vertex[N]; // 图中每个定点与之相邻的定点链表 
	int 		vexnum_;
	int			arcnum_;  // 图中的定点数和边数 
	GraphKind	kind_;
}AdjList;

int LocateVertex_(AdjList *g, VertexData v);

int CreateUDG_(AdjList *g);

void DFS_(AdjList g,int vo);

void BFS_(AdjList g,int vo);

void Traverse_(AdjList g);

void Visit(AdjList *g);

#endif // END ADJLIST_H

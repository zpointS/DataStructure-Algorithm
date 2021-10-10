#ifndef ADJLIST_H
#define ADJLIST_H

#include "common.h"

typedef struct ArcNode_   // �߽ڵ� 
{
	int 			adjvex;
	struct ArcNode_ *nextarc;
} ArcNode_;   

typedef struct VertexNode // ����ڵ� 
{
	VertexData	data;
	ArcNode_ 	*firstarc;
}VertexNode;

typedef struct
{
	VertexNode	vertex[N]; // ͼ��ÿ��������֮���ڵĶ������� 
	int 		vexnum_;
	int			arcnum_;  // ͼ�еĶ������ͱ��� 
	GraphKind	kind_;
}AdjList;

int LocateVertex_(AdjList *g, VertexData v);

int CreateUDG_(AdjList *g);

void DFS_(AdjList g,int vo);

void BFS_(AdjList g,int vo);

void Traverse_(AdjList g);

void Visit(AdjList *g);

#endif // END ADJLIST_H

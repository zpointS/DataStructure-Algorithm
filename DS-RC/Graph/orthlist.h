#ifndef ORTHLIST_H
#define ORTHLIST_H

/*图的十字链表结构形式化定义如下：*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM	20              /*最多顶点个数*/
#define INFINITY		32768           /*表示极大值，即∞*/
#define True			1
#define False			0
#define Error 			-1
#define Ok 				1

typedef enum
{DG, DN,  UDG,  UDN} 
GraphKind;  /*图的种类*/
typedef char VertexData;    /*假设顶点数据为字符型*/

typedef struct ArcNode 
{
	int				tailvex;
	int				headvex;  
	struct ArcNode	*hlink;
	struct ArcNode	*tlink;    
}ArcNode;

typedef struct VertexNode
{
	VertexData	data;    /*顶点信息*/
	ArcNode		*firstin;
	ArcNode		*firstout;   
}VertexNode;

typedef struct
{
	VertexNode	vertex[MAX_VERTEX_NUM];   
	int			vexnum;
	int			arcnum;   /*图的顶点数和弧数*/
	GraphKind	kind;     /*图的种类*/
}OrthList;      /*图的十字链表表示法(Orthogonal List)*/

void  CrtOrthList(OrthList *g);

int _LocateVertex(OrthList *G,VertexData v);

#endif // ORTHLIST_H

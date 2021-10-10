#ifndef ORTHLIST_H
#define ORTHLIST_H

/*ͼ��ʮ������ṹ��ʽ���������£�*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM	20              /*��ඥ�����*/
#define INFINITY		32768           /*��ʾ����ֵ������*/
#define True			1
#define False			0
#define Error 			-1
#define Ok 				1

typedef enum
{DG, DN,  UDG,  UDN} 
GraphKind;  /*ͼ������*/
typedef char VertexData;    /*���趥������Ϊ�ַ���*/

typedef struct ArcNode 
{
	int				tailvex;
	int				headvex;  
	struct ArcNode	*hlink;
	struct ArcNode	*tlink;    
}ArcNode;

typedef struct VertexNode
{
	VertexData	data;    /*������Ϣ*/
	ArcNode		*firstin;
	ArcNode		*firstout;   
}VertexNode;

typedef struct
{
	VertexNode	vertex[MAX_VERTEX_NUM];   
	int			vexnum;
	int			arcnum;   /*ͼ�Ķ������ͻ���*/
	GraphKind	kind;     /*ͼ������*/
}OrthList;      /*ͼ��ʮ�������ʾ��(Orthogonal List)*/

void  CrtOrthList(OrthList *g);

int _LocateVertex(OrthList *G,VertexData v);

#endif // ORTHLIST_H

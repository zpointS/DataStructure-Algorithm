#ifndef PRIM_H
#define PRIM_H

#include <stdio.h> 
#include <malloc.h> 
#include <limits.h> 
#define INFINITY INT_MAX                              // INT_MAX��ʾ��������������C��limits.h�ļ� 
#define n 10                                          // ͼ�Ķ�������Ӧ���û����� 
typedef int AdjMatrix[n][n];                          // �ö�ά������Ϊ�ڽӾ����ʾ 

typedef struct{                                       // ���߽��                                     
	int fromvex;
	int tovex;                                        // �ߵ������յ� 
	int length;                                       // ���ϵ�Ȩ 
}TreeEdgeNode; 

typedef TreeEdgeNode MST[n-1];                        // ��С���������� 

AdjMatrix	G;                                        // ��ͨ���Ĵ�Ȩ�ڽӾ���,��ΪPrim�㷨������ 
MST 		T;                                        // ���G����С����������ΪPrim�㷨����� 

void Error(char *msg);                                // ��ӡ������Ϣ 

void CreateGraph(AdjMatrix G);

void DefaultCreateGraph(AdjMatrix G);

void InitCandidateSet(AdjMatrix G,MST T,int r);       // �����ʼ��ʱ��ѡ��߼�T[0...n-2]�����߼�TE!=Null,��㼯U={r} 
 
int SelectLightEdge(MST T,int k);                     // �ڵ�ǰ��ѡ��߼���ѡ��һ�����,��ѡ�񳤶���̵��ϱ�

void ModifyCandidateSet(AdjMatrix G,MST T,int k,int v);// ������ѡ�߼� 

void PrimMST(AdjMatrix G,MST T,int r);                // ��ͼG����rΪ����MST,rΪ��ʼ�Ľ�� 

void PrintMST(MST T);

#endif // PRIM_H

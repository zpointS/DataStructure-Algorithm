#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define X 			10000
#define VertexNum 	7  //ʵ���Ϲ����������㣨1--6��
#define EdgeNum  	9



int Visited[VertexNum];
int path[VertexNum];
int Distance[VertexNum];

void Dijkstra(int Begin);

#endif // DIJKSTRA_H

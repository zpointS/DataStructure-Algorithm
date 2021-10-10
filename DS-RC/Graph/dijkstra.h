#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define X 			10000
#define VertexNum 	7  //实际上共有六个顶点（1--6）
#define EdgeNum  	9



int Visited[VertexNum];
int path[VertexNum];
int Distance[VertexNum];

void Dijkstra(int Begin);

#endif // DIJKSTRA_H

#include "dijkstra.h"
int Graph_[VertexNum][VertexNum] =
//0  1  2  3  4  5  6
{ X, X, X, X, X, X, X,  //0
  X, X, 6, 3, X, X, X,  //1
  X, X, X, X, 5, X, X,  //2
  X, X, 2, X, 3, 4, X,  //3
  X, X, X, X, X, X, 3,  //4
  X, X, X, X, 2, X, 5,  //5
  X, X, X, X, X, X, X   //6
};

void Dijkstra(int Begin)
{
  int MinEdge;
  int Vertex;
  int i;
  int j;
  int Edges;
  
  Edges = 1;
  Visited[Begin] = 1;
  for (i = 1; i<VertexNum; i++)
  {
  	Distance[i] = Graph_[Begin][i];
  } 

  Distance[Begin] = 0;
  printf("     1  2  3  4  5  6\n");
  printf("-----------------------------------\n");
  printf("s:%d", Edges);
  for( i=1; i<VertexNum; i++)
  if(Distance[i] == X) 
  {
  	printf("  *");
  }
  else
  {
  	printf("%3d",Distance[i]);
  } 
  printf("\n");
  while( Edges<VertexNum-1)
  {
    Edges++; MinEdge = X;
    for(j=1; j<VertexNum; j++)
    {
    	if (Visited[j]==0 && MinEdge > Distance[j] )
	    {
	 		Vertex = j;
		  	MinEdge = Distance[j];
	    }
	    Visited[Vertex] = 1;
	    printf("s:%d",Edges);
    }
    
    for(j=1; j<VertexNum; j++)
    {
      if (Visited[j] == 0 && Distance[Vertex] + Graph_[Vertex][j] <Distance[j])
      {   
	  	  Distance[j] = Distance[Vertex] + Graph_[Vertex][j];
		  path[j] = Vertex;
      }
       if (Distance[j] == X)
   		{
       	printf("  *"); 
       } 
   		else
   		{
       	printf("%3d",Distance[j]);
       } 
    }
    printf("\n");
  }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  N 20
#define  M (2*N-1)

typedef char* HuffmanCode;

typedef struct 
{
	unsigned int weight; /* 用来存放各个结点的权值*/
	unsigned int parent;
	unsigned int LChild;
	unsigned int RChild; 
}HTNode, * HuffmanTree;

void select(HuffmanTree *ht,int n, int *s1, int *s2);

void CrtHuffmanTree(HuffmanTree *ht , int *w, int n);

void OutputHuffman(HuffmanTree HT, int m);

void CrtHuffmanCode(HuffmanTree *ht, HuffmanCode *hc, int n);

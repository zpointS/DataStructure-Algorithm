#include "huffman.h"

int main(int argc, char *argv[])
{
	HuffmanTree HT; 
	HuffmanCode HC; 
	int *w; 
	int i,n;      // the number of elements; 
	int wei;    // the weight of a element; 
	int m;
	
	printf("input the total number of the Huffman Tree:" ); 
	scanf("%d",&n); 
	w=(int *)malloc((n+1)*sizeof(int)); 
	for(i=1;i<=n;i++)
	{ 
		printf("input the %d element's weight:",i); 
		fflush(stdin);
		scanf("%d",&wei); 
		w[i]=wei; 
	} 

	CrtHuffmanTree(&HT,w,n); 
	m = 2*n-1;
	OutputHuffman(HT,m); 
	printf("\n");
	CrtHuffmanCode(&HT,&HC,n);
	
	return 0;
}

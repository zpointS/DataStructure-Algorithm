#include "huffman.h"

void select(HuffmanTree *ht,int n, int *s1, int *s2)
{
	int i;
	int min;
	for(i=1; i<=n; i++)
	{
		if((*ht)[i].parent == 0)
		{
			min = i;
			i = n+1;
		}
	}
	for(i=1; i<=n; i++)
	{
		if((*ht)[i].parent == 0)
		{
			if((*ht)[i].weight < (*ht)[min].weight)
			{
				min = i;
			}	
		}
	}
	*s1 = min;
	for(i=1; i<=n; i++)
	{
		if((*ht)[i].parent == 0 && i!=(*s1))
		{
			min = i;
			i = n+1;
		}
	}
	for(i=1; i<=n; i++)
	{
		if((*ht)[i].parent == 0 && i!=(*s1))
		{
			if((*ht)[i].weight < (*ht)[min].weight)
				min = i;
		}
	}
	*s2 = min;
}

/* w�����֪��n��Ȩֵ�������������ht */
void CrtHuffmanTree(HuffmanTree *ht , int *w, int n)
{ 
	int m;
	int i;
	int s1;
	int s2;
	
	m=2*n-1;
	*ht=(HuffmanTree)malloc((m+1)*sizeof(HTNode));  /*0�ŵ�Ԫδʹ��*/
	for(i=1;i<=n;i++) 
	{
		(*ht)[i].weight = w[i];
		(*ht)[i].LChild = 0;
		(*ht)[i].parent = 0;
		(*ht)[i].RChild = 0;
	}		
	for(i=n+1;i<=m;i++)
	{
		(*ht)[i].weight = 0;
		(*ht)[i].LChild = 0;
		(*ht)[i].parent = 0;
		(*ht)[i].RChild = 0;
	}    /*��Ҷ�ӽ���ʼ��*/
	
	for(i=n+1;i<=m;i++)    /*������Ҷ�ӽ��,����������*/
	{
		select(ht,i-1,&s1,&s2);
		(*ht)[s1].parent=i;
		(*ht)[s2].parent=i;
		(*ht)[i].LChild=s1;
		(*ht)[i].RChild=s2;
		(*ht)[i].weight=(*ht)[s1].weight+(*ht)[s2].weight;
	} 
}

void OutputHuffman(HuffmanTree HT, int m)
{
	if(m!=0)
	{
		printf("%d  ", HT[m].weight);
		OutputHuffman(HT,HT[m].LChild);
		OutputHuffman(HT,HT[m].RChild);
	}
}

/*��Ҷ�ӽ�㵽����������ÿ��Ҷ�ӽ���Ӧ�Ĺ���������*/
void CrtHuffmanCode(HuffmanTree *ht, HuffmanCode *hc, int n)
{
	char			*cd;
	int				i;
	unsigned int	c;
	int				start;
	int				p;
	
	hc=(HuffmanCode *)malloc((n+1)*sizeof(char *));  /*����n�������ͷָ��*/
	cd=(char * )malloc(n * sizeof(char ));  		 /*������ǰ����Ĺ����ռ�*/
	cd[n-1]='\0';   /*����������λ��ű��룬���ȴ�ű��������*/
	
	for(i=1;i<=n;i++)  /*��n��Ҷ�ӽ���Ӧ�Ĺ���������*/
	{
		start=n-1;    /*��ʼ��������ʼָ��*/
		for(c=i,p=(*ht)[i].parent; p!=0; c=p,p=(*ht)[p].parent) /*��Ҷ�ӵ�����������*/
			if( (*ht)[p].LChild == c) 
				cd[--start]='0';  /*���֧��0*/
			else 
				cd[--start]='1';  /*�ҷ�֧��1*/
	hc[i]=(char *)malloc((n-start)*sizeof(char));  /*Ϊ��i���������ռ�*/
	strcpy(hc[i],&cd[start]);
	}
	free(cd);
	for(i=1;i<=n;i++)
	{
		printf("%d����Ϊ%s\n",(*ht)[i].weight,hc[i]);
	}	
}

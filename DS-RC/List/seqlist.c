#include <stdlib.h>
#include <stdio.h>
#include "seqlist.h"

void InitialSeqList(SeqList * L, int n)
{
	L->elem = (ElemType *)malloc(sizeof(ElemType)*n);
	memset(L->elem, 0, sizeof(ElemType)*n);
	L->length = n;
	L->last = 0;
}

void DestroySeqList(SeqList * L)
{
	if(L->elem)
		free(L->elem);
	L->length = 0;
	L->last = 0;
}

void SetRandNumSeqList(SeqList * L, int n)
{
	int i;
	if(L->elem==NULL || L->length < n)
		return;
	for(i=0; i<n; i++)
		L->elem[i] = rand()%100;
	L->last = n-1;
}

int  LocateSeqList(SeqList L, ElemType e)
{	
	int i=0;                            /*i为扫描计数器，初值为0，即从第一个元素开始比较*/
	while ((i<=L.last)&&(L.elem[i]!=e))	/*顺序扫描表，直到找到值为key的元素, 或扫描到表尾而没找到*/
	{
		i++;
	}	 
	if  (i<=L.last)                    /*若找到值为e的元素，则返回其下标序号*/
	{
		return(i);
	}	                  
	else
	{
		return(-1);                     /*若没找到，则返回空序号*/
	}
}

int  InsertSeqList(SeqList *L, int pos, ElemType e)
{ 
	int	k;
	
	if((pos<0) || pos>=L->length)       /*首先判断插入位置是否合法*/
	{
		printf("InsertSeqList over range\n");
		return(ERROR);
	}
	for(k=L->last;k>=pos;k--)        /* 为插入元素而移动位置 */
		L->elem[k+1]=L->elem[k];
	L->elem[pos]=e;                  /* 在C语言数组中，第i个元素的下标为i-1 */
	L->last++;
	return(OK);
}

int  DeletSeqList(SeqList *L, int i)
{ 
	int	k;
	
	if((i<1)||(i>L->last+1))   
	{ 
		printf("删除位置不合法!");
		return(ERROR);
	}
	for(k=i; i<=L->last; k++)
		L->elem[k-1] = L->elem[k];   /* 将后面的元素依次前移 */
	L->last--;
	return(OK);
}

void ShowSeqList(SeqList *L, char *gvfilename)
{
	int i;
	FILE *fp = fopen(gvfilename,"w+");
	fprintf(fp,"digraph SeqList { \n");
	fprintf(fp,"node [fontname = \"Microsoft YaHei\", color=darkgreen, shape=record, height=.1]; \n");
	fprintf(fp,"edge [fontname = \"Microsoft YaHei\", color=darkgreen, style=solid]; \n");
	
	fprintf(fp,"struct [ label = \"{val|add}");
	for(i=0; i<L->last; i++)
		fprintf(fp," | {%2d|%2d}", L->elem[i], i);
	for(i=L->last; i<L->length; i++)
		fprintf(fp," | {NA|%2d}", i);	
	fprintf(fp,"\"]; \n}\n");
	fclose(fp);
}

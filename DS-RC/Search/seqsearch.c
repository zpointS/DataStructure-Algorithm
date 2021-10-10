#include "seqsearch.h"

void createlist(RecordList *l)
{
	int 	i;
	int 	len;
	KeyType ch;

	printf("请输入线性表的长度:");
	scanf("%d",&len);
	l->length = len;
	for(i=1; i<=len; i++)
	{
		printf("请输入线性表的第%d个元素:",i);
		fflush(stdin);
		scanf("%c",&ch);
		l->r[i].key = ch;
	}
}

/*在顺序表l中顺序查找其关键字等于k的元素，若找到，则函数值为该元素在表中的位置，否则为0*/
int SeqSearch(RecordList  l,  KeyType  k)
{
	int i;
	l.r[0].key=k; 
	i=l.length;
	while (l.r[i].key!=k)
	{
		i--;
	}  
	
	return(i);
}

/*不用"监视哨"法，在顺序表中查找关键字等于k的元素*/
int SeqSearch2(RecordList l,  KeyType k)
{
	int i;
	i = l.length;
	while (i>=1&&l.r[i].key!=k)  i--;
	if (i>=1) 
	{
		return(i);
	}	
	else
	{
		return (0);
	}	
}

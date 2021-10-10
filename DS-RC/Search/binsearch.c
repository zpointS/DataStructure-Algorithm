#include "binsearch.h"

void createlist_(RecordList *l)
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

/*在有序表l中折半查找其关键字等于k的元素，若找到，则函数值为该元素在表中的位置*/
int BinSrch(RecordList  l,  KeyType  k)
{
	int low;
	int high;
	int mid;
	
	low=1;  
	high=l.length;/*置区间初值*/
	while( low <= high)
	{
		mid=(low+high) / 2;
		if  (k==l.r[mid]. key)  
		{
			return (mid);/*找到待查元素*/
		}	
		else  
		{
			if (k<l.r[mid]. key) 
			{
				high=mid-1;/*未找到，则继续在前半区间进行查找*/
			}	
			else  
			{
				low=mid+1;/*继续在后半区间进行查找*/
			}	
		}	
	}

	return (0);
}

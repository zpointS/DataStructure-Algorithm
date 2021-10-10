#include "binsearch.h"

void createlist_(RecordList *l)
{
	int 	i;
	int 	len;
	KeyType ch;
	
	printf("���������Ա�ĳ���:");
	scanf("%d",&len);
	l->length = len;
	for(i=1; i<=len; i++)
	{
		printf("���������Ա�ĵ�%d��Ԫ��:",i);
		fflush(stdin);
		scanf("%c",&ch);
		l->r[i].key = ch;
	}
}

/*�������l���۰������ؼ��ֵ���k��Ԫ�أ����ҵ�������ֵΪ��Ԫ���ڱ��е�λ��*/
int BinSrch(RecordList  l,  KeyType  k)
{
	int low;
	int high;
	int mid;
	
	low=1;  
	high=l.length;/*�������ֵ*/
	while( low <= high)
	{
		mid=(low+high) / 2;
		if  (k==l.r[mid]. key)  
		{
			return (mid);/*�ҵ�����Ԫ��*/
		}	
		else  
		{
			if (k<l.r[mid]. key) 
			{
				high=mid-1;/*δ�ҵ����������ǰ��������в���*/
			}	
			else  
			{
				low=mid+1;/*�����ں��������в���*/
			}	
		}	
	}

	return (0);
}

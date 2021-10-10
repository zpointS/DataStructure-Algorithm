#include "merge.h"

/* ��֪r1[low..mid]��r1[mid+1..high]�ֱ𰴹ؼ����������У������Ǻϲ���һ���������У������r2[low..high] */
void Merge(RecordType r1[],  int low,   int mid,   int high,  RecordType  r2[])
{ 
	int i;
	int j;
	int k;
	
	i=low;
	j=mid+1;
	k=low;
	while ( (i<=mid)&&(j<=high)  )
	{
		if ( r1[i].key<=r1[j].key )
		{
			r2[k]=r1[i];
			++i;
		}
		else 
		{
			r2[k]=r1[j];
			++j;
		}
		++k;
	}
	while( i<=mid )
	{
		r2[k]=r1[i];
		k++;
		i++;
	}
	while( j<=high)
	{
		r2[k]=r1[j];
		k++;
		j++;
	}
} /* Merge */ 

/* r1[low..high]������������r3[low..high]�У�r2[low..high]Ϊ�����ռ� */ 
void   MSort(RecordType r1[], int low, int high, RecordType r3[])
{
	int 		mid;
	RecordType  r2[20];
	if ( low==high ) 
	{
		r3[low]=r1[low];
	}	
	else
	{
		mid=(low+high)/2;
        MSort(r1,low, mid, r2);
        MSort(r1,mid+1,high, r2);
        Merge (r2,low,mid,high, r3);
	}
} /*   MSort  */ 

/* �Լ�¼����r[1..n]���鲢���� */ 
void MergeSort ( RecordType  r[],  int  n )
{
	MSort ( r,  1,  n,  r );
}

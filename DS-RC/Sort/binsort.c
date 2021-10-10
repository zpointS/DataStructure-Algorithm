#include "binsort.h" 

void    BinSort (RecordType  r[],  int length)
/*�Լ�¼����r�����۰��������lengthΪ����ĳ���*/
{
	int 		i;
	int 		j;
	RecordType 	x;
	int 		low;
	int 		high;
	int 		mid;
	
	for (  i=2; i<=length ; ++i ) 
	{
		x= r[i];
		low=1; 
		high=i-1;
		while (low<=high )                  /* ȷ������λ��*/ 
		{
			mid=(low+high) / 2;
			if (  x.key< r[mid].key   )    
			{
				high=mid-1;
			}	
			else 
			{
				low=mid+1;
			}	
		}
		for(j = i-1; j >= low; --j )
		{
			r[j+1]= r[j];         /*  ��¼��������ƶ� */ 
		}   
		r[low]=x;                 /* �����¼ */ 
	}
}/*BinSort*/

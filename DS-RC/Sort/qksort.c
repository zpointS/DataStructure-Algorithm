#include "qksort.h"

// �Լ�¼����r �е�r[left]��r[right]���ֽ���һ������
// ���õ���׼��λ�ã�ʹ�������Ľ��������֮��ǰ���ļ�¼��
// �ؼ��־���С�ڣ����ڣ��ڻ�׼��¼*/
int QKPass(RecordType r[],int left, int right)
{ 
	RecordType 	x;
	int 		low;
	int 		high;
	
	x= r[left];             /* ѡ���׼��¼*/ 
	low=left;  
	high=right;
	
	while(low<high)
	{
		while(low< high && r[high].key>=x.key) 
		{
			high--;
		}	
		if(low <high) 
		{ 
			r[low]= r[high];
			low++;
		}  
		/* �ҵ�С��x.key�ļ�¼������н���*/
		while(low<high && r[low].key<x.key)    /* low�������Ҵ���x.key�ļ�¼ */
		{
			low++; 
		}	
		if(low<high)
		{ 
			r[high]= r[low];
			high--; 
		} /* �ҵ�����x.key�ļ�¼���򽻻�*/
	}
	r[low]=x;                     /*����׼��¼���浽low=high��λ��*/
	return low;                   /*���ػ�׼��¼��λ��*/
} /* QKPass */ 

/*�Լ�¼����r[low..high]�ÿ��������㷨��������*/
void QKSort(RecordType r[],int low, int high )
{
	int pos;
	if(low<high)
	{
		pos=QKPass(r, low, high);  /*����һ�˿������򣬽�����Ԫ��Ϊ�绮�������ӱ�*/
		QKSort(r, low, pos-1);     /*�����ӱ��������*/
		QKSort(r, pos+1, high); /*���Ҳ��ӱ��������*/	
	}
}

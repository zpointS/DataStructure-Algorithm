#include "heapsort.h"

// �����[k..m]���ԣ�[k]Ϊ������ȫ���������ҷֱ��ԣ�[2k]�ͣ�[2k+1]Ϊ����
// ��������Ϊ����ѣ�����r[k]��ʹ��������r[k..m]����ѵ�����
void sift(RecordType r[], int k, int m)
{
	RecordType 	t;
	int 		i;
	int 		j;
	int 		x;
	int 		finished;
	
	t= r[k];          /* �ݴ�"��"��¼r[k] */ 
	x=r[k].key;
	i=k;
	j=2*i;
	finished=FALSE;
	while(j<=m && !finished) 
	{     
		if (j<m  && r[j].key< r[j+1].key ) 
		{    
			j=j+1;  /* �������������������������Ĺؼ��ִ������ҷ�֧"ɸѡ" */
		}
		if ( x>= r[j].key)
		{
			finished=TRUE;            /*  ɸѡ���  */ 
		}	
		else 
		{
			r[i] = r[j];
			i=j;
			j=2*i;
		}    /* ����ɸѡ */ 
	}
	r[i] =t;          /* r[k]���뵽ǡ����λ�� */ 
}
  
/*�Լ�¼����r���ѣ�lengthΪ����ĳ���*/
void crt_heap(RecordType r[], int length )
{
	int i;
	int n;
	
    n= length;
	for ( i=n/2; i >= 1; --i)         /* �Ե�[n/2]����¼��ʼ����ɸѡ���� */ 
	{
		sift(r,i,n);
	}	
}

/* ��r[1..n]���ж�����ִ�б��㷨��r�м�¼���ؼ����ɴ�С�������� */ 
void HeapSort(RecordType r[], int length)
{
	int 		i;
	int 		n;
	RecordType	b;
	
	crt_heap(r, length);
	n= length;
	for (  i=n ; i>= 2; --i) 
	{
		b=r[1];              /* ���Ѷ���¼�Ͷ��е����һ����¼���� */ 
		r[1]= r[i];
		r[i]=b; 
		sift(r,1,i-1);  /* ���е�����ʹr[1..i-1]��ɶ� */ 
	}
} /* HeapSort */ 

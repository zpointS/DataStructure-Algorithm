#include "radixsort.h"

// ��¼����r�м�¼�Ѱ���λ�ؼ���key[i+1]������key[d]���й�"��λ����"����
// ���㷨����iλ�ؼ���key[i]����RADIX�����У�ͬһ�������м�¼��key[i]��ͬ��
// head[j]��tail[j]�ֱ�ָ��������е�һ�������һ����¼��j=0��1��2������RADIX-1����
// head[j]=0��ʾ��Ӧ����Ϊ�ն���
void   Distribute(RecordType1 r[],  int  i,  PVector head,  PVector tail)
{
	int j;
	int p;
	for ( j=0 ; j<=RADIX-1 ; ++j)
		head[j]=0;                        /* ��RADIX�����г�ʼ��Ϊ�ն��� */ 
		p= r[0].next;                     /* pָ�������еĵ�һ����¼ */ 
		while( p!=0 ) 
		{
			j=r[p].key[i];                /* �ü�¼�е�iλ�ؼ�������Ӧ���к� */
			if  ( head[j]==0 ) 
			{
				head[j]=p;                /* ��p��ָ��Ľ������j�������� */ 	
			}
			else
			{
				r[tail[j]].next=p;
			}	
			tail[j]=p;
			p= r[p].next;
		}
}
 
/* ���㷨��0��RADIX-1 ɨ������У������зǿն�����β��ӣ��������ӳ�һ������ */ 
void  Collect(RecordType1  r[],  PVector head,  PVector tail)
{
	int j;
	int t;
	j=0;
	while (head[j]==0 )                 /* �ҵ�һ���ǿն��� */ 
	{
		++j;
	}	
	r[0].next =head[j];
	t=tail[j];
	while ( j<RADIX-1 )                 /* Ѱ�Ҳ��������зǿն��� */
	{
		++j;
		while ( (j<RADIX-1 ) && (head[j]==0 ) )     /* ����һ���ǿն��� */ 
		{
			++j;
		}	
		if ( head[j]!=0 )       /* ���ӷǿն��� */ 
		{
			r[t].next =head[j];
			t=tail[j];
		} 
	}
	r[t].next =0;              /* tָ�����һ���ǿն����е����һ����� */ 
}   /* Collect */ 

/* length����¼���������r�У�ִ�б��㷨���л�������������еļ�¼�����ؼ��ִ�С�����˳�������ӡ� */ 
void  RadixSort (RecordType1 r[],int length )
{
	int 	i;
	int 	n;
	int 	d;
	PVector head;
	PVector tail;
    
	n= length;
	for ( i=0 ; i<= n-1 ; ++i)  
	{
		r[i].next=i+1;  /* ���쾲̬���� */
	}	
	r[n].next =0;
	d= 3;
	for ( i =d-1; i>= 0; --i )       /* �����λ�ӹؼ��ֿ�ʼ������d�˷�����ռ�*/
	{ 
		Distribute(r,i,head,tail);  /* ��i�˷��� */ 
		Collect(r,head,tail);       /* ��i���ռ� */ 
	}
}

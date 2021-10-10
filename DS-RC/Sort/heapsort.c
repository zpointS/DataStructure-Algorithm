#include "heapsort.h"

// 假设ｒ[k..m]是以ｒ[k]为根的完全二叉树，且分别以ｒ[2k]和ｒ[2k+1]为根的
// 左、右子树为大根堆，调整r[k]，使整个序列r[k..m]满足堆的性质
void sift(RecordType r[], int k, int m)
{
	RecordType 	t;
	int 		i;
	int 		j;
	int 		x;
	int 		finished;
	
	t= r[k];          /* 暂存"根"记录r[k] */ 
	x=r[k].key;
	i=k;
	j=2*i;
	finished=FALSE;
	while(j<=m && !finished) 
	{     
		if (j<m  && r[j].key< r[j+1].key ) 
		{    
			j=j+1;  /* 若存在右子树，且右子树根的关键字大，则沿右分支"筛选" */
		}
		if ( x>= r[j].key)
		{
			finished=TRUE;            /*  筛选完毕  */ 
		}	
		else 
		{
			r[i] = r[j];
			i=j;
			j=2*i;
		}    /* 继续筛选 */ 
	}
	r[i] =t;          /* r[k]填入到恰当的位置 */ 
}
  
/*对记录数组r建堆，length为数组的长度*/
void crt_heap(RecordType r[], int length )
{
	int i;
	int n;
	
    n= length;
	for ( i=n/2; i >= 1; --i)         /* 自第[n/2]个记录开始进行筛选建堆 */ 
	{
		sift(r,i,n);
	}	
}

/* 对r[1..n]进行堆排序，执行本算法后，r中记录按关键字由大到小有序排列 */ 
void HeapSort(RecordType r[], int length)
{
	int 		i;
	int 		n;
	RecordType	b;
	
	crt_heap(r, length);
	n= length;
	for (  i=n ; i>= 2; --i) 
	{
		b=r[1];              /* 将堆顶记录和堆中的最后一个记录互换 */ 
		r[1]= r[i];
		r[i]=b; 
		sift(r,1,i-1);  /* 进行调整，使r[1..i-1]变成堆 */ 
	}
} /* HeapSort */ 

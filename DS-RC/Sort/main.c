// #include "inssort.h"
// #include "binsort.h"
// #include "shellinsert.h"
// #include "bubblesort.h"
// #include "qksort.h"
// #include "selectsort.h"
// #include "heapsort.h"
// #include "merge.h"
// #include "radixsort.h"

/*
*********************************************************************************************************
*                                        main 测试实现的9种排序 
*
* Description: main函数用于实现9种排序算法的测试，通过取消头文件引用前的注释来实现对应的方法的测试，每次 
*              只能取消一个注释，否则将会出现错误。 
*
*********************************************************************************************************
*/ 

int main(int argc, char *argv[])
{

#ifdef INSSORT_H
	int 		i;
	int 		j;
	RecordType 	r[20];
	int 		len;

	printf("请输入待排序记录的长度:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("请输入第%d个记录元素:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key);
	}	
	printf("\n");

	InsSort(r,len);
	for(i=1;i<=len;i++)
		printf("%d  ",r[i].key);
	printf("\n");
#endif

#ifdef BINSORT_H
	int 		i;
	int 		j;
	RecordType 	r[20];
	int 		len;

	printf("请输入待排序记录的长度:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("请输入第%d个记录元素:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key);
	}	
	printf("\n");
	
	BinSort(r,len);
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key);
	}	
	printf("\n");
#endif

#ifdef SHELLINSERT_H
	int 		i;
	int 		j;
	RecordType 	r[20];
	int 		len;
	int 		delta[3]={4,2,1};
	
	printf("请输入待排序记录的长度:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("请输入第%d个记录元素:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key);
	}	
	printf("\n");
	
	ShellSort(r,len,delta,3);
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key);
	}	
	printf("\n");
#endif

#ifdef BUBBLESORT_H
	int 		i;
	int 		j;
	RecordType 	r[20];
	int 		len;
	
	printf("请输入待排序记录的长度:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("请输入第%d个记录元素:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key);
	}	
	printf("\n");
	
	BubbleSort(r,len);
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key);
	}	
	printf("\n");
#endif

#ifdef QKSORT_H
	int 		i;
	int 		j;
	RecordType 	r[20];
	int 		len;
	
	printf("请输入待排序记录的长度:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("请输入第%d个记录元素:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key);
	}	
	printf("\n");
	QKSort(r,1,len);
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key);
	}	
	printf("\n");
#endif

#ifdef SELECTSORT_H
	int 		i;
	int 		j;
	RecordType 	r[20];
	int 		len;
	
	printf("请输入待排序记录的长度:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("请输入第%d个记录元素:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key);
	}	
	printf("\n");
	
	SelectSort(r,len);
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key);
	}	
	printf("\n");
#endif

#ifdef HEAPSORT_H
    int 		i;
	int 		j;
	RecordType 	r[20];
	int 		len;
	
	printf("请输入待排序记录的长度:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("请输入第%d个记录元素:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key);
	}	
	printf("\n");
	
	HeapSort(r,len);
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key);
	}	
	printf("\n");
#endif

#ifdef MERGE_H
	int 		i;
	int 		j;
	RecordType 	r[20];
	int 		len;
	
	printf("请输入待排序记录的长度:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("请输入第%d个记录元素:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key);
	}	
	printf("\n");
	MergeSort(r,len);
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key);
	}	
	printf("\n");
#endif

#ifdef RADIXSORT_H
	int 		i;
	int 		j;
	RecordType1 r[20];
	int 		len;
	int 		p;
	
	printf("请输入待排序记录的长度:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("请输入第%d个记录元素:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key[0] = j/100;
		r[i].key[1] = (j-100*r[i].key[0])/10;
		r[i].key[2] =(j-100*r[i].key[0]-10*r[i].key[1]);
	}
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key[0]*100+r[i].key[1]*10+r[i].key[2]);
	}	
	printf("\n");
	
	RadixSort(r,len);
	p = r[0].next;
	while(p!=0)
	{
		printf("%d  ",r[p].key[0]*100+r[p].key[1]*10+r[p].key[2]);
		p = r[p].next;
	}
	printf("\n");
	for(i=1;i<=len;i++)
	{
		printf("%d  ",r[i].key[0]*100+r[i].key[1]*10+r[i].key[2]);
	}	
	printf("\n");
#endif
	
	return 0;
}

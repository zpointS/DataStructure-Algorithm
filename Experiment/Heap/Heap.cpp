#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#define TOTALNUM 200

void HeapAdjust(int array[],int i,int nLength)
{
	//此函数实现的是向下调整
	//array[]是堆指针，i是节点编号，nLength是末尾节点编号
    int nChild;
    int nTemp;
    for(;2*i+1<nLength;i=nChild)//然后看他的孩子
    {
        nChild=2*i+1;
		//首先判断是否有右子树，然后找到两个孩子中的元素的较小值
        if(nChild<nLength-1&&array[nChild+1]<array[nChild])
			++nChild;
        if(array[i]>array[nChild])
        {
            nTemp=array[i];
            array[i]=array[nChild];
            array[nChild]=nTemp; 
        }
        else break;
    }
}

void DotHeap(int Heap[], int n, char *slabel,int input=-1, int drop=-1)
{
	FILE *fpTree=fopen("heapT.gv","w+");
	fprintf(fpTree,"digraph heapT {\n");
	fprintf(fpTree,"fontname = \"Microsoft YaHei\"; labelloc = t; labeljust = l; rankdir = TB;\n");
	fprintf(fpTree,"label = \"%s\";\n",slabel);
	fprintf(fpTree,"node [fontname = \"Microsoft YaHei\", color=indigo, shape=circle, height=.1];\n");
	fprintf(fpTree,"edge [fontname = \"Microsoft YaHei\", color=indigo, style=solid, arrowsize=0.7];\n");	
	
	if(input!=-1 && drop!=-1)//如果开始读后续的数据了，把这个新数据标出来
		fprintf(fpTree,"in%d[style=filled,label=\"%d\",shape=doubleoctagon,color=darkgoldenrod];\n",input,input);

	for(int i=0; i<n; i++)//先画出现有的堆(注意这个堆已经是更新后的了)
		fprintf(fpTree,"%d[label=\"%d\"];\n",Heap[i],Heap[i]);
	
	if(input!=-1 && drop!=-1 && input!=drop){//如果新的元素比旧元素大，即发生了更新
		fprintf(fpTree,"%d[style=filled,label=\"%d\",shape=doubleoctagon,color=darkgoldenrod];\n",input,input);
		fprintf(fpTree, "%d[label=\"%d\",shape=Msquare, height=.65];\n", Heap[0], Heap[0]);
	}
	if(input!=-1 && drop!=-1)
		if(input==drop)//如果新元素没有超过旧元素，即没有发生更新，则把原堆顶变成双圆
			fprintf(fpTree,"%d[style=filled, label=\"%d\",shape=doublecircle,color=seagreen];\n",Heap[0],Heap[0]);
	
	if(input!=-1 && drop!=-1)
		if(input!=drop)//若更新，则显示把哪个给更新掉了
			fprintf(fpTree,"dp%d[style=filled, label=\"%d\",shape=doublecircle,color=maroon];\n",drop,drop);
		else		   //若没有更新，则显示哪个没有被更新
			fprintf(fpTree,"dp%d[style=filled, label=\"%d\",shape=doubleoctagon,color=darkgoldenrod];\n",drop,drop);
	
	if(input!=-1 && drop!=-1)
	{
		fprintf(fpTree,"{rank = same; in%d; %d; dp%d;};\n",input,Heap[0],drop);
		fprintf(fpTree,"in%d -> %d[color=blue];\n",input,Heap[0]);
		fprintf(fpTree,"%d -> dp%d[color=red];\n",Heap[0],drop);
	}

	for(int i=0; i<n; i++)
	{
		if(2*(i+1)-1<n)
			fprintf(fpTree,"%d:sw -> %d;\n",Heap[i],Heap[2*(i+1)-1]);
		if(2*(i+1)<n)
			fprintf(fpTree,"%d:se -> %d;\n",Heap[i],Heap[2*(i+1)]);
	}

///////////////////////////////////////////////////////////	
	fprintf(fpTree,"node [fontname = \"Microsoft YaHei\", color=indigo, shape=record, height=.1];\n");
	fprintf(fpTree,"edge [fontname = \"Microsoft YaHei\", color=indigo, style=solid];\n");
	fprintf(fpTree,"struct [ label = \"{value|address} |");
	fprintf(fpTree,"{|%d} ",0);
	for(int i=0; i<n; i++)
		fprintf(fpTree,"| {%d|%d} ",Heap[i],i+1);
	fprintf(fpTree,"\"]; \n");
	fprintf(fpTree,"%d -> struct[color=white]; \n",Heap[n-1]);
//////////////////////////////////////////////////////////
	
	fprintf(fpTree,"}\n\n");
	fclose(fpTree);
	
}

int main(int argc, char *argv[])
{
	if(argc<2)
		printf("Order is Heap.exe filename.txt\n");
	
	char figlabel[128];
	char orderstr[128];
	int Heap[TOTALNUM]; //开一个足够大的数组，用于构造堆
	int Nnum, Heapsize;
	memset(Heap,'\0',sizeof(Heap));
	Nnum = 0;
	FILE *fp;
	fp = fopen(argv[1],"r+");


	Heapsize = 10;//TOP-K的K值
	//初始化堆
	while( Nnum<Heapsize && EOF != fscanf(fp,"%d",&Heap[Nnum++]));

	sprintf(figlabel, "Initial Heap");
	DotHeap(Heap,Nnum,figlabel);
	sprintf(orderstr, "dot.exe -Tpng heapT.gv -o IniT.png");
	system(orderstr);
	
	//调整初始堆
	//从最末尾节点的父节点开始调整，依次将前面的每一个节点都调整一遍
	for(int i=Nnum/2; i>=0; --i)
		HeapAdjust(Heap,i,Nnum);
	
	sprintf(figlabel, "Adjust Heap");
	DotHeap(Heap,Nnum,figlabel);
	sprintf(orderstr, "dot.exe -Tpng heapT.gv -o AdjT.png");
	system(orderstr);
		
	
	int temp;
	int i = Heapsize + 1; //从第11个数据开始读入
	//把后续的所有数据都读入
	while(EOF != fscanf(fp,"%d",&temp))
	{
		sprintf(figlabel, "Input %d Drop %d",temp);
		if(temp > Heap[0])
		{
			int pretop = Heap[0];
			Heap[0] = temp;
			HeapAdjust(Heap,0,Nnum);
			sprintf(figlabel, "Time = %d",i);
			DotHeap(Heap,Nnum,figlabel,temp,pretop);			
		}
		else
		{
			sprintf(figlabel, "Time = %d",i);
			DotHeap(Heap,Nnum,figlabel,temp,temp);	
		}
		sprintf(orderstr, "dot.exe -Tpng heapT.gv -o Tree%02d.png",i++);
		system(orderstr);
	}


	sprintf(figlabel, "Current Heap Situation");
	DotHeap(Heap,Nnum,figlabel,temp);
	sprintf(orderstr, "dot.exe -Tpng heapT.gv -o FinaT.png");
	system(orderstr);

	return 0;	
////////////////////////////////////////////

}

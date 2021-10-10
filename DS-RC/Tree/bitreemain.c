#include "bitree.h"
#include <stdio.h>
#include <malloc.h>
#include <conio.h>

int main(int argc, char *argv[])
{
	BiTree 	bt;
	int 	lc1;
	int 	lc2;
	int 	ptd1;
	int 	ptd2;
	
	printf("开始创建二叉树...\n");
	CreateBiTree(&bt);
	
	printf("先序遍历\n");
	PreOrder(bt);
	
	printf("中序遍历\n");
	InOrder(bt);
	
	printf("后序遍历\n");
	PostOrder(bt);
	
	printf("前序叶子节点遍历\n");
	PreOrderLeaves(bt);
	
	printf("中序非递归遍历1\n");
	InOrderNonRecursion1(bt);
	printf("中序非递归遍历2\n");
	InOrderNonRecursion2(bt);
	
	printf("后序非递归遍历\n");
	PostOrderNonRecursion(bt); 
	
	printf("按竖向树状打印的二叉树\n");
	PrintTree(bt, 1); // TODO:有问题 
	
	printf("先序遍历二叉树叶子节点\n");
	PreOrderLeaves(bt);
	
	printf("\n层次遍历二叉树\n");
	LayerOrder(bt); 
	
	lc1 = LeafCount(bt);// TODO:有问题 
	printf("\n叶子节点个数:%d\n", lc1);
    lc2 = LeafCountNonRecursion(bt); 
    printf("叶子节点个数(非递归):%d\n", lc2);
    
	ptd1 = PostTreeDepth(bt);
 	printf("树深度(后序):%d\n", ptd1);
    ptd2 = PreTreeDepth(bt, 1); // TODO:有问题    
	printf("树深度(前序):%d\n", ptd2);
	
	return 0;
}


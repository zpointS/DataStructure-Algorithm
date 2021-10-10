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
	
	printf("��ʼ����������...\n");
	CreateBiTree(&bt);
	
	printf("�������\n");
	PreOrder(bt);
	
	printf("�������\n");
	InOrder(bt);
	
	printf("�������\n");
	PostOrder(bt);
	
	printf("ǰ��Ҷ�ӽڵ����\n");
	PreOrderLeaves(bt);
	
	printf("����ǵݹ����1\n");
	InOrderNonRecursion1(bt);
	printf("����ǵݹ����2\n");
	InOrderNonRecursion2(bt);
	
	printf("����ǵݹ����\n");
	PostOrderNonRecursion(bt); 
	
	printf("��������״��ӡ�Ķ�����\n");
	PrintTree(bt, 1); // TODO:������ 
	
	printf("�������������Ҷ�ӽڵ�\n");
	PreOrderLeaves(bt);
	
	printf("\n��α���������\n");
	LayerOrder(bt); 
	
	lc1 = LeafCount(bt);// TODO:������ 
	printf("\nҶ�ӽڵ����:%d\n", lc1);
    lc2 = LeafCountNonRecursion(bt); 
    printf("Ҷ�ӽڵ����(�ǵݹ�):%d\n", lc2);
    
	ptd1 = PostTreeDepth(bt);
 	printf("�����(����):%d\n", ptd1);
    ptd2 = PreTreeDepth(bt, 1); // TODO:������    
	printf("�����(ǰ��):%d\n", ptd2);
	
	return 0;
}


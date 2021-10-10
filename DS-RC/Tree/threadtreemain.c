#include "threadtree.h"

int main(int argc, char *argv[])
{
	BiTree 	T;
	BiTree 	p;
	BiTree 	q;
	BiTNode *r;
	
	printf("按扩展先序遍历序列建立二叉树，请输入序列:\n");
	// 输入序列为: ABD..E..CF... 
    CreateBiTree(&T);
	pre = NULL;
	Inthread(T);
    p=T->LChild->RChild;
	q =InPre(p);
	printf("\n前驱为%c",q->data);
	q =InNext(p);
	printf("\n后继为%c",q->data);
	printf("\n");

	q=TinFirst(T);
	printf("\n第一个结点为%c",q->data);

	r=(BiTNode*)malloc(sizeof(BiTNode));
	r->data = 'Q';
	r->LChild = NULL;
	r->RChild = NULL;
	r->Ltag = 0;
	r->Rtag = 0;
	InsNode(p,r);

	printf("遍历线索树:\n");
    TinOrder(T);

	return 0;
}

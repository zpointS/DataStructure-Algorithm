#include "threadtree.h"

int main(int argc, char *argv[])
{
	BiTree 	T;
	BiTree 	p;
	BiTree 	q;
	BiTNode *r;
	
	printf("����չ����������н���������������������:\n");
	// ��������Ϊ: ABD..E..CF... 
    CreateBiTree(&T);
	pre = NULL;
	Inthread(T);
    p=T->LChild->RChild;
	q =InPre(p);
	printf("\nǰ��Ϊ%c",q->data);
	q =InNext(p);
	printf("\n���Ϊ%c",q->data);
	printf("\n");

	q=TinFirst(T);
	printf("\n��һ�����Ϊ%c",q->data);

	r=(BiTNode*)malloc(sizeof(BiTNode));
	r->data = 'Q';
	r->LChild = NULL;
	r->RChild = NULL;
	r->Ltag = 0;
	r->Rtag = 0;
	InsNode(p,r);

	printf("����������:\n");
    TinOrder(T);

	return 0;
}

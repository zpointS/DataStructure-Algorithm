#include "linklist.h"

int main()
{
    LinkList	L;
    LinkList	La;
	LinkList	Lb;
	LinkList	Lc;
 	DoubleList	dl;
	ElemType	key;
	ElemType	elem; 
    ElemType	E;
    Node		*e;
 	int			Length;
	
	key = '2'; 

/* ********************�������������**************************** */ 
	// ��ʼ������
    printf("��ʼ��ʼ������...\n");  
    InitLinkList(&L);

    // ͷ���뷽ʽ�������� - ��ͷ�ڵ� 
    printf("�����������Ԫ�أ�����'$'������\n");
    CreateFromHead(L);
   
    // �������� 
    printf("������������\n");
    TravelLinkList(L);

//    // ��������ʱ��������ڵ���2
//	  e =  (Node *)malloc(sizeof(struct Node));
//	  e =  Get(L,2);/* ���ҵ�����L�в��ҵ�i����� */
//    printf("��2��Ԫ���ǣ�%c\n", e->data);
//    free(e);
//    
//    // ���ұ�L�е�Ԫ��e 
//    e =  (Node *)malloc(sizeof(struct Node));
//    e = Locate(L, key);
//    if(e->data) printf("�ҵ�Ԫ��[ %c ]\n", key);
//    else printf("δ�ҵ�Ԫ��[ %c ]\n", key);
//    free(e);
    
//    Length = ListLength(L);
//    printf("������Ϊ��%d\n", Length);


//	  printf("�ڵ�����λ���ϲ���[%c]��\n", key);
//	  InsList(L, 3, key);
//	  TravelLinkList(L);
    

//    DelList(L, 2, &E);
//    printf("ɾ����2��Ԫ��[%c]��\n", E);
//    TravelLinkList(L);
//	  free(e);
/* ********************END �������������************************ */ 
    
/* ********************�ϲ����������**************************** */    
//    InitLinkList(&La);
//    InitLinkList(&Lb);
//    CreateFromHead(La);
//    CreateFromHead(Lb); 
//    Lc = MergeLinkList(La,Lb);
//    TravelLinkList(Lc);
/* ********************END �ϲ����������************************ */

/* ********************˫�������������**************************** */ 
//	dl = (DNode *)malloc(sizeof(struct DNode));
//	dl->next = dl;
//	dl->prior = dl; 
//	CreateDList(dl);
//	
//	DlinkIns(dl, 2, key);
//	DlinkDel(dl, 2, &elem);
//	printf("%c\n", elem); 
/* ********************END ˫�������������************************ */	    
    return 0;
}

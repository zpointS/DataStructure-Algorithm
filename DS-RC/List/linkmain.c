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

/* ********************单链表基本操作**************************** */ 
	// 初始化链表
    printf("开始初始化链表...\n");  
    InitLinkList(&L);

    // 头出入方式创建链表 - 带头节点 
    printf("请输入链表的元素，并以'$'结束。\n");
    CreateFromHead(L);
   
    // 遍历链表 
    printf("输出遍历结果：\n");
    TravelLinkList(L);

//    // 创建链表时长度需大于等于2
//	  e =  (Node *)malloc(sizeof(struct Node));
//	  e =  Get(L,2);/* 查找单链表L中查找第i个结点 */
//    printf("第2个元素是：%c\n", e->data);
//    free(e);
//    
//    // 查找表L中的元素e 
//    e =  (Node *)malloc(sizeof(struct Node));
//    e = Locate(L, key);
//    if(e->data) printf("找到元素[ %c ]\n", key);
//    else printf("未找到元素[ %c ]\n", key);
//    free(e);
    
//    Length = ListLength(L);
//    printf("链表长度为：%d\n", Length);


//	  printf("在第三个位置上插入[%c]后：\n", key);
//	  InsList(L, 3, key);
//	  TravelLinkList(L);
    

//    DelList(L, 2, &E);
//    printf("删除第2个元素[%c]后：\n", E);
//    TravelLinkList(L);
//	  free(e);
/* ********************END 单链表基本操作************************ */ 
    
/* ********************合并单链表操作**************************** */    
//    InitLinkList(&La);
//    InitLinkList(&Lb);
//    CreateFromHead(La);
//    CreateFromHead(Lb); 
//    Lc = MergeLinkList(La,Lb);
//    TravelLinkList(Lc);
/* ********************END 合并单链表操作************************ */

/* ********************双单链表基本操作**************************** */ 
//	dl = (DNode *)malloc(sizeof(struct DNode));
//	dl->next = dl;
//	dl->prior = dl; 
//	CreateDList(dl);
//	
//	DlinkIns(dl, 2, key);
//	DlinkDel(dl, 2, &elem);
//	printf("%c\n", elem); 
/* ********************END 双单链表基本操作************************ */	    
    return 0;
}

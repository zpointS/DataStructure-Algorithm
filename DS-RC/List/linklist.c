#include "linklist.h" 

void InitLinkList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node)); /*申请结点空间*/
	memset(&((*L)->data),'$',sizeof(ElemType));
	(*L)->next = NULL;                   /*置为空表*/
}

/*通过键盘输入表中元素值，利用头插法建单链表,并返回该单链表头指针L*/
void  CreateFromHead(LinkList L)
{ 
	Node	*s;
	char	c;
	int		flag;
	
	flag = 1;
	
    if('$' != L->data){
        printf("LinkList Uninit.");
        return ;
    }
    
	while(flag)   /* flag初值为1，当输入"$"时，置flag为0，建表结束*/
	{
		c=getchar();   
		if(c!='$')
		{
			s=(Node*)malloc(sizeof(Node)); /*建立新结点s*/
			s->data=c;
			s->next=L->next;  /*将s结点插入表头*/
			L->next=s;
		}
		else
		{
			flag=0;
		}
	}
}

void TravelLinkList(LinkList L)
{
	LinkList p = L;
	if(!p) return; 
	while(p->next != NULL)
	{
		printf("%2c \n", p->data);
		p = p->next;
	}
	printf("%2c \n", p->data);	
}

void CreateFromTail(LinkList L)
{ 
	Node	*r;
	Node	*s;
	char	c;
	int		flag;
	
	flag = 1;         /*设置一个标志，初值为1，当输入"$"时，flag为0，建表结束*/
	
	if('$' != L->data){
        printf("LinkList Uninit.");
        return ;
    }
	
	r=L;                /*r指针动态指向链表的当前表尾，以便于做尾插入，其初值指向头结点*/
	while(flag)         /*循环输入表中元素值，将建立新结点s插入表尾*/
	{
		c=getchar();
		if(c!='$')
		{
			s=(Node*)malloc(sizeof(Node));
			s->data=c;
			r->next=s;
			r=s;
		}
		else
		{
			flag=0;
			r->next=NULL;   /*将最后一个结点的next链域置为空，表示链表的结束*/
		}
	}   
} 

// 在带头结点的单链表L中查找第i个结点，
// 若找到(1≤i≤n)，则返回该结点的存储位置; 
// 否则返回NULL
Node * Get(LinkList  L, int i)
{  
	int		j;
	Node	*p;
	
	p = L;
	j = 0;               /*从头结点开始扫描*/ 
	
	while ((p->next!=NULL)&&(j<i))
	{ 
		p=p->next;     /* 扫描下一结点*/
		j++;           /* 已扫描结点计数器 */
	}
	if(i == j)
		return p;      /* 找到了第i个结点 */
	else 
		return NULL;   /* 找不到，i≤0或i>n */
}  

// 在带头结点的单链表L中查找其结点值等于key的结点，
// 若找到则返回该结点的位置p，
// 否则返回NULL
Node *Locate( LinkList L,ElemType key)
{ 
	Node	*p;
	
	p = L->next;    /*从表中第一个结点开始 */
	
	while (p!=NULL)
	{
		if (p->data!=key)
			p=p->next; 
		else  
			break;      /*找到结点值=key时退出循环 */
	}
	return p;
} 

/*求带头结点的单链表L的长度*/
int	ListLength(LinkList L)
{   
	Node	*p;
	int		j;
	
	p = L->next;
	j = 0;   /*用来存放单链表的长度*/
	
	while(p!=NULL)
	{	  
		p=p->next;
		j++;
	}
	return j;	/*j为求得的单链表长度*/
}

/*在带头结点的单链表L中第i个位置插入值为e的新结点s*/
int InsList(LinkList L,int i,ElemType e)
{  
	Node	*pre;
	Node	*s;
	int		k;
	pre=L;  
	k=0;                     /*从"头"开始，查找第i-1个结点*/
	while(pre!=NULL&&k<i-1)  /*表未查完且未查到第i-1个时重复，找到pre指向第i-1个*/ 
	{ 
		pre=pre->next;
		k=k+1; 
	}									/*查找第i-1结点*/
	if(!pre)      /*如当前位置pre为空表已找完还未数到第i个，说明插入位置不合理*/ 
	{ 
		printf("插入位置不合理!");
		return ERROR;
	}
	s=(Node*)malloc(sizeof(Node));   /*申请一个新的结点S */
	s->data=e;                       /*值e置入s的数据域*/
	s->next=pre->next;			     /*修改指针，完成插入操作*/
	pre->next=s;
	return OK;
}

/*在带头结点的单链表L中删除第i个元素，并将删除的元素保存到变量*e中*/
int DelList(LinkList L,int i,ElemType *e)
{  
	Node	*pre;
	Node	*r;
	int		k;
	
	pre = L;
	k = 0;
	
	while(pre->next!=NULL && k<i-1)	/*寻找被删除结点i的前驱结点i-1使p指向它*/
	{ 
		pre=pre->next; 
		k=k+1;
	}								/*查找第i-1个结点*/
	if(!(pre->next))     /* 即while循环是因为p->next=NULL或i<1而跳出的,而是因为没有找到合法的前驱位置，说明删除位置i不合法。*/
	{
		printf("删除结点的位置i不合理!");
		return ERROR;
	}
	r=pre->next;
	pre->next=pre->next->next;    /*修改指针，删除结点r*/
	*e = r->data;
	free(r);    /*释放被删除的结点所占的内存空间*/
	printf("成功删除结点!");
	
	return OK;
}

/*将递增有序的单链表LA和LB合并成一个递增有序的单链表LC*/
LinkList MergeLinkList(LinkList LA, LinkList LB)
{  
	Node		*pa,*pb;
	Node		*r;
	LinkList	LC; /*将LC初始置空表。pa和pb分别指向两个单链表LA和LB中的第一个结点,r初值为LC*/
   
	pa = LA->next;
	pb = LB->next;
	LC = LA;
	LC->next = NULL;
	r = LC;        /*当两个表中均未处理完时，比较选择将较小值结点插入到新表LC中。*/
    
	while(pa!=NULL && pb!=NULL)
	{
		if(pa->data <= pb->data)
		{
			r->next=pa;
			r=pa;
			pa=pa->next;
		}
		else
		{
			r->next=pb;
			r=pb;
			pb=pb->next;
		}
	}
	if(pa) /*若表LA未完，将表LA中后续元素链到新表LC表尾*/
		r->next=pa;
	else	 /*否则将表LB中后续元素链到新表LC表尾*/
		r->next=pb;
	free(LB);
	
	return(LC);
}

/*创建循环链表*/
void CreateCLinkList(LinkList l)
{
	int		num;
	Node	*p;
	
	l->data = -1;
	l->next = l;
	
	printf("请输入循环链表的元素 (以-1结束):\n");
	scanf("%d",&num);
	while(num != -1)
	{
		p=(Node*)malloc(sizeof(struct Node));
		p->data=num;
		p->next=l->next;
		l->next=p;
		scanf("%d",&num);
	}
}

/*创建尾指针表示的循环链表*/
LinkList CreateRCLinkList()
{
	LinkList	l;
	int			num;
	Node		*p;
	
	l = (Node*)malloc(sizeof(struct Node));
	l->data = -1;
	l->next = l;
	
	printf("请输入循环链表的元素 (以-1结束):\n");
	scanf("%d",&num);
	while(num != -1)
	{
		p=(Node*)malloc(sizeof(struct Node));
		p->data=num;
		p->next=l->next;
		l->next=p;
		scanf("%d",&num);
	}
	p=l;
	while(p->next!=l)
	{
		p=p->next;
	}
	
	return p;
}

/*通过键盘输入表中元素值，利用尾插法建单链表,并返回该单链表头指针L*/
void CreateDList(DoubleList L)
{ 
	DNode	*r, *s;
	char	c;
	int		flag; 
	flag = 1; /*设置一个标志，初值为1，当输入"$"时，flag为0，建表结束*/
	
	L->next = L;
	L->prior = L;
	r = L;              
	
	while(flag)         
	{
		c=getchar();
		if(c!='$')
		{
			s=(DNode*)malloc(sizeof(DNode));
			s->data=c;
			r->next=s;
			s->prior=r;
			r=s;
		}
		else
		{
			flag=0;
			r->next=L;   
			L->prior=r;
		}
	}
}

int DlinkIns(DoubleList L,int i,ElemType e)
{
	DNode	*s,*p;
	int		k;
	p = L;  
	k = 0;                    /*从"头"开始，查找第i-1个结点*/
	while(p->next!=L&&k<i)    /*表未查完且未查到第i-1个时重复，找到p指向第i个*/ 
	{ 
		p=p->next;
		k=k+1; 
	}					    /*查找第i-1结点*/
	if(p->next == L)        /*如当前位置p为空表已找完还未数到第i个，说明插入位置不合理*/ 
	{ 
		printf("插入位置不合理!");
		return ERROR;
	}
	s=(DNode*)malloc(sizeof(DNode));
 	if (s)
	{
		s->data=e;
		s->prior=p->prior;		
		p->prior->next=s;	
		s->next=p;			
		p->prior=s;			
		return OK;
	}
	else 
		return ERROR;
}

int	DlinkDel(DoubleList L,int i,ElemType *e)
{
	DNode	*p;
	int		k;
	
	p = L;  
	k = 0;                      /* 从"头"开始，查找第i个结点 */
	
	while(p->next!=L && k<i)    /*表未查完且未查到第i个时重复，找到p指向第i个*/ 
	{ 
		p=p->next;
		k=k+1; 
	}								
	if(p->next == L)       
	{ 
		return ERROR;
	}
	else
	{
		*e=p->data;
		p->prior->next=p->next;
		p->next->prior=p->prior;
		free(p);
		
		return OK;
	}
}

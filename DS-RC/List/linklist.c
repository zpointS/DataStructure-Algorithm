#include "linklist.h" 

void InitLinkList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node)); /*������ռ�*/
	memset(&((*L)->data),'$',sizeof(ElemType));
	(*L)->next = NULL;                   /*��Ϊ�ձ�*/
}

/*ͨ�������������Ԫ��ֵ������ͷ�巨��������,�����ظõ�����ͷָ��L*/
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
    
	while(flag)   /* flag��ֵΪ1��������"$"ʱ����flagΪ0���������*/
	{
		c=getchar();   
		if(c!='$')
		{
			s=(Node*)malloc(sizeof(Node)); /*�����½��s*/
			s->data=c;
			s->next=L->next;  /*��s�������ͷ*/
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
	
	flag = 1;         /*����һ����־����ֵΪ1��������"$"ʱ��flagΪ0���������*/
	
	if('$' != L->data){
        printf("LinkList Uninit.");
        return ;
    }
	
	r=L;                /*rָ�붯ָ̬������ĵ�ǰ��β���Ա�����β���룬���ֵָ��ͷ���*/
	while(flag)         /*ѭ���������Ԫ��ֵ���������½��s�����β*/
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
			r->next=NULL;   /*�����һ������next������Ϊ�գ���ʾ����Ľ���*/
		}
	}   
} 

// �ڴ�ͷ���ĵ�����L�в��ҵ�i����㣬
// ���ҵ�(1��i��n)���򷵻ظý��Ĵ洢λ��; 
// ���򷵻�NULL
Node * Get(LinkList  L, int i)
{  
	int		j;
	Node	*p;
	
	p = L;
	j = 0;               /*��ͷ��㿪ʼɨ��*/ 
	
	while ((p->next!=NULL)&&(j<i))
	{ 
		p=p->next;     /* ɨ����һ���*/
		j++;           /* ��ɨ��������� */
	}
	if(i == j)
		return p;      /* �ҵ��˵�i����� */
	else 
		return NULL;   /* �Ҳ�����i��0��i>n */
}  

// �ڴ�ͷ���ĵ�����L�в�������ֵ����key�Ľ�㣬
// ���ҵ��򷵻ظý���λ��p��
// ���򷵻�NULL
Node *Locate( LinkList L,ElemType key)
{ 
	Node	*p;
	
	p = L->next;    /*�ӱ��е�һ����㿪ʼ */
	
	while (p!=NULL)
	{
		if (p->data!=key)
			p=p->next; 
		else  
			break;      /*�ҵ����ֵ=keyʱ�˳�ѭ�� */
	}
	return p;
} 

/*���ͷ���ĵ�����L�ĳ���*/
int	ListLength(LinkList L)
{   
	Node	*p;
	int		j;
	
	p = L->next;
	j = 0;   /*������ŵ�����ĳ���*/
	
	while(p!=NULL)
	{	  
		p=p->next;
		j++;
	}
	return j;	/*jΪ��õĵ�������*/
}

/*�ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½��s*/
int InsList(LinkList L,int i,ElemType e)
{  
	Node	*pre;
	Node	*s;
	int		k;
	pre=L;  
	k=0;                     /*��"ͷ"��ʼ�����ҵ�i-1�����*/
	while(pre!=NULL&&k<i-1)  /*��δ������δ�鵽��i-1��ʱ�ظ����ҵ�preָ���i-1��*/ 
	{ 
		pre=pre->next;
		k=k+1; 
	}									/*���ҵ�i-1���*/
	if(!pre)      /*�統ǰλ��preΪ�ձ������껹δ������i����˵������λ�ò�����*/ 
	{ 
		printf("����λ�ò�����!");
		return ERROR;
	}
	s=(Node*)malloc(sizeof(Node));   /*����һ���µĽ��S */
	s->data=e;                       /*ֵe����s��������*/
	s->next=pre->next;			     /*�޸�ָ�룬��ɲ������*/
	pre->next=s;
	return OK;
}

/*�ڴ�ͷ���ĵ�����L��ɾ����i��Ԫ�أ�����ɾ����Ԫ�ر��浽����*e��*/
int DelList(LinkList L,int i,ElemType *e)
{  
	Node	*pre;
	Node	*r;
	int		k;
	
	pre = L;
	k = 0;
	
	while(pre->next!=NULL && k<i-1)	/*Ѱ�ұ�ɾ�����i��ǰ�����i-1ʹpָ����*/
	{ 
		pre=pre->next; 
		k=k+1;
	}								/*���ҵ�i-1�����*/
	if(!(pre->next))     /* ��whileѭ������Ϊp->next=NULL��i<1��������,������Ϊû���ҵ��Ϸ���ǰ��λ�ã�˵��ɾ��λ��i���Ϸ���*/
	{
		printf("ɾ������λ��i������!");
		return ERROR;
	}
	r=pre->next;
	pre->next=pre->next->next;    /*�޸�ָ�룬ɾ�����r*/
	*e = r->data;
	free(r);    /*�ͷű�ɾ���Ľ����ռ���ڴ�ռ�*/
	printf("�ɹ�ɾ�����!");
	
	return OK;
}

/*����������ĵ�����LA��LB�ϲ���һ����������ĵ�����LC*/
LinkList MergeLinkList(LinkList LA, LinkList LB)
{  
	Node		*pa,*pb;
	Node		*r;
	LinkList	LC; /*��LC��ʼ�ÿձ�pa��pb�ֱ�ָ������������LA��LB�еĵ�һ�����,r��ֵΪLC*/
   
	pa = LA->next;
	pb = LB->next;
	LC = LA;
	LC->next = NULL;
	r = LC;        /*���������о�δ������ʱ���Ƚ�ѡ�񽫽�Сֵ�����뵽�±�LC�С�*/
    
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
	if(pa) /*����LAδ�꣬����LA�к���Ԫ�������±�LC��β*/
		r->next=pa;
	else	 /*���򽫱�LB�к���Ԫ�������±�LC��β*/
		r->next=pb;
	free(LB);
	
	return(LC);
}

/*����ѭ������*/
void CreateCLinkList(LinkList l)
{
	int		num;
	Node	*p;
	
	l->data = -1;
	l->next = l;
	
	printf("������ѭ�������Ԫ�� (��-1����):\n");
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

/*����βָ���ʾ��ѭ������*/
LinkList CreateRCLinkList()
{
	LinkList	l;
	int			num;
	Node		*p;
	
	l = (Node*)malloc(sizeof(struct Node));
	l->data = -1;
	l->next = l;
	
	printf("������ѭ�������Ԫ�� (��-1����):\n");
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

/*ͨ�������������Ԫ��ֵ������β�巨��������,�����ظõ�����ͷָ��L*/
void CreateDList(DoubleList L)
{ 
	DNode	*r, *s;
	char	c;
	int		flag; 
	flag = 1; /*����һ����־����ֵΪ1��������"$"ʱ��flagΪ0���������*/
	
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
	k = 0;                    /*��"ͷ"��ʼ�����ҵ�i-1�����*/
	while(p->next!=L&&k<i)    /*��δ������δ�鵽��i-1��ʱ�ظ����ҵ�pָ���i��*/ 
	{ 
		p=p->next;
		k=k+1; 
	}					    /*���ҵ�i-1���*/
	if(p->next == L)        /*�統ǰλ��pΪ�ձ������껹δ������i����˵������λ�ò�����*/ 
	{ 
		printf("����λ�ò�����!");
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
	k = 0;                      /* ��"ͷ"��ʼ�����ҵ�i����� */
	
	while(p->next!=L && k<i)    /*��δ������δ�鵽��i��ʱ�ظ����ҵ�pָ���i��*/ 
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

#include "bitree.h"

void CreateBiTree(BiTree *bt)
{
	char ch;
	ch = getchar();
    if(ch=='.') *bt=NULL;
    else 
	{
		*bt=(BiTree)malloc(sizeof(BiTNode)); //����һ���½��
        (*bt)->data=ch;
        CreateBiTree(&((*bt)->LChild)); //����������
        CreateBiTree(&((*bt)->RChild)); //����������
	}
}

void Visit(char ch)
{
	printf("%c\n",ch);
}

/*�������������, rootΪָ�������(��ĳһ����)������ָ��*/
void  PreOrder(BiTree root) 
{
	if (root!=NULL)
	{
		Visit(root ->data);       /*���ʸ����*/
		PreOrder(root ->LChild);  /*�������������*/
		PreOrder(root ->RChild);  /*�������������*/
	}
}

/*�������������, rootΪָ�������(��ĳһ����)������ָ��*/
void  InOrder(BiTree root)  
{
	if (root!=NULL)
	{
		InOrder(root ->LChild);   /*�������������*/
		Visit(root ->data);        /*���ʸ����*/
		InOrder(root ->RChild);   /*�������������*/
	}
}

/* ���������������rootΪָ�������(��ĳһ����)������ָ��*/
void  PostOrder(BiTree root)  
{
	if(root!=NULL)
	{
		PostOrder(root ->LChild); /*�������������*/
		PostOrder(root ->RChild); /*�������������*/
		Visit(root ->data);       /*���ʸ����*/
	}
}

/*�������������, rootΪָ�������������ָ��*/
void  PreOrderLeaves(BiTree root) 
{
	if (root!=NULL)
	{
		if (root ->LChild==NULL && root ->RChild==NULL)
			printf("%c  ",root ->data);  /* ���Ҷ�ӽ�� */
		PreOrder(root ->LChild);         /* ������������� */
		PreOrder(root ->RChild);         /* ������������� */
	}
}

int LeafCount(BiTree root)
{   
    int leafcount_;
	
	leafcount_  = 0;
	
	if(root!=NULL)
	{
		if ((root->LChild==NULL) && (root->RChild==NULL))
			leafcount_++;
		LeafCount(root->LChild);
		LeafCount(root->RChild);
	}
	
	return leafcount_;
}

int LeafCountNonRecursion(BiTree root)
{
	int leafcount;
	
	leafcount = 0;
	
	if(root==NULL)	
	{
		leafcount = 0;
	}	
	else 
	{
		if((root->LChild==NULL)&&(root->RChild==NULL))
		{
			leafcount =1;
		}	
		else /* Ҷ����Ϊ����������Ҷ����Ŀ֮�� */
		{
			leafcount =LeafCountNonRecursion(root->LChild)+
			LeafCountNonRecursion(root->RChild);
		}	
	}	
	
	return leafcount;
}

/* ���������������ĸ߶ȵݹ��㷨 */
int PostTreeDepth(BiTree bt)           
{
	int hl;
	int hr;
	int max;
	
	if(bt!=NULL)
	{
		hl=PostTreeDepth(bt->LChild);  /* ������������� */
		hr=PostTreeDepth(bt->RChild);  /* ������������� */
		max=hl>hr?hl:hr;               /* �õ�����������Ƚϴ���*/
		return(max+1);                 /* ����������� */
	}
	else return(0);                    /* ����ǿ������򷵻�0 */
}

// ǰ������������bt�߶ȵĵݹ��㷨��hΪbtָ�������ڲ�Σ���ֵΪ1
// depthΪ��ǰ��õ�����Σ�Ϊȫ�ֱ���������ǰ��ֵΪ0
int PreTreeDepth(BiTree bt, int h)
{
	int depth;
    if(bt!=NULL)
    {
        if(h>depth)   depth = h;            /* ����ý����ֵ����depth������depth��ֵ */
        PreTreeDepth(bt->LChild, depth+1);  /* ���������� */
        PreTreeDepth(bt->RChild, depth+1);  /* ���������� */
     }
     return depth;
}

/* ��������״��ӡ�Ķ����� */
void PrintTree(BiTree bt,int nLayer)        
{   int i;
	if(bt == NULL) return;
	PrintTree(bt->RChild,nLayer+1);
	for(i=0;i<nLayer;i++)
		printf("  ");
	printf("%c\n",bt->data);
	PrintTree(bt->LChild,nLayer+1);
}

/* ���������������rootΪ�������ĸ���� */
void InOrderNonRecursion1(BiTree root)     
{
	int		top; 
	BiTree	p;
	BiTree	s[Stack_Size];
	int		m;
	
	top = 0;
	m = Stack_Size-1;
	p = root;
	
	do
	{
		while(p!=NULL)
		{ 
			if (top>m) return;
			top=top+1;  
			s[top]=p;
			p=p->LChild;
		};  /* ���������� */
		if(top!=0)
		{ 
			p=s[top];
			top=top-1;
			Visit(p->data);  /* ���ʸ���� */
			p=p->RChild;     /* ���������� */
		}   
	}
	while(p!=NULL || top!=0);
}

void  InOrderNonRecursion2(BiTree root) /* ��������������ķǵݹ��㷨 */
{
	SeqStack	S;
	BiTree		p;
	
	InitStack (&S);
	p=root;
	while(p!=NULL || !IsStackEmpty(&S))
	{ 
		if (p!=NULL)  /* ��ָ���ջ������������ */
		{
			Push(&S,p);
			p=p->LChild;
		}
		else
		{  /*��ָ����ջ�����ʸ���㣬����������*/
			Pop(&S,&p); 
			Visit(p->data);  
			p=p->RChild;
		}
	}
}

void PostOrderNonRecursion(BiTree root)
{
	BiTNode *p;
	BiTNode *q;
	BiTNode **s;
	int 	top;
	
	top = 0;
	q = NULL;
	p = root;
	s = (BiTNode**)malloc(sizeof(BiTNode*)*NUM);
	
	/* NUMΪԤ����ĳ��� */
	while(p!=NULL || top!=0)
	{
		while(p!=NULL)
		{
			top++; 
			s[top]=p; 
			p=p->LChild; 
		}  /*����������*/
		if(top>0) 
		{	
			p=s[top];
			if((p->RChild==NULL) ||(p->RChild==q))	/* ���Һ��ӣ����Һ����ѱ����� */
			{
			    Visit(p->data);        /* ���ʸ����*/
				q=p;            	/* ���浽q��Ϊ��һ���Ѵ�����ǰ�� */
				top--;
				p=NULL;
			} 
			else	
				p=p->RChild;
		}
	}
	free(s);
}

int LayerOrder(BiTree bt)
{ 
	SeqQueue 	*Q;
	BiTree  	p;
	
	Q=(SeqQueue *)malloc(sizeof(SeqQueue));
	
	InitQueue(Q);  /*��ʼ���ն���Q*/
	if(bt == NULL)
	{
		return ERROR; /* ��������btΪ���������������*/
	}	
	EnterQueue(Q, bt);/* ��������bt�ǿգ�������bt��ӣ���ʼ��α���*/
	while(!IsEmpty(Q))/*�����зǿգ������Ϊ��������������*/
	{ 
		DeleteQueue(Q, &p);           /* ��ͷԪ�س��Ӳ����� */
		printf("%c  ",p->data);
		if(p->LChild )  
		{
			EnterQueue(Q, p->LChild); /* ��p�����ӷǿգ������ */
		}	
		if(p->RChild ) 
		{
			EnterQueue(Q, p->RChild); /* ��p���Һ��ӷǿգ������ */
		}	
	}
	
	return OK;
}


void InitQueue(SeqQueue *Q)
{  
	Q->front = Q->rear = 0;
}

int EnterQueue(SeqQueue *Q, QueueElementType x)
{  
	if((Q->rear+1)%MAXSIZE==Q->front)
	{
		return(FALSE);
	}	
	Q->element[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;
	
	return(TRUE); 
}

int DeleteQueue(SeqQueue *Q, QueueElementType *x)
{ 
	if(Q->front==Q->rear) 
	{
		return(FALSE);
	}	
	*x=Q->element[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
	
	return(TRUE);
}

int GetHead(SeqQueue *Q, QueueElementType *x)
{ 
	if(Q->front==Q->rear) 
	{
		return(FALSE);
	}	
	*x=Q->element[Q->front];
	
	return(TRUE);
}

int IsEmpty(SeqQueue *Q)
{ 
	if(Q->front==Q->rear)
	{
		return(TRUE);
	}	
	else
	{
		return(FALSE);
	}	  
}

void InitStack(SeqStack *S)
{
  	S->top = -1;
}

int IsStackEmpty(SeqStack *S)
{
	return(S->top==-1?TRUE:FALSE);
}

int IsFull(SeqStack *S)
{
	return(S->top==Stack_Size-1?TRUE:FALSE);
}

int Push(SeqStack *S,StackElementType x)
{
	if(S->top==Stack_Size-1)  
	{
		return(FALSE);
	}	
	S->top++;
	S->elem[S->top] = x;
	
	return(TRUE);
}

int Pop(SeqStack *S,StackElementType *x)
{  
	if(S->top == -1)  
	{
		return(FALSE);
	}	
	else
	{
  		*x = S->elem[S->top];
		S->top--;
  		return(TRUE);
	}
}

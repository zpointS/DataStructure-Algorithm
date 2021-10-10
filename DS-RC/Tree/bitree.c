#include "bitree.h"

void CreateBiTree(BiTree *bt)
{
	char ch;
	ch = getchar();
    if(ch=='.') *bt=NULL;
    else 
	{
		*bt=(BiTree)malloc(sizeof(BiTNode)); //生成一个新结点
        (*bt)->data=ch;
        CreateBiTree(&((*bt)->LChild)); //生成左子树
        CreateBiTree(&((*bt)->RChild)); //生成右子树
	}
}

void Visit(char ch)
{
	printf("%c\n",ch);
}

/*先序遍历二叉树, root为指向二叉树(或某一子树)根结点的指针*/
void  PreOrder(BiTree root) 
{
	if (root!=NULL)
	{
		Visit(root ->data);       /*访问根结点*/
		PreOrder(root ->LChild);  /*先序遍历左子树*/
		PreOrder(root ->RChild);  /*先序遍历右子树*/
	}
}

/*中序遍历二叉树, root为指向二叉树(或某一子树)根结点的指针*/
void  InOrder(BiTree root)  
{
	if (root!=NULL)
	{
		InOrder(root ->LChild);   /*中序遍历左子树*/
		Visit(root ->data);        /*访问根结点*/
		InOrder(root ->RChild);   /*中序遍历右子树*/
	}
}

/* 后序遍历二叉树，root为指向二叉树(或某一子树)根结点的指针*/
void  PostOrder(BiTree root)  
{
	if(root!=NULL)
	{
		PostOrder(root ->LChild); /*后序遍历左子树*/
		PostOrder(root ->RChild); /*后序遍历右子树*/
		Visit(root ->data);       /*访问根结点*/
	}
}

/*先序遍历二叉树, root为指向二叉树根结点的指针*/
void  PreOrderLeaves(BiTree root) 
{
	if (root!=NULL)
	{
		if (root ->LChild==NULL && root ->RChild==NULL)
			printf("%c  ",root ->data);  /* 输出叶子结点 */
		PreOrder(root ->LChild);         /* 先序遍历左子树 */
		PreOrder(root ->RChild);         /* 先序遍历右子树 */
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
		else /* 叶子数为左右子树的叶子数目之和 */
		{
			leafcount =LeafCountNonRecursion(root->LChild)+
			LeafCountNonRecursion(root->RChild);
		}	
	}	
	
	return leafcount;
}

/* 后序遍历求二叉树的高度递归算法 */
int PostTreeDepth(BiTree bt)           
{
	int hl;
	int hr;
	int max;
	
	if(bt!=NULL)
	{
		hl=PostTreeDepth(bt->LChild);  /* 求左子树的深度 */
		hr=PostTreeDepth(bt->RChild);  /* 求右子树的深度 */
		max=hl>hr?hl:hr;               /* 得到左、右子树深度较大者*/
		return(max+1);                 /* 返回树的深度 */
	}
	else return(0);                    /* 如果是空树，则返回0 */
}

// 前序遍历求二叉树bt高度的递归算法，h为bt指向结点所在层次，初值为1
// depth为当前求得的最大层次，为全局变量，调用前初值为0
int PreTreeDepth(BiTree bt, int h)
{
	int depth;
    if(bt!=NULL)
    {
        if(h>depth)   depth = h;            /* 如果该结点层次值大于depth，更新depth的值 */
        PreTreeDepth(bt->LChild, depth+1);  /* 遍历左子树 */
        PreTreeDepth(bt->RChild, depth+1);  /* 遍历右子树 */
     }
     return depth;
}

/* 按竖向树状打印的二叉树 */
void PrintTree(BiTree bt,int nLayer)        
{   int i;
	if(bt == NULL) return;
	PrintTree(bt->RChild,nLayer+1);
	for(i=0;i<nLayer;i++)
		printf("  ");
	printf("%c\n",bt->data);
	PrintTree(bt->LChild,nLayer+1);
}

/* 中序遍历二叉树，root为二叉树的根结点 */
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
		};  /* 遍历左子树 */
		if(top!=0)
		{ 
			p=s[top];
			top=top-1;
			Visit(p->data);  /* 访问根结点 */
			p=p->RChild;     /* 遍历右子树 */
		}   
	}
	while(p!=NULL || top!=0);
}

void  InOrderNonRecursion2(BiTree root) /* 中序遍历二叉树的非递归算法 */
{
	SeqStack	S;
	BiTree		p;
	
	InitStack (&S);
	p=root;
	while(p!=NULL || !IsStackEmpty(&S))
	{ 
		if (p!=NULL)  /* 根指针进栈，遍历左子树 */
		{
			Push(&S,p);
			p=p->LChild;
		}
		else
		{  /*根指针退栈，访问根结点，遍历右子树*/
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
	
	/* NUM为预定义的常数 */
	while(p!=NULL || top!=0)
	{
		while(p!=NULL)
		{
			top++; 
			s[top]=p; 
			p=p->LChild; 
		}  /*遍历左子树*/
		if(top>0) 
		{	
			p=s[top];
			if((p->RChild==NULL) ||(p->RChild==q))	/* 无右孩子，或右孩子已遍历过 */
			{
			    Visit(p->data);        /* 访问根结点*/
				q=p;            	/* 保存到q，为下一次已处理结点前驱 */
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
	
	InitQueue(Q);  /*初始化空队列Q*/
	if(bt == NULL)
	{
		return ERROR; /* 若二叉树bt为空树，则结束遍历*/
	}	
	EnterQueue(Q, bt);/* 若二叉树bt非空，则根结点bt入队，开始层次遍历*/
	while(!IsEmpty(Q))/*若队列非空，则遍历为结束，继续进行*/
	{ 
		DeleteQueue(Q, &p);           /* 队头元素出队并访问 */
		printf("%c  ",p->data);
		if(p->LChild )  
		{
			EnterQueue(Q, p->LChild); /* 若p的左孩子非空，则进队 */
		}	
		if(p->RChild ) 
		{
			EnterQueue(Q, p->RChild); /* 若p的右孩子非空，则进队 */
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

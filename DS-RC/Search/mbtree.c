#include "mbtree.h"

/* 在mbp->key[ipos +1]处插上key, 在mbp->ptr[ipos+1]处插上rp  */
void insert(Mbtree mbp,	int ipos, 	KeyType key,  Mbtree rp)
{
	int j;
	for (j=mbp->keynum; j>= ipos +1 ; j--)
	{ 
		mbp->key[j+1]=mbp->key[j];
		mbp->ptr[j+1]=mbp->ptr[j];
	}
	mbp->key[ipos+1]=key;
	mbp->ptr[ipos+1]=rp;
	mbp->keynum++;
}

/* B_树的分裂过程 */
void  split (Mbtree  oldp,	Mbtree  *newp)
{
	int s;
	int n;
	int i;
	
	s=ceil((float)m/2);       /* s=  */
	n=m-s;
	*newp=(Mbtree)malloc(sizeof(Mbtnode));
	(*newp)->keynum=n;
	(*newp)->parent=oldp->parent;
	(*newp)->ptr[0]=oldp->ptr[s];
	for (i=1 ; i<=n ; i++)
	{ 
		(*newp)->key[i]=oldp->key[s+i];
		(*newp)->ptr[i]=oldp->ptr[s+i];
	}
	oldp->keynum=s-1;
}

/*在mbt指向的结点中，寻找小于等于key的最大关键字序号*/
int  search (Mbtree  mbt,  KeyType  key )
{
	int n;
	int i;
	n = mbt->keynum ;
	i = 1 ;
	while (i <= n && mbt->key[i] <= key )
	{
		i++;
	}  
	return (i - 1);    /* 返回小于等于key的最大关键字序号 ，为0 时表示应到
						最左分支找，越界时表示应到最右分支找 */
}

// 在m阶B_树t中插入k：如果mbt=NULL，则生成初始根（此时q=NULL,i=0）；
// 否则q指向某个最下层非终端结点，k应插在该结点中q->key[i+1]处，
// 插入后如果q->keynum>m-1，则进行分裂处理
void  ins_mbtree(Mbtree  *mbt,  KeyType  k,  Mbtree q,  int  i)
{ 
	Mbtree	q1;
	Mbtree	ap;
	Mbtree	new_root;
	int 	s;
	int 	finished;
	int 	x;
	
	if (*mbt==NULL)
	{ 
		*mbt =(Mbtree)malloc(sizeof(Mbtnode));
		(*mbt)->keynum=1;
		(*mbt)->parent=NULL;
		(*mbt)->key[1]=k;
		(*mbt)->ptr[0]=NULL; 
		(*mbt)->ptr[1]=NULL;
	}
	else  
	{  
		x=k;            /* 将x插到q->key[i+1] 处 */
		ap=NULL;		/* 将ap插到q->ptr[i+1] 处 */
		finished=(int)NULL;
		while (q!=NULL && !finished) /* q=NULL 表示已经分裂到根 */
		{ 
			insert(q, i, x, ap);
			if (q->keynum<m) 
			{
				finished=TRUE;  	/* 不再分裂 */
			}	
			else
			{
				s=ceil((float)m/2);   /* s=  */
				split(q, &q1);        /* 分裂 */
				x=q->key[s];	
				ap=q1;
				q=q->parent;
				if (q!=NULL) 
				{
					i=search(q,x);	 /* search( ) 的定义参见B_树查找一节 */
				}	
			}
		}
		if (!finished)      /* 表示根结点要分裂，并产生新根 */
		{
			new_root=(Mbtree)malloc(sizeof(Mbtnode));
			new_root->keynum=1;  
			new_root->parent=NULL; 
			new_root->key[1]=x;	
			new_root->ptr[0]=*mbt; 
			new_root->ptr[1]=ap;
			*mbt=new_root;
		}
	}
}

void Creatembtree(Mbtree *mbt)
{
	int		k;
	Mbtree 	q;
	int 	i;
	
	*mbt = NULL;
	q = NULL;
	i = 0;
	printf("请输入一个元素:");
	scanf("%d",&k);
	while(k != 0)
	{
		ins_mbtree(mbt,k,q,i);
		i = i+1;
		printf("清继续输入元素:");
		fflush(stdin);
		scanf("%d",&k);
	}
	
}

// 在根为mbt的B_树中查找关键字k，如果查找成功，
// 则将所在结点地址放入np，将结点内位置序号放入pos，并返回true；
// 否则，将k应被插入的结点地址放入np，将结点内应插位置序号放入pos，并返回false
Boolean  srch_mbtree (Mbtree  mbt,  KeyType  k,  Mbtree  *np,  int *pos)
{
	Mbtree 	p;
	Mbtree 	fp;
	Boolean found;
	int 	i;
	
	p = mbt;
	fp = NULL; 
	found = false; 
	i = 0;
	while (p != NULL && !found)
	{ 
		i = search (p, k);
		if (i>0 && p->key[i] == k) 
		{
			found = true;
		}	
		else 
		{ 
			fp = p; 
			p = p->ptr[i]; 
		}
	}
	if (found) 
	{ 
		*np = p; 
		*pos = i; 
		return true;
	}
	else 
	{
		*np = fp; 
		*pos = i; 
		return false;
	}
}

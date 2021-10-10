#include "mbtree.h"

/* ��mbp->key[ipos +1]������key, ��mbp->ptr[ipos+1]������rp  */
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

/* B_���ķ��ѹ��� */
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

/*��mbtָ��Ľ���У�Ѱ��С�ڵ���key�����ؼ������*/
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
	return (i - 1);    /* ����С�ڵ���key�����ؼ������ ��Ϊ0 ʱ��ʾӦ��
						�����֧�ң�Խ��ʱ��ʾӦ�����ҷ�֧�� */
}

// ��m��B_��t�в���k�����mbt=NULL�������ɳ�ʼ������ʱq=NULL,i=0����
// ����qָ��ĳ�����²���ն˽�㣬kӦ���ڸý����q->key[i+1]����
// ��������q->keynum>m-1������з��Ѵ���
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
		x=k;            /* ��x�嵽q->key[i+1] �� */
		ap=NULL;		/* ��ap�嵽q->ptr[i+1] �� */
		finished=(int)NULL;
		while (q!=NULL && !finished) /* q=NULL ��ʾ�Ѿ����ѵ��� */
		{ 
			insert(q, i, x, ap);
			if (q->keynum<m) 
			{
				finished=TRUE;  	/* ���ٷ��� */
			}	
			else
			{
				s=ceil((float)m/2);   /* s=  */
				split(q, &q1);        /* ���� */
				x=q->key[s];	
				ap=q1;
				q=q->parent;
				if (q!=NULL) 
				{
					i=search(q,x);	 /* search( ) �Ķ���μ�B_������һ�� */
				}	
			}
		}
		if (!finished)      /* ��ʾ�����Ҫ���ѣ��������¸� */
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
	printf("������һ��Ԫ��:");
	scanf("%d",&k);
	while(k != 0)
	{
		ins_mbtree(mbt,k,q,i);
		i = i+1;
		printf("���������Ԫ��:");
		fflush(stdin);
		scanf("%d",&k);
	}
	
}

// �ڸ�Ϊmbt��B_���в��ҹؼ���k��������ҳɹ���
// �����ڽ���ַ����np���������λ����ŷ���pos��������true��
// ���򣬽�kӦ������Ľ���ַ����np���������Ӧ��λ����ŷ���pos��������false
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

#include "bst.h"

/*���ڶ����������в����ڹؼ��ֵ���key��Ԫ�أ������Ԫ��*/
void InsertBST(BSTree *bst, KeyType key)
{ 
	BSTree s;
	if (*bst == NULL)/*�ݹ��������*/
	{
		s=(BSTree)malloc(sizeof(BSTNode));/*�����µĽ��s*/
		s-> key=key;
		s->lchild=NULL; 
		s->rchild=NULL;
		*bst=s;
	}
	else 
	{
		if (key < (*bst)->key)
		{
			InsertBST(&((*bst)->lchild), key);/*��s����������*/
		}	
		else 
		{
			if (key > (*bst)->key)
			{
				InsertBST(&((*bst)->rchild), key); /*��s����������*/
			}	
		}	
	} 

}

/*�Ӽ�������Ԫ�ص�ֵ��������Ӧ�Ķ���������*/
void  CreateBST(BSTree  *bst)
{ 
	KeyType key;
	*bst=NULL;
	scanf("%d", &key);
	while (key!=ENDKEY)   /*ENDKEYΪ�Զ��峣��*/
	{
		InsertBST(bst, key);
		scanf("%d", &key);
	}
}

/*�������������, rootΪָ�������������ָ��*/
void  PreOrder(BSTree root) 
{
	if (root!=NULL)
	{
		printf("%d  ",root->key);  /*������*/
		PreOrder(root->lchild);    /*�������������*/
		PreOrder(root->rchild);    /*�������������*/
	}
}

/*�ڸ�ָ��bst��ָ����������bst�ϣ����ҹؼ��ֵ���key�Ľ�㣬�����ҳɹ�������ָ���Ԫ�ؽ��ָ�룬���򷵻ؿ�ָ��*/
BSTree  SearchBST(BSTree bst, KeyType key)
{ 
	BSTree q;
	q=bst;
	while(q)
	{
		if (q->key == key) 
			return q;  /*���ҳɹ�*/
		if (q->key > key)  
			q=q->lchild;  /*���������в���*/
		else  
			q=q->rchild;  /*���������в���*/
	}
	return NULL; /*����ʧ��*/
}/*SearchBST*/

BSTNode  * DelBST(BSTree t, KeyType  k) /*�ڶ���������t��ɾȥ�ؼ���Ϊk�Ľ��*/
{
	BSTNode	*p;
	BSTNode	*f;
	BSTNode *s;
	BSTNode *q;
	
	p=t; 
	f=NULL;
	while(p)  /*���ҹؼ���Ϊk�Ĵ�ɾ���p*/
	{ 
		if(p->key==k )  break;  /*�ҵ�������ѭ��*/
		f=p;   /*fָ��p����˫�׽��*/
		if(p->key>k)  
		{
			p=p->lchild;
		}	
		else 
		{
			p=p->rchild;
		}	
	} 
	if(p==NULL)
	{
		return t;  /*���Ҳ���������ԭ���Ķ���������*/
	}  
	if(p->lchild==NULL)  /*p��������*/
	{ 
		if(f==NULL) 
			t=p->rchild;  /*p��ԭ�����������ĸ�*/
		else 
		{
			if(f->lchild==p)  /*p��f������*/
			{
				f->lchild=p->rchild ;  /*��p������������f��������*/
			}	
			else  /*p��f���Һ���*/
			{
				f->rchild=p->rchild ;  /*��p������������f��������*/
			}	
		}
		free(p);  /*�ͷű�ɾ���Ľ��p*/	
	}
	else  /*p��������*/
	{ 
		q=p; 
		s=p->lchild;
		while(s->rchild)  /*��p���������в��������½��*/
		{
			q=s; 
			s=s->rchild;
		}
		if(q==p) 
		{
			q->lchild=s->lchild ;  /*��s������������q��*/
		}	
		else 
		{
			q->rchild=s->lchild;
		}	
		p->key=s->key;  /*��s��ֵ����p*/
		free(s);
	}
	return t;
}  /*DelBST*/

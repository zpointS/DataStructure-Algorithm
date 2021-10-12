#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef int KeyType;

typedef struct  node
{
	KeyType  key ; /*�ؼ��ֵ�ֵ*/
	struct node  *lchild,*rchild;/*����ָ��*/
	int flag;
}BSTNode, *BSTree;

void InsertBST(BSTree *bst, KeyType key)
/*���ڶ����������в����ڹؼ��ֵ���key��Ԫ�أ������Ԫ��*/
{ 
	BSTree s;
	if (*bst == NULL)/*�ݹ��������*/
	{
		s=(BSTree)malloc(sizeof(BSTNode));/*�����µĽ��s*/
		s-> key=key;
		s->lchild=NULL; 
		s->rchild=NULL;
		s->flag=0;
		*bst=s;
	}
	else 
		if (key < (*bst)->key)
			InsertBST(&((*bst)->lchild), key);/*��s����������*/
		else 
			if (key > (*bst)->key)
				InsertBST(&((*bst)->rchild), key); /*��s����������*/
}


void  CreateBST(BSTree  *bst, char * filename)
/*���ļ�����Ԫ�ص�ֵ��������Ӧ�Ķ���������*/
{ 
	FILE *fp;
	KeyType keynumber;
	*bst=NULL;
	fp = fopen(filename,"r+");
	if(fp==NULL)
		exit(0x01);
	while(EOF != fscanf(fp,"%d",&keynumber))
		InsertBST(bst, keynumber);
}

void  PreOrderCleanFlag(BSTree root) 
/*�������������, rootΪָ�������������ָ��*/
{
	if (root!=NULL)
	{
		root->flag = 0;  /*������*/
		PreOrderCleanFlag(root->lchild);  /*�������������*/
		PreOrderCleanFlag(root->rchild);  /*�������������*/
	}
}

void DestroyBST(BSTree root)
{
	if(root!=NULL)
	{
		PreOrderCleanFlag(root->lchild);  /*�������������*/
		PreOrderCleanFlag(root->rchild);  /*�������������*/
		free(root);
	}
}

BSTree  SearchBST(BSTree bst, KeyType key)
/*�ڸ�ָ��bst��ָ����������bst�ϣ����ҹؼ��ֵ���key�Ľ�㣬�����ҳɹ�������ָ���Ԫ�ؽ��ָ�룬���򷵻ؿ�ָ��*/
{ 
	BSTree q;
	q=bst;
	while(q)
	{
		q->flag=1;
		if (q->key == key)
		{
			q->flag=2;
			return q;  /*���ҳɹ�*/			
		}
		if (q->key > key) 
			q=q->lchild;  /*���������в���*/
		else   
			q=q->rchild;  /*���������в���*/
	}
	return NULL; /*����ʧ��*/
}/*SearchBST*/

BSTNode  * DelBST(BSTree t, KeyType  k) /*�ڶ���������t��ɾȥ�ؼ���Ϊk�Ľ��*/
{
	BSTNode  *p, *f,*s ,*q;
	p=t; 
	f=NULL;
	while(p)  /*���ҹؼ���Ϊk�Ĵ�ɾ���p*/
	{ 
		if(p->key==k )  break;  /*�ҵ�������ѭ��*/
		f=p;   /*fָ��p����˫�׽��*/
		if(p->key>k)  
			p=p->lchild;
		else 
			p=p->rchild;
	} 
	if(p==NULL)  return t;  /*���Ҳ���������ԭ���Ķ���������*/
	if(p->lchild==NULL)  /*p��������*/
	{ 
		if(f==NULL) 
			t=p->rchild;  /*p��ԭ�����������ĸ�*/
		else 
			if(f->lchild==p)  /*p��f������*/
				f->lchild=p->rchild ;  /*��p������������f��������*/
			else  /*p��f���Һ���*/
				f->rchild=p->rchild ;  /*��p������������f��������*/
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
			q->lchild=s->lchild ;  /*��s������������q��*/
		else 
			q->rchild=s->lchild;
		p->key=s->key;  /*��s��ֵ����p*/
		free(s);
	}
	return t;
}  /*DelBST*/


void  DotOrderList(BSTree root, FILE *fp) 
{
	if(root==NULL)
		return;
	char lpoint = root->lchild ? ' ' : ' ';
	char rpoint = root->rchild ? ' ' : ' ';
	if(root->flag==1)
	{
		fprintf(fp,"%d[label = \"<l>%c|<d>%d|<r>%c\",color=green];\n",root->key,lpoint,root->key,rpoint);
	}
	else if(root->flag==2)
	{
		fprintf(fp,"%d[label = \"<l>%c|<d>%d|<r>%c\",color=red,fontcolor=red];\n",root->key,lpoint,root->key,rpoint);
	}
	else
		fprintf(fp,"%d[label = \"<l>%c|<d>%d|<r>%c\"];\n",root->key,lpoint,root->key,rpoint);
	DotOrderList(root->lchild,fp);
	DotOrderList(root->rchild,fp);
}

void  DotOrderLink(BSTree root, FILE *fp) 
{
	if(root==NULL)
		return;
	
	if(root->lchild)
		fprintf(fp,"%d:l:sw -> %d:d;\n",root->key,root->lchild->key);
	
	if(root->rchild)
		fprintf(fp,"%d:r:se -> %d:d;\n",root->key,root->rchild->key);

	DotOrderLink(root->lchild,fp);
	DotOrderLink(root->rchild,fp);
}

void MakeDot(BSTree root, char * tital=NULL)
{
	FILE *fp=fopen("BST.gv","w+");
	fprintf(fp,"digraph BST {\n");
	if(tital != NULL)
	{
		fprintf(fp,"labelloc = t; labeljust = l;\n");
		fprintf(fp,"label = \"%s\";\n",tital);		
	}
	fprintf(fp,"node [fontname = Verdana, color=navy, shape=record, height=.1];\n");
	fprintf(fp,"edge [fontname = Verdana, color=navy, style=solid];\n");
	DotOrderList(root,fp);
	DotOrderLink(root,fp);
	fprintf(fp,"}\n\n");
	fclose(fp);
}

int main(int argc, char *argv[])
{
	BSTree T;
	if(argc<2)
		printf("Order is BST.exe filename.txt\n");
   	CreateBST(&T,argv[1]);
	printf("\n");
	MakeDot(T);
	
	PreOrderCleanFlag(T);
	system("dot.exe -Tpng bst.gv -o bst.png");
	SearchBST(T,62);
	MakeDot(T);
	system("dot.exe -Tpng bst.gv -o bst_search(62).png");
	
	PreOrderCleanFlag(T);
	SearchBST(T,98); 
	MakeDot(T);
	system("dot.exe -Tpng bst.gv -o bst_search(98).png");
	
	PreOrderCleanFlag(T);
	DestroyBST(T);
	return 0;
}

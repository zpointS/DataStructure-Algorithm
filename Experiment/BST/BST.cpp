#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef int KeyType;

typedef struct  node
{
	KeyType  key ; /*关键字的值*/
	struct node  *lchild,*rchild;/*左右指针*/
	int flag;
}BSTNode, *BSTree;

void InsertBST(BSTree *bst, KeyType key)
/*若在二叉排序树中不存在关键字等于key的元素，插入该元素*/
{ 
	BSTree s;
	if (*bst == NULL)/*递归结束条件*/
	{
		s=(BSTree)malloc(sizeof(BSTNode));/*申请新的结点s*/
		s-> key=key;
		s->lchild=NULL; 
		s->rchild=NULL;
		s->flag=0;
		*bst=s;
	}
	else 
		if (key < (*bst)->key)
			InsertBST(&((*bst)->lchild), key);/*将s插入左子树*/
		else 
			if (key > (*bst)->key)
				InsertBST(&((*bst)->rchild), key); /*将s插入右子树*/
}


void  CreateBST(BSTree  *bst, char * filename)
/*从文件输入元素的值，创建相应的二叉排序树*/
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
/*先序遍历二叉树, root为指向二叉树根结点的指针*/
{
	if (root!=NULL)
	{
		root->flag = 0;  /*输出结点*/
		PreOrderCleanFlag(root->lchild);  /*先序遍历左子树*/
		PreOrderCleanFlag(root->rchild);  /*先序遍历右子树*/
	}
}

void DestroyBST(BSTree root)
{
	if(root!=NULL)
	{
		PreOrderCleanFlag(root->lchild);  /*先序遍历左子树*/
		PreOrderCleanFlag(root->rchild);  /*先序遍历右子树*/
		free(root);
	}
}

BSTree  SearchBST(BSTree bst, KeyType key)
/*在根指针bst所指二叉排序树bst上，查找关键字等于key的结点，若查找成功，返回指向该元素结点指针，否则返回空指针*/
{ 
	BSTree q;
	q=bst;
	while(q)
	{
		q->flag=1;
		if (q->key == key)
		{
			q->flag=2;
			return q;  /*查找成功*/			
		}
		if (q->key > key) 
			q=q->lchild;  /*在左子树中查找*/
		else   
			q=q->rchild;  /*在右子树中查找*/
	}
	return NULL; /*查找失败*/
}/*SearchBST*/

BSTNode  * DelBST(BSTree t, KeyType  k) /*在二叉排序树t中删去关键字为k的结点*/
{
	BSTNode  *p, *f,*s ,*q;
	p=t; 
	f=NULL;
	while(p)  /*查找关键字为k的待删结点p*/
	{ 
		if(p->key==k )  break;  /*找到则跳出循环*/
		f=p;   /*f指向p结点的双亲结点*/
		if(p->key>k)  
			p=p->lchild;
		else 
			p=p->rchild;
	} 
	if(p==NULL)  return t;  /*若找不到，返回原来的二叉排序树*/
	if(p->lchild==NULL)  /*p无左子树*/
	{ 
		if(f==NULL) 
			t=p->rchild;  /*p是原二叉排序树的根*/
		else 
			if(f->lchild==p)  /*p是f的左孩子*/
				f->lchild=p->rchild ;  /*将p的右子树链到f的左链上*/
			else  /*p是f的右孩子*/
				f->rchild=p->rchild ;  /*将p的右子树链到f的右链上*/
			free(p);  /*释放被删除的结点p*/
	}
	else  /*p有左子树*/
	{ 
		q=p; 
		s=p->lchild;
		while(s->rchild)  /*在p的左子树中查找最右下结点*/
		{
			q=s; 
			s=s->rchild;
		}
		if(q==p) 
			q->lchild=s->lchild ;  /*将s的左子树链到q上*/
		else 
			q->rchild=s->lchild;
		p->key=s->key;  /*将s的值赋给p*/
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

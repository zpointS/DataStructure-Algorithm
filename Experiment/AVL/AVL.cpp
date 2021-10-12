#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef int KeyType;

typedef struct  node
{
	KeyType  key ; /*�ؼ��ֵ�ֵ*/
	int bf;
	struct node  *lchild,*rchild;/*����ָ��*/
}AVLTNode, *AVLTree;


void  ins_AVLtree(AVLTree  *avlt ,  KeyType  K)
/*��ƽ��������в���Ԫ��K��ʹ֮��Ϊһ���µ�ƽ�����������*/
{
	AVLTNode *S;
	AVLTNode *A,*FA,*p,*fp,*B,*C;
	S=(AVLTree)malloc(sizeof(AVLTNode));
	S->key=K; 
	S->lchild=S->rchild=NULL;
	S->bf=0;
	if (*avlt==NULL)  
		*avlt=S;
	else 
	{ 
	/* ���Ȳ���S�Ĳ���λ��fp��ͬʱ��¼��S�Ĳ���λ�������
		ƽ�����Ӳ�����0������-1��1���Ľ��A��AΪ���ܵ�ʧ����*/
		A=*avlt;  FA=NULL;
		p=*avlt;  fp=NULL;
		while  (p!=NULL)
		{ 
			if (p->bf!=0) 
			{
				A=p; FA =fp;
			}
			fp=p;
			if  (K < p->key)  
				p=p->lchild;
			else if (K > p->key)
				p=p->rchild;
			else
			{
				free(S);
				return;			
			}
		}
		/* ����S*/
		if (K < fp->key) 
			fp->lchild=S;
		else
			fp->rchild=S;
		/* ȷ�����B�����޸�A��ƽ������ */
		if (K < A->key)
		{
			B=A->lchild;
			A->bf=A->bf+1;
		}
		else
		{
			B=A->rchild;
			A->bf=A->bf-1;
		}
		/* �޸�B��S·���ϸ�����ƽ�����ӣ�ԭֵ��Ϊ0��*/
		p=B;
		while (p!=S)
			if  (K < p->key)
			{
				p->bf=1;
				p=p->lchild;
			}
			else
			{
				p->bf=-1;
				p=p->rchild;
			}
		/* �ж�ʧ�����Ͳ�����Ӧ���� */
		if  (A->bf==2 && B->bf==1)       /* LL�� */
		{
			B=A->lchild;
			A->lchild=B->rchild;
			B->rchild=A;
			A->bf=0;
			B->bf=0;
			if (FA==NULL) 
				*avlt=B;
			else 
				if (A==FA->lchild) 
					FA->lchild=B;
				else 
					FA->rchild=B;
		}
		else
			if (A->bf==2 && B->bf==-1)       /* LR�� */
			{
				B=A->lchild;
				C=B->rchild;
				B->rchild=C->lchild;
				A->lchild=C->rchild;
				C->lchild=B;
				C->rchild=A;
				if (S->key < C->key)
				{ 
					A->bf=-1;
					B->bf=0;
					C->bf=0;
				}
				else 
					if (S->key >C->key)
					{
						A->bf=0;
						B->bf=1;
						C->bf=0;
					}
					else
					{ 
						A->bf=0;
						B->bf=0;
					}
					if  (FA==NULL) 
						*avlt=C;
					else 
						if (A==FA->lchild) 
							FA->lchild=C;
						else 
							FA->rchild=C;
			}
			else 
				if  (A->bf==-2 && B->bf==1)       /* RL�� */
				{
					B=A->rchild;
					C=B->lchild;
					B->lchild=C->rchild;
					A->rchild=C->lchild;
					C->lchild=A;
					C->rchild=B;
					if (S->key <C->key) 
					{ 
						A->bf=0;
						B->bf=-1;
						C->bf=0;
					}
					else 
						if (S->key >C->key)
						{
							A->bf=1;
							B->bf=0;
							C->bf=0;
						}
						else 
						{ 
							A->bf=0;
							B->bf=0;
						}
						if (FA==NULL)  
							*avlt=C;
						else
							if (A==FA->lchild) 
								FA->lchild=C;
							else  
								FA->rchild=C;
				}
				else 
					if (A->bf==-2 && B->bf==-1)       /* RR�� */
					{
						B=A->rchild;
						A->rchild=B->lchild;
						B->lchild=A;
						A->bf=0;
						B->bf=0;
						if (FA==NULL) 
							*avlt=B;
						else
							if (A==FA->lchild)
								FA->lchild=B;
							else 
								FA->rchild=B;
					}
	}
}

void  CreateAVLT(AVLTree  *bst, char * filename)
/*���ļ�����Ԫ�ص�ֵ��������Ӧ�Ķ���������*/
{ 
	FILE *fp;
	KeyType keynumber;
	*bst=NULL;
	fp = fopen(filename,"r+");
	while(EOF != fscanf(fp,"%d",&keynumber))
		ins_AVLtree(bst, keynumber);
}

void  PreOrder(AVLTree root) 
/*�������������, rootΪָ�������������ָ��*/
{
	if (root!=NULL)
	{
		printf("%d(%d)\t",root->key,root->bf);  /*������*/
		PreOrder(root->lchild);  /*�������������*/
		PreOrder(root->rchild);  /*�������������*/
	}
}

void  DotOrder(AVLTree root, FILE *fp) /*�������������, rootΪָ�������������ָ��*/
{
	if(root==NULL || !(root->lchild || root->rchild))
		return;
	if(root->lchild)
		fprintf(fp,"%d:sw -> %d ;\n",root->key,root->lchild->key);
	else
	{
		fprintf(fp,"NULL%dL[label=\"NULL\",shape=none] ;\n",root->key);
		fprintf(fp,"%d:sw -> NULL%dL ;\n",root->key,root->key);
	}
	if(root->rchild)
		fprintf(fp,"%d:se -> %d ;\n",root->key,root->rchild->key);
	else
	{
		fprintf(fp,"NULL%dR[label=\"NULL\",shape=none] ;\n",root->key);
		fprintf(fp,"%d:se -> NULL%dR ;\n",root->key,root->key);
	}
	DotOrder(root->lchild,fp);
	DotOrder(root->rchild,fp);
}

void MakeDot(AVLTree root)
{
	FILE *fp=fopen("AVL.gv","w+");
	fprintf(fp,"digraph AVL {\n");
	DotOrder(root,fp);
	fprintf(fp,"}\n");
	fclose(fp);
}

int main(int argc, char *argv[])
{
	AVLTree T;
	if(argc<2)
		printf("Order is AVL.exe filename.txt\n");
    CreateAVLT(&T,argv[1]);
//	PreOrder(T);
	printf("\n");
	MakeDot(T);	
	return 0;
}

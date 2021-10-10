#include "avltree.h"

/*��ƽ��������в���Ԫ��k��ʹ֮��Ϊһ���µ�ƽ�����������*/
void  ins_AVLtree(AVLTree  *avlt ,  KeyType  K)
{
	AVLTNode *S;
	AVLTNode *A;
	AVLTNode *FA;
	AVLTNode *p;
	AVLTNode *fp;
	AVLTNode *B;
	AVLTNode *C;
	
	S=(AVLTree)malloc(sizeof(AVLTNode));
	S->key=K; 
	S->lchild=S->rchild=NULL;
	S->bf=0;
	if (*avlt==NULL)  
	{
		*avlt=S;
	}	
	else 
	{ 
	/* ���Ȳ���S�Ĳ���λ��fp��ͬʱ��¼��S�Ĳ���λ�������
	   ƽ�����Ӳ�����0������-1��1���Ľ��A��AΪ���ܵ�ʧ���� */
		A=*avlt;
		FA=NULL;
		p=*avlt;  
		fp=NULL;
		while  (p!=NULL)
		{ 
			if (p->bf!=0) 
			{
				A = p;
				FA = fp;
			}
			fp=p;
			if  (K < p->key)  
			{
				p=p->lchild;
			}	
			else  
			{
				p=p->rchild;
			}	
		}
		/* ����S*/
		if (K < fp->key) 
		{
			fp->lchild=S;
		}	
		else
		{
			fp->rchild=S;
		}	
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
		{
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
				{
					*avlt=B;
				}	
				else 
					if (A==FA->lchild) 
					{
						FA->lchild=B;
					}	
					else 
					{
						FA->rchild=B;
					}	
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
					{
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
						{
							*avlt=C;
						}	
						else 
						{
							if (A==FA->lchild) 
							{
								FA->lchild=C;
							}	
							else 
							{
								FA->rchild=C;
							}	
						}	
					} 
						
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
						{
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
							{
								*avlt=C;
							}	
							else
							{
								if (A==FA->lchild) 
								{
									FA->lchild=C;
								}	
								else  
								{
									FA->rchild=C;
								}	
							}	
						}	
					}
					else 
					{
						if (A->bf==-2 && B->bf==-1)       /* RR�� */
						{
							B=A->rchild;
							A->rchild=B->lchild;
							B->lchild=A;
							A->bf=0;
							B->bf=0;
							if (FA==NULL) 
							{
								*avlt=B;
							}	
							else
							{
								if (A==FA->lchild)
								{
									FA->lchild=B;
								}	
								else 
								{
									FA->rchild=B;
								}	
							}	
						}
					}	
				}
		}
}

/*�Ӽ�������Ԫ�ص�ֵ��������Ӧ�Ķ���������*/
void  CreateAVLT(AVLTree  *bst)
{ 
	KeyType key;
	*bst=NULL;
	scanf("%d", &key);
	while (key!=ENDKEY)   /*ENDKEYΪ�Զ��峣��*/
	{
		ins_AVLtree(bst, key);
		scanf("%d", &key);
	}
}

/*�������������, rootΪָ�������������ָ��*/
void  PreOrder_(AVLTree root) 
{
	if (root!=NULL)
	{
		printf("%d  ",root->key);   /*������*/
		PreOrder(root->lchild);  	/*�������������*/
		PreOrder(root->rchild);     /*�������������*/
	}
}

 #include "avltree.h"
// #include "bst.h"
// #include "hash.h"
// #include "seqsearch.h"
// #include "binsearch.h"
// #include "mbtree.h"

int main(int argc, char *argv[])
{

#ifdef AVLTREE_H
	AVLTree T;
	
	printf("��������������������������:\n");
    CreateAVLT(&T);
	printf("��������������Ϊ:\n");
	PreOrder(T);
#endif

#ifdef BST_H
	BSTree 	T;
	int 	k;
	BSTree 	result;
	
	printf("��������������������������:\n");
    CreateBST(&T);
	printf("��������������Ϊ:");
	PreOrder(T);
	printf("\n������Ҫ���ҵ�Ԫ��:");
	fflush(stdin);
	scanf("%d",&k);
	result = SearchBST(T,k);
	if (result != NULL)
	{
		printf("Ҫ���ҵ�Ԫ��Ϊ%d\n",result->key);
	}	
	else
	{
		printf("δ�ҵ�!\n");
	}	
	result = DelBST(T,k);
	PreOrder(result);
#endif

#ifdef HASH_H
	int 		i;
	int 		j;
	int 		n;
	int 		p;
	int 		hj;
	int 		k;
	int 		result;
	HashTable 	ht;
	
	for(i=0; i<m; i++)
	{
		ht[i].key = NULLKEY;
	} 
	
	printf("�������ϣ���Ԫ�ظ���:");
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		printf("�������%d��Ԫ��:",i);
		fflush(stdin);
		scanf("%d",&p);
		j = hash(p);
		if (ht[j].key == NULLKEY)
		{
			ht[j].key = p;
		}	
		else
		{ 
			for (i=1; i<=m-1;  i++)
			{
				hj=(j+i) % m;
				if  (ht[hj].key==NULLKEY) 
				{
					ht[j].key = p;
					i = m;
				}
				
			}
			
		}

	}
	printf("������Ҫ���ҵ�Ԫ��:");
	fflush(stdin);
	scanf("%d",&k);
	result = HashSearch(ht,k);
	if(result == -1)
	{
		printf("δ�ҵ�!\n");
	}	
	else
	{
		printf("Ԫ��λ��Ϊ%d\n",result);
	}	
#endif

#ifdef SEQSEARCH_H
	RecordList 	l;
	int 		locate1;
	int 		locate2;
	KeyType 	k;
	
	createlist(&l);
	printf("������Ҫ���ҵ�Ԫ��:");
	fflush(stdin);
	scanf("%c",&k);
	locate1 = SeqSearch(l,k);
	if(locate1 == 0)
	{
		printf("δ�ҵ�!\n");
	}	
	else
	{
		printf("��Ԫ���ڱ��е�λ��Ϊ%d\n",locate1);
	}	
	locate2 = SeqSearch2(l,k);
	if(locate2 == 0)
	{
		printf("δ�ҵ�!\n");
	}	
	else
	{
		printf("��Ԫ���ڱ��е�λ��Ϊ%d\n",locate2);
	}	
#endif

#ifdef BINSEARCH_H
	RecordList 	l;
	int 		locate;
	KeyType 	k;
	
	createlist(&l);
	printf("������Ҫ���ҵ�Ԫ��:");
	fflush(stdin);
	scanf("%c",&k);
	locate = BinSrch(l,k);
	if(locate == 0)
	{
		printf("δ�ҵ�!\n");
	}	
	else
	{
		printf("��Ԫ���ڱ��е�λ��Ϊ%d\n",locate);
	}	
#endif

#ifdef MBTREE_H
	Mbtree 		*bt;
	Mbtree 		*rp;
	Mbtree 		*newp;
	KeyType  	key;
	int 		ipos;
	
	bt = (Mbtree *)malloc(sizeof(Mbtree));
	Creatembtree(bt);
	printf("�����ɹ�ok!\n");
	
	key = 12;
	printf("С�ڵ���key�����ؼ������: %d\n", search(*bt, key));
	
	printf("��ԭ��2��λ�ϲ���һ���µ�mbtree\n");
	ipos = 2;
	rp = (Mbtree *)malloc(sizeof(Mbtree));
	Creatembtree(rp);
	insert(*bt,	ipos,  key, *rp);
	
	printf("����B_��\n");
	newp = (Mbtree *)malloc(sizeof(Mbtree));
	split (*bt,	newp);
	/*
	ins_mbtree(*mbt,  k, q, i);
	
	srch_mbtree(mbt, k, *np, *pos);
	*/
    free(bt);
    free(rp);
    free(newp);
#endif
	
	return 0;
}

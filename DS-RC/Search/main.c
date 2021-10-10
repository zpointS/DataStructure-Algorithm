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
	
	printf("建立二叉排序树，请输入序列:\n");
    CreateAVLT(&T);
	printf("先序遍历输出序列为:\n");
	PreOrder(T);
#endif

#ifdef BST_H
	BSTree 	T;
	int 	k;
	BSTree 	result;
	
	printf("建立二叉排序树，请输入序列:\n");
    CreateBST(&T);
	printf("先序遍历输出序列为:");
	PreOrder(T);
	printf("\n请输入要查找的元素:");
	fflush(stdin);
	scanf("%d",&k);
	result = SearchBST(T,k);
	if (result != NULL)
	{
		printf("要查找的元素为%d\n",result->key);
	}	
	else
	{
		printf("未找到!\n");
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
	
	printf("请输入哈希表的元素个数:");
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		printf("请输入第%d个元素:",i);
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
	printf("请输入要查找的元素:");
	fflush(stdin);
	scanf("%d",&k);
	result = HashSearch(ht,k);
	if(result == -1)
	{
		printf("未找到!\n");
	}	
	else
	{
		printf("元素位置为%d\n",result);
	}	
#endif

#ifdef SEQSEARCH_H
	RecordList 	l;
	int 		locate1;
	int 		locate2;
	KeyType 	k;
	
	createlist(&l);
	printf("请输入要查找的元素:");
	fflush(stdin);
	scanf("%c",&k);
	locate1 = SeqSearch(l,k);
	if(locate1 == 0)
	{
		printf("未找到!\n");
	}	
	else
	{
		printf("该元素在表中的位置为%d\n",locate1);
	}	
	locate2 = SeqSearch2(l,k);
	if(locate2 == 0)
	{
		printf("未找到!\n");
	}	
	else
	{
		printf("该元素在表中的位置为%d\n",locate2);
	}	
#endif

#ifdef BINSEARCH_H
	RecordList 	l;
	int 		locate;
	KeyType 	k;
	
	createlist(&l);
	printf("请输入要查找的元素:");
	fflush(stdin);
	scanf("%c",&k);
	locate = BinSrch(l,k);
	if(locate == 0)
	{
		printf("未找到!\n");
	}	
	else
	{
		printf("该元素在表中的位置为%d\n",locate);
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
	printf("创建成功ok!\n");
	
	key = 12;
	printf("小于等于key的最大关键字序号: %d\n", search(*bt, key));
	
	printf("在原来2号位上插入一个新的mbtree\n");
	ipos = 2;
	rp = (Mbtree *)malloc(sizeof(Mbtree));
	Creatembtree(rp);
	insert(*bt,	ipos,  key, *rp);
	
	printf("分裂B_树\n");
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

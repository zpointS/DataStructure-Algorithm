#include "seqsearch.h"

void createlist(RecordList *l)
{
	int 	i;
	int 	len;
	KeyType ch;

	printf("���������Ա�ĳ���:");
	scanf("%d",&len);
	l->length = len;
	for(i=1; i<=len; i++)
	{
		printf("���������Ա�ĵ�%d��Ԫ��:",i);
		fflush(stdin);
		scanf("%c",&ch);
		l->r[i].key = ch;
	}
}

/*��˳���l��˳�������ؼ��ֵ���k��Ԫ�أ����ҵ�������ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0*/
int SeqSearch(RecordList  l,  KeyType  k)
{
	int i;
	l.r[0].key=k; 
	i=l.length;
	while (l.r[i].key!=k)
	{
		i--;
	}  
	
	return(i);
}

/*����"������"������˳����в��ҹؼ��ֵ���k��Ԫ��*/
int SeqSearch2(RecordList l,  KeyType k)
{
	int i;
	i = l.length;
	while (i>=1&&l.r[i].key!=k)  i--;
	if (i>=1) 
	{
		return(i);
	}	
	else
	{
		return (0);
	}	
}

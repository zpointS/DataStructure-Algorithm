#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct CSNode
{
	DataType  data;                  /*�����Ϣ*/
	struct CSNode  *FirstChild;      /*��һ������*/
	struct CSNode  *Nextsibling;     /*��һ���ֵ�*/
}CSNode, *CSTree;








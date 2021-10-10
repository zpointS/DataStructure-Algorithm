#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define OK		1
#define ERROR	0
#define TRUE	1
#define FALSE	0


#define	MAXSIZE  100          /*此处的宏定义常量表示线性表可能达到的最大长度*/

typedef int ElemType; 
typedef  struct
{ 
	ElemType  *elem;          // 线性表数组起始地址
    int		  length;         // 线性表占用的数组空间f
	int       last;           /*记录线性表中最后一个元素在数组elem[ ]中的位置（下标值），空表置为-1*/
}SeqList;

/*************************************************************************
 *           初始化、销毁、随机赋值 线性表L           *
 *************************************************************************/ 
void InitialSeqList(SeqList * L, int n);
void DestroySeqList(SeqList * L);
void SetRandNumSeqList(SeqList * L, int n);

/**
 * 查找元素e在顺序表L中的位置 
 */
int  LocateSeqList(SeqList L, ElemType e);

/**
 * 在L中第i个位置之前插入新的数据元素e，L的长度加1 
 */
int  InsertSeqList(SeqList *L, int pos, ElemType e);

/**
 * 删除L中第i个位置上元素e，并返回该元素 
 */
int  DeletSeqList(SeqList *L, int i);

/*************************************************************************
 *           Graphviz dot draw picture           *
 *************************************************************************/ 
 
void ShowSeqList(SeqList *L, char *gvfilename);
 
#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct node1
{
	char data;
	struct node1 *next;
}Node1, *LinkList1;

typedef struct node2
{
	char data1;
	char data2;
	struct node2 *next;
}Node2, *LinkList2;

#endif // LINKLIST_H

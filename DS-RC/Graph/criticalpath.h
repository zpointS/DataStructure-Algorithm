#ifndef CRITICALPATH_H
#define CRITICALPATH_H

#include <stdio.h> 
#include <stdlib.h> 
//#include <iomanip.h> 
#include <process.h> 

typedef struct node 
{ 
	int 		adjvex; 
	int 		dut; 
	struct node *next; 
}edgenode; 

typedef struct 
{ 
	int			projectname; 
	int 		id; 
	edgenode	*link; 
}vexnode; 


void CreateGraphic(vexnode* Graphicmap,int projectnumber,int activenumber) ;

int SearchMapPath(vexnode* Graphicmap,int projectnumber,int activenumber,int totaltime);

void seekkeyroot();

#endif // CRITICALPATH_H

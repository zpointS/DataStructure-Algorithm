#include "seqlist.h"
#include <stdio.h>
#include <windows.h>

int main(int argc, char *argv[])
{
	SeqList seqlist;
	SeqList * pList;
	pList = &seqlist;
	if(argc<3)
	{
		printf("SeqListTest.exe [maxnum] [datafile.txt]\n");
		return 0x01;	
	}
	int maxnum = atoi(argv[1]);
	FILE *pdatafile = fopen(argv[2],"r+");
	
	char * gvfigurename = "SeqListShow.gv";
	InitialSeqList(pList,maxnum);
	int inum;
	int i = 0;
	while(EOF != fscanf(pdatafile,"%d",&inum))
		InsertSeqList(pList, i++,inum);
	ShowSeqList(pList,gvfigurename);
	system();
	return 0;
}

#include "criticalpath.h"

void CreateGraphic(vexnode* Graphicmap,int projectnumber,int activenumber)
{
    int 		begin;
	int 		end;
	int 		duttem;
    int 		i;
	int		 	k;
    edgenode	*p;
    for(i=0; i<projectnumber; i++)
    {
        Graphicmap[i].projectname=i;
        Graphicmap[i].id =0;
        Graphicmap[i].link =NULL;
    }
    printf("某项目的开始到结束在图中的节点输入<vi,vj,dut>\n");
    printf("如：3,4,9 回车表示第三节点到第四节点之间的活动用了9个单位时间\n");
    for(k=0; k<activenumber; k++)
    {
        scanf("%d,%d,%d",&begin,&end,&duttem);
        p=(edgenode*)malloc(sizeof(edgenode));
        p->adjvex =end-1;
        p->dut =duttem;
        Graphicmap[end-1].id ++;
        p->next =Graphicmap[begin-1].link ;
        Graphicmap[begin-1].link =p;
    }
}

int SearchMapPath(vexnode* Graphicmap,int projectnumber,int activenumber,int totaltime)
{
    int 		i;
	int			j;
	int			k;
	int			m;
    int			front;
	int			rear;
    int*		topologystack; // 用来保存拓扑排列
    int*		vl;            // 用来表示在不推迟整个工程的前提下，VJ允许最迟发生的时间
    int*		ve;			   // 用来表示Vj最早发生时间
    int*		l;             // 用来表示活动Ai最迟完成开始时间
    int*		e;             // 表示活动最早开始时间
    edgenode	*p;
    
    topologystack=(int*)malloc(projectnumber*sizeof(int));
    vl=(int*)malloc(projectnumber*sizeof(int));
    ve=(int*)malloc(projectnumber*sizeof(int));
    l=(int*)malloc(activenumber*sizeof(int));
    e=(int*)malloc(activenumber*sizeof(int));
    
	m = 0;
    front = rear = -1;
    totaltime = 0;
    
	for(i=0; i<projectnumber; i++) ve[i]=0;
    for(i=0; i<projectnumber; i++)
    {
        if(Graphicmap[i].id==0)
        {
            topologystack[++rear]=i;
            m++;
        }
    }
    while(front!=rear)
    {
        front++;
        j=topologystack[front];
        m++;
        p=Graphicmap[j].link ;
        while(p)
        {
            k=p->adjvex ;
            Graphicmap[k].id --;
            if(ve[j]+p->dut >ve[k])
            {
            	ve[k]=ve[j]+p->dut ;
            }    
            if(Graphicmap[k].id ==0)
            {
            	topologystack[++rear]=k;
            }    
            p=p->next ;
        }
    }
    if(m<projectnumber)
    {
        printf("\n本程序所建立的图有回路不可计算出关键路径\n");
        printf("将退出本程序\n");
        return 0;
    }
    totaltime=ve[projectnumber-1];
    for(i=0; i<projectnumber; i++)
    {
    	vl[i]=totaltime;
    }    
    for(i=projectnumber-2; i>=0; i--)
    {
        j=topologystack[i];
        p=Graphicmap[j].link ;
        while(p)
        {
            k=p->adjvex ;
            if((vl[k]-p->dut )<vl[j])
            {
            	vl[j]=vl[k]-p->dut ;
            }    
            p=p->next ;
        }
    }
    i=0;
    printf("| 起点 | 终点 |  最早开始时间  |  最迟完成时间  | 差值 |  备注  |\n");
    for(j=0; j<projectnumber; j++)
    {
        p=Graphicmap[j].link;
        while(p)
        {
            k=p->adjvex ;
            e[++i]=ve[j];
            l[i]=vl[k]-p->dut;
            printf("| %4d | %4d |    %4d    |    %4d    | %4d |",Graphicmap[j].projectname +1,Graphicmap[k].projectname +1,e[i],l[i],l[i]-e[i]);
            if(l[i]==e[i])
            {
            	printf(" 关键活动 |");
            }    
            printf("\n");
            p=p->next ;
        }
    }
    return 1;
}

void seekkeyroot()
{
    int 		projectnumber;
	int 		activenumber;
	int 		totaltime;
    vexnode* 	Graphicmap;
    
    totaltime = 0;
    
    system("cls");
    printf("请输入这个工程的化成图形的节点数:");
    scanf("%d",&projectnumber);
    printf("请输入这个工程的活动个数:");
    scanf("%d",&activenumber);
    Graphicmap=(vexnode*)malloc(projectnumber*sizeof(vexnode));
    CreateGraphic(Graphicmap,projectnumber,activenumber);
    SearchMapPath(Graphicmap,projectnumber,activenumber,totaltime);
    printf("整个工程所用的最短时间为：%d个单位时间\n",totaltime);
    system("pause");
}

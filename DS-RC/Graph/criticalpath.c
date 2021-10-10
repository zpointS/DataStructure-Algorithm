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
    printf("ĳ��Ŀ�Ŀ�ʼ��������ͼ�еĽڵ�����<vi,vj,dut>\n");
    printf("�磺3,4,9 �س���ʾ�����ڵ㵽���Ľڵ�֮��Ļ����9����λʱ��\n");
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
    int*		topologystack; // ����������������
    int*		vl;            // ������ʾ�ڲ��Ƴ��������̵�ǰ���£�VJ������ٷ�����ʱ��
    int*		ve;			   // ������ʾVj���緢��ʱ��
    int*		l;             // ������ʾ�Ai�����ɿ�ʼʱ��
    int*		e;             // ��ʾ����翪ʼʱ��
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
        printf("\n��������������ͼ�л�·���ɼ�����ؼ�·��\n");
        printf("���˳�������\n");
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
    printf("| ��� | �յ� |  ���翪ʼʱ��  |  ������ʱ��  | ��ֵ |  ��ע  |\n");
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
            	printf(" �ؼ�� |");
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
    printf("������������̵Ļ���ͼ�εĽڵ���:");
    scanf("%d",&projectnumber);
    printf("������������̵Ļ����:");
    scanf("%d",&activenumber);
    Graphicmap=(vexnode*)malloc(projectnumber*sizeof(vexnode));
    CreateGraphic(Graphicmap,projectnumber,activenumber);
    SearchMapPath(Graphicmap,projectnumber,activenumber,totaltime);
    printf("�����������õ����ʱ��Ϊ��%d����λʱ��\n",totaltime);
    system("pause");
}

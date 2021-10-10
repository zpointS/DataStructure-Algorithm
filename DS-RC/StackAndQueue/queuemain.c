// #include "linkqueue.h"
#include "seqqueue.h"

int main()
{
#ifdef SEQQUEUE_H
	SeqQueue			sq;
	QueueElementType	e; 
#endif 	

#ifdef LINKQUEUE_H
	LinkQueue			lq;
	QueueElementType	e; 
#endif 

#ifdef SEQQUEUE_H
	printf("��ʼ��˳�����...\n");
    InitQueue(&sq);
    
	printf("��˳������в���a,b,c\n");
    EnterQueue(&sq, 'a');
    EnterQueue(&sq, 'b');
    EnterQueue(&sq, 'c');
    
    DeleteQueue(&sq, &e);
    printf("ɾ��˳�����Ԫ��%c\n", e); 
    
	printf("��˳������в���d\n");
    EnterQueue(&sq, 'd');
    
    GetHead(&sq, &e); 
    printf("ȡ��˳����е�ͷԪ��%c\n", e);
    
    printf("�ж��б��Ƿ�Ϊ��:%d\n", IsEmpty(&sq));

#endif 	

#ifdef LINKQUEUE_H
    printf("��ʼ����ʽ����...\n");
    LQInitQueue(&lq);
    
	printf("����ʽ�����в���a,b,c\n");
    LQEnterQueue(&lq, 'a');
    LQEnterQueue(&lq, 'b');
    LQEnterQueue(&lq, 'c');
    
    LQDeleteQueue(&lq, &e);
    printf("ɾ����ʽ����Ԫ��%c\n", e); 
    
	printf("����ʽ�����в���d\n");
    LQEnterQueue(&lq, 'd');
    
    LQGetHead(&lq, &e);
    printf("ȡ����ʽ���е�ͷԪ��%c\n", e);
    
#endif // END LINKQUEUE_H�� 
	return 0;
}

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
	printf("初始化顺序队列...\n");
    InitQueue(&sq);
    
	printf("向顺序队列中插入a,b,c\n");
    EnterQueue(&sq, 'a');
    EnterQueue(&sq, 'b');
    EnterQueue(&sq, 'c');
    
    DeleteQueue(&sq, &e);
    printf("删除顺序队列元素%c\n", e); 
    
	printf("向顺序队列中插入d\n");
    EnterQueue(&sq, 'd');
    
    GetHead(&sq, &e); 
    printf("取出顺序队列的头元素%c\n", e);
    
    printf("判断列表是否为空:%d\n", IsEmpty(&sq));

#endif 	

#ifdef LINKQUEUE_H
    printf("初始化链式队列...\n");
    LQInitQueue(&lq);
    
	printf("向链式队列中插入a,b,c\n");
    LQEnterQueue(&lq, 'a');
    LQEnterQueue(&lq, 'b');
    LQEnterQueue(&lq, 'c');
    
    LQDeleteQueue(&lq, &e);
    printf("删除链式队列元素%c\n", e); 
    
	printf("向链式队列中插入d\n");
    LQEnterQueue(&lq, 'd');
    
    LQGetHead(&lq, &e);
    printf("取出链式队列的头元素%c\n", e);
    
#endif // END LINKQUEUE_H　 
	return 0;
}

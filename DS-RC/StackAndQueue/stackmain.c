// #include "seqstack.h"
// #include "linkstack.h"
#include "dqstack.h"
 
int main()
{
#ifdef SEQSTACK_H
    SeqStack			sstack;
    StackElementType	a;
#endif
	
#ifdef LINKSTACK_H
    LinkStack			lstack;
	StackElementType	e;
#endif

#ifdef DQSTACK_H
    DqStack				dstack;
    StackElementType	e;
	e = 0;
#endif		
	
#ifdef SEQSTACK_H
	printf("��ʼ��˳��ջ...\n");
    SSInitStack(&sstack);
    
	printf("isempty: %d\n", IsEmpty(&sstack));
    printf("isfull: %d\n", IsFull(&sstack));
    
	a = 'x';
	printf("��ջ��ѹ��Ԫ��x\n");
    SSPush(&sstack, a);
    a = '\0';
    SSPop(&sstack, &a);
    printf("������Ԫ��Ϊ: %c\n", a);
    
    printf("��ջ�зֱ�ѹ��Ԫ��1��2��3\n");
	SSPush(&sstack, '1');
    SSPush(&sstack, '2');
    SSPush(&sstack, '3');
    GetTop(&sstack, &a); 
    printf("ջ��Ԫ��Ϊ: %c\n", a);
    
    printf("Match('{','d'): %d\n",Match('{','d')); 
    printf("Match'{','}': %d\n", Match('{','}'));
#endif
   
#ifdef LINKSTACK_H
    printf("��ջ��ѹ��Ԫ��%c\n", 'a');
	LSPush(&lstack, 'a');
	LSPop(&lstack, &e);
	printf("����ջ��Ԫ���ǣ�%c\n", e);
#endif

#ifdef DQSTACK_H
    DSInitStack(&dstack);
    printf("��ջ��ѹ��Ԫ��%c %c\n", 'X', 'Y');
    DSPush(&dstack, 'X', 0);
    DSPush(&dstack, 'Y', 1);
    Visit(&dstack);
    DSPop(&dstack, &e, 0); 
    printf("����Ԫ��Ϊ%c\n", e);
#endif

	return 0;
}

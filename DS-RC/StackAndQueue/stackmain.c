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
	printf("初始化顺序栈...\n");
    SSInitStack(&sstack);
    
	printf("isempty: %d\n", IsEmpty(&sstack));
    printf("isfull: %d\n", IsFull(&sstack));
    
	a = 'x';
	printf("向栈中压入元素x\n");
    SSPush(&sstack, a);
    a = '\0';
    SSPop(&sstack, &a);
    printf("弹出的元素为: %c\n", a);
    
    printf("向栈中分别压入元素1，2，3\n");
	SSPush(&sstack, '1');
    SSPush(&sstack, '2');
    SSPush(&sstack, '3');
    GetTop(&sstack, &a); 
    printf("栈顶元素为: %c\n", a);
    
    printf("Match('{','d'): %d\n",Match('{','d')); 
    printf("Match'{','}': %d\n", Match('{','}'));
#endif
   
#ifdef LINKSTACK_H
    printf("向栈中压入元素%c\n", 'a');
	LSPush(&lstack, 'a');
	LSPop(&lstack, &e);
	printf("弹出栈的元素是：%c\n", e);
#endif

#ifdef DQSTACK_H
    DSInitStack(&dstack);
    printf("向栈中压入元素%c %c\n", 'X', 'Y');
    DSPush(&dstack, 'X', 0);
    DSPush(&dstack, 'Y', 1);
    Visit(&dstack);
    DSPop(&dstack, &e, 0); 
    printf("弹出元素为%c\n", e);
#endif

	return 0;
}

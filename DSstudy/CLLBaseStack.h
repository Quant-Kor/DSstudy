#ifndef __CLLBASE_STACK_H__
#define __CLLBASE_STACK_H__

#include "CLinkedList.h"

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _listStack
{
	List * plist;           // 리스트 포인터형으로 plist를 생성해야함!
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif
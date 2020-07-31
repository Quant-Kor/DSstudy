#ifndef __CLLBASE_STACK_H__
#define __CLLBASE_STACK_H__

#include "CLinkedList.h"

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _listStack
{
	List * plist;           // ����Ʈ ������������ plist�� �����ؾ���!
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif
#include <stdio.h>
#include <stdlib.h>
#include "CLLBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->plist = malloc(sizeof(List));       // ����Ʈ �����ͷ� ������Ͽ��� �����Ͽ����Ƿ� ������ ������ malloc�� ����Ͽ� �Ҵ�!
	ListInit(pstack->plist);
}
int SIsEmpty(Stack* pstack)
{
	if (LCount(pstack->plist) == 0)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	LInsertFront(pstack->plist, data);
}
Data SPop(Stack* pstack)
{
	Data data;
	LFirst(pstack->plist, &data); // ù��° ���� �����͸� ������ �ϹǷ� LFirst�� �� �ڿ� LRemove�� ���!
	LRemove(pstack->plist);
	return data;
}
Data SPeek(Stack* pstack)
{
	Data data;
	LFirst(pstack->plist, &data);
	return data;
}
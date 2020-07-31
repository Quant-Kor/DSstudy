#include <stdio.h>
#include <stdlib.h>
#include "CLLBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->plist = malloc(sizeof(List));       // 리스트 포인터로 헤더파일에서 생성하였으므로 저장할 공간을 malloc을 사용하여 할당!
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
	LFirst(pstack->plist, &data); // 첫번째 부터 데이터를 꺼내야 하므로 LFirst를 한 뒤에 LRemove를 사용!
	LRemove(pstack->plist);
	return data;
}
Data SPeek(Stack* pstack)
{
	Data data;
	LFirst(pstack->plist, &data);
	return data;
}
#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int WhoIsPrecede(Point* p1, Point* p2)
{
	if (p1->xpos < p2->xpos)
		return 0;
	else if (p1->xpos > p2->xpos)
		return 1;
	else
	{
		if (p1->ypos < p1->ypos)
			return 0;
		else
			return 1;
	}

}

int main(void)
{
	List list;
	Point compPos;
	Point* ppos;

	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);

	// 4개의 데이터 저장
	ppos = malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	// 저장된 데이터의 출력
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	// xpos가 2인 모든 데이터 삭제
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos))
	{
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);
		}

		while (LNext(&list, &ppos))
		{
			if (PointComp(ppos, &compPos) == 1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	// 삭제 후 남은 데이터 전체 출력
	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}


// typedef Point * Ldata 로 선언했으므로 LInsert의 두번째 인자로 Point * ppos에서 ppos만 들어가면 되고
// LFirst나 LNext의 인자로 들어갈 때에는 매개변수로 LData * pdata 를 넣어야하므로 &ppos를 넣어주어야함!
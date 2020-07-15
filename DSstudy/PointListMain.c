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

	// 4���� ������ ����
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

	// ����� �������� ���
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	// xpos�� 2�� ��� ������ ����
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

	// ���� �� ���� ������ ��ü ���
	printf("���� �������� �� : %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}


// typedef Point * Ldata �� ���������Ƿ� LInsert�� �ι�° ���ڷ� Point * ppos���� ppos�� ���� �ǰ�
// LFirst�� LNext�� ���ڷ� �� ������ �Ű������� LData * pdata �� �־���ϹǷ� &ppos�� �־��־����!
#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	// Array List�� ���� �� �ʱ�ȭ
	List list;
	int data;
	int sum = 0;
	ListInit(&list);

	// 9���� ������ ����
	LInsert(&list, 1); LInsert(&list, 2);
	LInsert(&list, 3); LInsert(&list, 4);
	LInsert(&list, 5); LInsert(&list, 6);
	LInsert(&list, 7); LInsert(&list, 8);
	LInsert(&list, 9);

	// �� ���� ����Ͽ� ���
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		sum += data;

		while (LNext(&list, &data))
			sum += data;
	}
	printf("��ü ��: %d \n", sum);

	// 2�� ����� 3�� ����� Ž���Ͽ� ��� ����
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
		}
	}

	// ���� �� ���� ������ ��ü ���
	printf("���� �������� �� : %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}
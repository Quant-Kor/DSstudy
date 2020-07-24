#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

void ShowEmpinfo(Employee* pemp)
{
	printf("Employee ssn : %d\n", pemp->ssn);
	printf("Emplotee name : %s\n", pemp->name);
	printf("\n");
}

Employee* WhoisNextdangjik(List* plist, char* empname, int day)
{
	int i, num;
	Employee* emp;

	num = LCount(plist);

	LFirst(plist, &emp);

	if (strcpy(emp->name, empname) != 0)
	{
		for (i = 0; i < num - 1; i++)
		{
			LNext(plist, &emp);

			if (strcpy(emp->name, empname))
				break;
		}
		if (i >= num - 1)
			return NULL;
	}
	
	// 그 뒤로 날 세기
	for (i = 0; i < day; i++)
		LNext(plist, &emp);

	return emp;
}

int main(void)
{
	Employee* pemp;
	int data, i ,nodeNum;


	// 리스트 초기화
	List list;
	ListInit(&list);


	// 직원정보 저장
	pemp = malloc(sizeof(Employee));
	pemp->ssn = 1111;
	strcpy(pemp->name, "이정민1");
	LInsert(&list, pemp);

	pemp = malloc(sizeof(Employee));
	pemp->ssn = 2222;
	strcpy(pemp->name, "이정민2");
	LInsert(&list, pemp);

	pemp = malloc(sizeof(Employee));
	pemp->ssn = 3333;
	strcpy(pemp->name, "이정민3");
	LInsert(&list, pemp);

	pemp = malloc(sizeof(Employee));
	pemp->ssn = 4444;
	strcpy(pemp->name, "이정민4");
	LInsert(&list, pemp);


	pemp = WhoisNextdangjik(&list, "이정민3", 7);
	ShowEmpinfo(pemp);

	pemp = WhoisNextdangjik(&list, "이정민1", 2);
	ShowEmpinfo(pemp);

	if (LFirst(&list, &pemp))
	{
		free(pemp);
		for (i = 0; i < LCount(&list) - 1; i++)
			if(LNext(&list, &pemp))
				free(pemp);
	}

	return 0;
}
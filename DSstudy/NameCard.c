#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Namecard.h"

// NameCard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
NameCard* MakeNameCard(char* name, char* phone)
{
	NameCard* n1 = malloc(sizeof(NameCard));
	strcpy(n1->name, name);
	strcpy(n1->phone, phone);
	return n1;
}

// NameCard ����ü ������ ���� ���
void ShowNameCardInfo(NameCard* pcard)
{
	printf("%s %s\n", pcard->name, pcard->phone);
}

// �̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
int NameCompare(NameCard* pcard, char* name)
{
	return strcmp(pcard->name, name);
}

// ��ȭ��ȣ ������ ����
void ChangePhoneNum(NameCard* pcard, char* phone)
{
	strcpy(pcard->phone, phone);
}
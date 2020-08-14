#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

// ���̺��� �ʱ�ȭ
void TBLInit(Table* pt, HashFunc* f)
{
	int i;

	// ��� ���� �ʱ�ȭ
	for (i = 0; i < MAX_TBL; i++)
		(pt->tbl[i]).status = EMPTY;

	pt->hf = f; // �ؽ� �Լ� ���
}

// ���̺� Ű�� ���� ����
void TBLInsert(Table* pt, Key k, Value v)
{
	int hv = pt->hf(k);
	pt->tbl[hv].val = v;
	pt->tbl[hv].key = k;
	pt->tbl[hv].status = INUSE;
}

// Ű�� �ٰŷ� ���̺��� ������ ����
Value TBLDelete(Table* pt, Key k)
{
	int hv = pt->hf(k);

	if ((pt->tbl[hv]).status != INUSE)
	{
		return NULL;
	}
	else
	{
		(pt->tbl[hv]).status = DELETED;
		return (pt->tbl[hv]).val; // �Ҹ� ��� �� ��ȯ
	}
}

// Ű�� �ٰŷ� ���̺��� ������ Ž��
Value TBLSearch(Table* pt, Key k)
{
	int hv = pt->hf(k);

	if ((pt->tbl[hv]).status != INUSE)
		return NULL;
	else
		return (pt->tbl[hv]).val; // Ž�� ����� �� ��ȯ
}
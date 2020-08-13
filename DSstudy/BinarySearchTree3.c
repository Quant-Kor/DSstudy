#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree3.h"
#include "AVLRebalance.h"

// ���� Ž���� Ʈ���� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}

// ���� Ž�� Ʈ���� ����� ������ ����(����� �������� ����)
void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	/*
	* 
	* 	if (*pRoot == NULL)
	{
		*pRoot = MakeBTreeNode();
		SetData(*pRoot, data);
	}
	else if (data < GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->left), data);
		*pRoot = Rebalance(pRoot);
	}
	else if (data > GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->right), data);
		*pRoot = Rebalance(pRoot);
	}
	else
	{
		return NULL; // Ű�� �ߺ��� ������� �ʴ´�.
	}
	return *pRoot;
	* 
	*/

	BTreeNode* pNode = NULL;
	BTreeNode* cNode = *pRoot;
	BTreeNode* nNode = NULL;

	while (cNode != NULL)
	{
		if (data == GetData(cNode))
			return;

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// pNode�� ���� ��忡 �߰��� �� ����� ����
	nNode = MakeBTreeNode();    // �� ����� ����
	SetData(nNode, data);    // �� ��忡 ������ ����

	// pNode�� ���� ��忡 �� ��带 �߰�
	if (pNode != NULL)    // �� ��尡 ��Ʈ ��尡 �ƴ϶��,
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else    // �� ��尡 ��Ʈ �����,
	{
		*pRoot = nNode;
	}
	*pRoot = Rebalance(pRoot);
}

// ���� Ž�� Ʈ���� ������� ������ Ž��
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst;
	BSTData cd;

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL;
}

// Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּҰ��� ��ȯ�Ѵ�.
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	// ���� ����� ��Ʈ ����� ��츦 ������ ����ؾ� �ϹǷ� ���� ��Ʈ ��� pVRoot�� ����!
	BTreeNode* pVRoot = MakeBTreeNode();
	BTreeNode* pNode = pVRoot;
	BTreeNode* cNode = *pRoot;
	BTreeNode* dNode;

	// ��Ʈ ��带 pVRoot�� ����Ű�� ����� ������ �ڽ� ��尡 �ǰ� ��
	ChangeRightSubTree(pVRoot, *pRoot);

	// ���� ����� ��带 Ž��
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)
		return NULL;

	dNode = cNode;

	// ù ��° ��� : ���� ����� �ܸ� ����� ���
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// �� ��° ��� : ���� ����� �ϳ��� �ڽ� ��带 ���� ���
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode* dcNode; // ���� ����� �ڽ� ��带 ����Ŵ

		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	// �� ��° ��� : �� ���� �ڽ� ��带 ��� ���� ���
	else
	{
		BTreeNode* mNode = GetRightSubTree(dNode); // ��ü ��带 ����Ŵ
		BTreeNode* mpNode = dNode; // ��ü ����� �θ� ��� ����Ŵ
		int delData;

		// ���� ����� ��ü ��� ã��
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// ��ü ��忡 ����� ���� ������ ��忡 �����Ѵ�.
		delData = GetData(dNode); // ���� �� ������ ���
		SetData(dNode, GetData(mNode));

		// ��ü ����� �θ� ���� �ڽ� ��带 �����Ѵ�.(��ü�� ����� �ڽ� ���� �׻� �������� �����ϹǷ� GetRightSubTree�� �ι�)
		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData); // ��� ������ ����
	}

	// ������ ��尡 ��Ʈ ����� ��쿡 �߰����� ó��
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot); // ��Ʈ����� ������ �ݿ�

	free(pVRoot);
	*pRoot = Rebalance(pRoot);
	return dNode;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}

// ���� Ž�� Ʈ���� ����� ��� ����� �����͸� ����Ѵ�.
void BSTShowAll(BTreeNode* bst)
{
	InorderTraverse(bst, ShowIntData);
}
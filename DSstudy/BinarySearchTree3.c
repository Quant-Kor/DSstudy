#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree3.h"
#include "AVLRebalance.h"

// 이진 탐색의 트리의 생성 및 초기화
void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}

// 이진 탐색 트리를 대상을 데이터 저장(노드의 생성과정 포함)
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
		return NULL; // 키의 중복을 허용하지 않는다.
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

	// pNode의 서브 노드에 추가할 새 노드의 생성
	nNode = MakeBTreeNode();    // 새 노드의 생성
	SetData(nNode, data);    // 새 노드에 데이터 저장

	// pNode의 서브 노드에 새 노드를 추가
	if (pNode != NULL)    // 새 노드가 루트 노드가 아니라면,
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else    // 새 노드가 루트 노드라면,
	{
		*pRoot = nNode;
	}
	*pRoot = Rebalance(pRoot);
}

// 이진 탐색 트리를 대상으로 데이터 탐색
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

// 트리에서 노드를 제거하고 제거된 노드의 주소값을 반환한다.
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	// 삭제 대상이 루트 노드인 경우를 별도로 고려해야 하므로 가상 루트 노드 pVRoot를 만듦!
	BTreeNode* pVRoot = MakeBTreeNode();
	BTreeNode* pNode = pVRoot;
	BTreeNode* cNode = *pRoot;
	BTreeNode* dNode;

	// 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 자식 노드가 되게 함
	ChangeRightSubTree(pVRoot, *pRoot);

	// 삭제 대상인 노드를 탐색
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

	// 첫 번째 경우 : 삭제 대상이 단말 노드인 경우
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// 두 번째 경우 : 삭제 대상이 하나의 자식 노드를 갖는 경우
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode* dcNode; // 삭제 대상의 자식 노드를 가리킴

		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	// 세 번째 경우 : 두 개의 자식 노드를 모두 갖는 경우
	else
	{
		BTreeNode* mNode = GetRightSubTree(dNode); // 대체 노드를 가리킴
		BTreeNode* mpNode = dNode; // 대체 노드의 부모 노드 가리킴
		int delData;

		// 삭제 대상의 대체 노드 찾기
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// 대체 노드에 저장된 값을 삭제할 노드에 대입한다.
		delData = GetData(dNode); // 대입 전 데이터 백업
		SetData(dNode, GetData(mNode));

		// 대체 노드의 부모 노드와 자식 노드를 연결한다.(대체할 노드의 자식 노드는 항상 오른족에 존재하므로 GetRightSubTree가 두번)
		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData); // 백업 데이터 복원
	}

	// 삭제된 노드가 루트 노드인 경우에 추가적인 처리
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot); // 루트노드의 변경을 반영

	free(pVRoot);
	*pRoot = Rebalance(pRoot);
	return dNode;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}

// 이진 탐색 트리에 저장된 모든 노드의 데이터를 출력한다.
void BSTShowAll(BTreeNode* bst)
{
	InorderTraverse(bst, ShowIntData);
}
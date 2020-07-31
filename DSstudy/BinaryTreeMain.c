#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
	BTreeNode* bt1 = MakeBTreeNde(); // ��� bt1 ����
	BTreeNode* bt2 = MakeBTreeNde(); // ��� bt2 ����
	BTreeNode* bt3 = MakeBTreeNde(); // ��� bt3 ����
	BTreeNode* bt4 = MakeBTreeNde(); // ��� bt4 ����

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	printf("%d \n", GetData(GetLeftSubTree(bt1)));

	printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

	return 0;
}
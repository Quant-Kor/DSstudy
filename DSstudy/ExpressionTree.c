#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "ListBaseStack.h"
#include "BinaryTree2.h"

BTreeNode* MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode* pnode;

	int expLen = strlen(exp);
	int i;

	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		pnode = MakeBTreeNode();
		if (isdigit(exp[i]))
		{
			SetData(pnode, exp[i] - '0');
		}
		else
		{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}
		SPush(&stack, pnode);
	}

	return SPop(&stack);
}
int EvaluateExpTree(BTreeNode* bt)
{
	// 후에 구현
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode* bt)
{
	PreorderTraverse(bt, ShowNodeData);
}
void ShowInifxTypeExp(BTreeNode* bt)
{
	if (bt == NULL)
		return;

	if (bt->left != NULL || bt->right != NULL)
		printf("(");
	
	ShowInifxTypeExp(bt->left);
	ShowNodeData(bt->data);
	ShowInifxTypeExp(bt->right);

	if (bt->left != NULL || bt->right != NULL)
		printf(")");


}
void ShowPostfixTypeExp(BTreeNode* bt)
{
	PostorderTraverse(bt, ShowNodeData);
}

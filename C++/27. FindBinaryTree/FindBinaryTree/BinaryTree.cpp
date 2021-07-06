#include <iostream>
using namespace std;
#include "BinaryTree.h"

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = new BTreeNode;

	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)
		delete main->left;

	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
		delete main->right;

	main->right = sub;
}

void GetAllData(BTreeNode* bt, int* data)
{
	if (bt == NULL)
		return;

	*data += bt->data;
	GetAllData(bt->left, data);
	GetAllData(bt->right, data);

	return;
}

void PreorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;

	cout << bt->data << " ";
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}
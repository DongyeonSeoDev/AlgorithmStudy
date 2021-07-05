//20409 ¼­µ¿¿¬

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

void DeleteBTreeNode(BTreeNode* bt)
{
	delete bt;
}

BTData GetData(BTreeNode* bt)
{
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
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

void PreorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;

	cout << bt->data << endl;
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

void InorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left);
	cout << bt->data << " ";
	InorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	cout << bt->data << endl;
}

void PreorderTraverseCheck(BTreeNode* bt, vector<int>& preorderTraverseCheckValue)
{
	if (bt == NULL)
		return;

	preorderTraverseCheckValue.push_back(bt->data);
	PreorderTraverseCheck(bt->left, preorderTraverseCheckValue);
	PreorderTraverseCheck(bt->right, preorderTraverseCheckValue);
}

void PostorderTraverseCheck(BTreeNode* bt, vector<int>& postorderTraverseCheckValue)
{
	if (bt == NULL)
		return;

	PostorderTraverseCheck(bt->left, postorderTraverseCheckValue);
	PostorderTraverseCheck(bt->right, postorderTraverseCheckValue);
	postorderTraverseCheckValue.push_back(bt->data);
}

bool TreeCheck(BTreeNode* bt, vector<int> preorderTraverseValue, vector<int> postorderTraverseValue)
{
	vector<int> preorderTraverseCheckValue;
	vector<int> postorderTraverseCheckValue;

	PreorderTraverseCheck(bt, preorderTraverseCheckValue);
	PostorderTraverseCheck(bt, postorderTraverseCheckValue);

	if (preorderTraverseValue.size() == preorderTraverseCheckValue.size() && postorderTraverseValue.size() == postorderTraverseCheckValue.size())
	{
		for (int i = 0; i < (int)preorderTraverseValue.size(); i++)
		{
			if (preorderTraverseValue[i] != preorderTraverseCheckValue[i])
			{
				return false;
			}
		}

		for (int i = 0; i < (int)postorderTraverseValue.size(); i++)
		{
			if (postorderTraverseValue[i] != postorderTraverseCheckValue[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}
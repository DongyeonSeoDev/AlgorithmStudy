#pragma once
#include <vector>

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

void PreorderTraverse(BTreeNode* bt);
void InorderTraverse(BTreeNode* bt);
void PostorderTraverse(BTreeNode* bt);

bool TreeCheck(BTreeNode* bt, std::vector<int> preorderTraverseValue, std::vector<int> postorderTraverseValue);
void PreorderTraverseCheck(BTreeNode* bt, std::vector<int> &preorderTraverseCheckValue);
void PostorderTraverseCheck(BTreeNode* bt, std::vector<int> &postorderTraverseCheckValue);
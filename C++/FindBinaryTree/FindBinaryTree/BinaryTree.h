//20409 ¼­µ¿¿¬

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
void SetData(BTreeNode* bt, BTData data);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

void GetAllData(BTreeNode* bt, int* data);
void PreorderTraverse(BTreeNode* bt);
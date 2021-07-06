//문제: https://www.acmicpc.net/problem/3038

#include <iostream>
#include <cmath>
#include <vector>

#include "BinaryTree.h"

using namespace std;

struct TreeDataNumber
{
    TreeDataNumber(int num1, int num2)
    {
        this->num1 = num1;
        this->num2 = num2;
    }

    int num1;
    int num2;
};

void checkInput()
{
    if (cin.fail())
    {
        cout << "잘못된 입력 입니다." << endl;
        exit(0);
    }

    return;
}

int main()
{
    vector<BTreeNode*> trees;
    vector<int> treeData;
    vector<TreeDataNumber> treeDataNumber;

    int input;
    int treeNumber = 1;

    cin >> input;
    checkInput();

    if (input <= 0)
    {
        cout << "숫자가 너무 작습니다. 1 이상의 숫자를 입력해 주세요." << endl;
        return 0;
    }
    else if (input > 6)
    {
        cout << "숫자가 너무 큽니다. 6 이하의 숫자를 입력해 주세요." << endl;
        return 0;
    }

    //트리의 노드 만들기
    for (int i = 0; i < pow(2, input) - 1; i++)
    {
        trees.push_back(MakeBTreeNode());
        treeData.push_back(i + 1);
    }

    //트리의 노드를 순서대로 연결하기
    SetData(trees[0], 1);

    for (int i = 0; i < input - 1; i++)
    {
        int treeParentNumber = (int)pow(2, i) - 1;

        for (int j = 0; j < pow(2, i); j++)
        {
            int treeParentNumberCheck = treeParentNumber + j;
            int treeNumberCheck = i + treeNumber;

            MakeLeftSubTree(trees[treeParentNumberCheck], trees[treeNumberCheck]);
            SetData(trees[treeNumberCheck], trees[treeParentNumberCheck]->data);
            if (i == input - 2) treeData[(long long)trees[treeParentNumberCheck]->data - 1] = -1;

            treeNumberCheck += 1;

            MakeRightSubTree(trees[treeParentNumberCheck], trees[treeNumberCheck]);
            SetData(trees[treeNumberCheck], trees[treeParentNumberCheck]->data + (int)pow(2, i));
            if (i == input - 2) treeData[(long long)trees[treeParentNumberCheck]->data + (int)pow(2, i) - 1] = -1;

            treeNumber += 2;
        }

        treeNumber--;
    }

    for (int i = 0; i < pow(2, input - 1) - 1; i++)
    {
        trees[i]->data = 0;
    }

    SetData(trees[0], (int)treeData.size());
    treeData[treeData.size() - 1] = -1;

    if (input == 6)
    {
        SetData(trees[1], (int)treeData.size() - 7);
        treeData[treeData.size() - 8] = -1;

        SetData(trees[2], (int)treeData.size() - 8);
        treeData[treeData.size() - 9] = -1;
    }

    for (int i = 1; true; i++)
    {
        //근노드만 남았다면
        if (input == 6 ? input - i <= 2 : input - i <= 1)
        {
            for (int j = 0; j < (int)treeData.size(); j++)
            {
                if (treeData[j] != -1)
                {
                    trees[0]->data = treeData[j];
                    break;
                }
            }

            //전위순회 출력
            PreorderTraverse(trees[0]);
            break;
        }

        //합의 차이가 2^D를 만족하는 숫자 구하기
        int d = input - 2 - i;
        int btNumber = (int)pow(2, input - i) - 2;

        for (int j = 0; j < pow(2, input - i - 2); j++)
        {
            int rightValue = 0;
            int leftValue = 0;
            GetAllData(trees[btNumber], &rightValue);
            btNumber--;
            GetAllData(trees[btNumber], &leftValue);
            btNumber++;

            for (int k = 0; k < (int)treeData.size(); k++)
            {
                for (int l = 0; l < (int)treeData.size(); l++)
                {
                    if (((rightValue + (double)treeData[k]) - (leftValue + (double)treeData[l]) == pow(2, d) || (leftValue + (double)treeData[l]) - (rightValue + (double)treeData[k]) == pow(2, d)) && k != l && treeData[k] != -1 && treeData[l] != -1)
                    {
                        treeDataNumber.push_back(TreeDataNumber(treeData[k], treeData[l]));

                        treeData[k] = -1;
                        treeData[l] = -1;

                        k = (int)treeData.size();

                        break;
                    }
                }
            }

            //트리에 값을 집어넣기
            SetData(trees[btNumber], treeDataNumber[0].num1);
            btNumber--;
            SetData(trees[btNumber], treeDataNumber[0].num2);
            btNumber--;

            treeDataNumber.clear();
            treeDataNumber.shrink_to_fit();
        }
    }

    return 0;
}
//전위순회와 후위순회를 입력받아 중위순회를 출력하는 프로그램

#include <iostream>
#include <vector>
#include <stack>

#include "BinaryTree.h"

using namespace std;

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
    int count;
    cout << "노드의 개수를 입력해 주세요: ";
    cin >> count;
    cout << endl;
    checkInput();

    if (count < 0)
    {
        cout << "숫자가 너무 작습니다. 1이상의 숫자를 입력해 주세요." << endl;
        return 0;
    }

    vector<int> preorderTraverseValue;
    vector<int> postorderTraverseValue;
    vector<BTreeNode*> trees;

    cout << "전위순회를 적어주세요: ";
    for (int i = 0; i < count; i++)
    {
        int temp;
        cin >> temp;
        checkInput();
        preorderTraverseValue.push_back(temp);
    }
    cout << endl;

    cout << "후위순회를 적어주세요: ";
    for (int i = 0; i < count; i++)
    {
        int temp;
        cin >> temp;
        checkInput();
        postorderTraverseValue.push_back(temp);
    }
    cout << endl;

    for (int i = 0; i < count; i++)
    {
        trees.push_back(MakeBTreeNode());
        SetData(trees.back(), preorderTraverseValue[i]);
    }

    int connectNode = 1;
    int preorderNumber = 0;
    int postorderNumber = 0;
    bool isLeft = true;

    stack<int> parentNode;
    parentNode.push(0);

    while (connectNode < count)
    {
        if (isLeft)
        {
            MakeLeftSubTree(trees[preorderNumber], trees[connectNode]);
            preorderNumber = connectNode;
            parentNode.push(connectNode);
            connectNode++;
        }
        else
        {
            MakeRightSubTree(trees[preorderNumber], trees[connectNode]);
            preorderNumber = connectNode;
            parentNode.push(connectNode);
            connectNode++;
        }

        if (connectNode >= count) break;

        if (postorderTraverseValue[postorderNumber] == trees[connectNode - 1]->data)
        {
            if (isLeft)
            {
                isLeft = false;
                parentNode.pop();
                preorderNumber = parentNode.top();
                postorderNumber++;

                bool check = false;

                while (!check)
                {
                    check = true;

                    for (int i = 0; i < connectNode; i++)
                    {
                        if (postorderTraverseValue[postorderNumber] == trees[i]->data)
                        {
                            parentNode.pop();
                            postorderNumber++;

                            while (true)
                            {
                                if (GetRightSubTree(trees[parentNode.top()]) == NULL)
                                {
                                    preorderNumber = parentNode.top();
                                    break;
                                }

                                parentNode.pop();
                                postorderNumber++;
                            }

                            check = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                parentNode.pop();
                parentNode.pop();
                postorderNumber += 2;

                while (true)
                {
                    if (GetRightSubTree(trees[parentNode.top()]) == NULL)
                    {
                        preorderNumber = parentNode.top();
                        break;
                    }

                    parentNode.pop();
                    postorderNumber++;
                }

                MakeRightSubTree(trees[preorderNumber], trees[connectNode]);
                preorderNumber = connectNode;
                parentNode.push(connectNode);
                connectNode++;
                isLeft = true;
            }
        }
    }

    if (TreeCheck(trees[0], preorderTraverseValue, postorderTraverseValue))
    {
        cout << "중위순회: ";
        InorderTraverse(trees[0]);
        cout << endl;
    }
    else
    {
        cout << "잘못된 입력 입니다." << endl;
    }

    return 0;
}
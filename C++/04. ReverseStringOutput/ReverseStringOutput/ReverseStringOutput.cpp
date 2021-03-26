#include <iostream>
using namespace std;

int setNum() //입력할 문자열의 개수를 설정하는 함수
{
    int num;
    cout << "입력할 문자열의 개수를 입력해 주세요(최대 10): ";
    cin >> num;
    cout << endl;
    if (num < 1 || num > 10)
    {
        cout << "잘못된 숫자 입니다." << endl;
        exit(0);
    }
    return num;
}

void setInput(char input[10][100], int num) //입력을 받는 함수
{
    cout << "문자열을 입력해 주세요 (한글은 안됨)" << endl;
    cin.ignore();

    for (int i = 0; i < num; i++)
    {
        cout << i + 1 << ": ";
        cin.getline(input[i], 99);
    }

    cout << endl;
}

void getLast(char input[10][100], int last[10], int num) //마지막 문자를 찾는 함수
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (input[i][j] == 0)
            {
                last[i] = j;
                break;
            }
        }
    }
}

void getReverseString(char input[10][100], char reverseString[10][100], int last[10], int num) //문자열을 거꾸로 바꾸는 함수
{
    for (int i = 0; i < num; i++)
    {
        int current = last[i] - 1;

        for (int j = 0; j < last[i]; j++)
        {
            reverseString[i][j] = input[i][current];
            current--;
        }

        reverseString[i][last[i]] = 0;
    }
}

void printInput(char input[10][100], int num) //문자열을 출력하는 함수
{
    int last[10];
    char reverseString[10][100];

    getLast(input, last, num);
    getReverseString(input, reverseString, last, num);

    cout << "문자열을 거꾸로 출력" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << i + 1 << ": " << reverseString[i] << endl;
    }
}

int main()
{
    cout << "입력 받은 문자열을 거꾸로 출력하는 프로그램" << endl;

    char input[10][100];
    int num = setNum();

    setInput(input, num);
    printInput(input, num);
}
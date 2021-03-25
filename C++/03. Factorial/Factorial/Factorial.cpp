// Factorial.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

unsigned long long factorial(unsigned long long n)
{
    if (n == 0)
        return 1;

    return(n * factorial(n - 1));
}

int main()
{
    int inputNum;
    unsigned long long factorialNum;
    cout << "입력된 숫자의 팩토리얼을 구하는 프로그램" << endl << endl;
    cout << "0부터 20까지의 숫자를 입력해 주세요: ";
    cin >> inputNum;
    cout << endl;

    if (inputNum < 0 || inputNum > 20)
    {
        cout << "잘못된 숫자 입니다." << endl;
        return 0;
    }
    else
    {
        factorialNum = factorial(inputNum);
        cout << inputNum << "팩토리얼은 " << factorialNum << "입니다." << endl;
    }

    cout << inputNum << "! = " << factorialNum << endl;;

    return 0;
}
#include <iostream>
using namespace std;

void setInput(long long& num) //입력을 받는 함수
{
    cout << "-999,999,999,999,999,999 ~ 999,999,999,999,999,999중에서 숫자 1개를 입력해 주세요: ";
    
    cin >> num;

    if (num < -999999999999999999 || num > 999999999999999999)
    {
        cout << "잘못된 숫자 입니다" << endl;
        exit(0);
    }

    cout << endl;
}

void getLast(long long& num, long long& digit) //자릿수를 찾는 함수
{
    if (num >= 0)
    {
        while (true)
        {
            if (num - digit < 0)
            {
                digit /= 10;
                break;
            }

            digit *= 10;
        }
    }
    else
    {
        while (true)
        {
            if (num + digit > 0)
            {
                digit /= 10;
                break;
            }

            digit *= 10;
        }
    }
}

void getReverseString(long long& num, long long& reverseNumber, long long& digit) //숫자를 거꾸로 바꾸는 함수
{
    for (long long i = 1; i <= digit; i *= 10)
    {
        reverseNumber += num / (digit / i) * i;
        num -= num / (digit / i) * (digit / i);
    }
}

void printNumber(long long& num) //숫자를 출력하는 함수
{
    long long digit = 1;
    long long reverseNumber = 0;

    getLast(num, digit);
    getReverseString(num, reverseNumber, digit);

    cout << "숫자를 거꾸로 출력: " << reverseNumber << endl;
}

int main()
{
    cout << "입력 받은 숫자를 거꾸로 출력하는 프로그램" << endl << endl;

    long long num;

    setInput(num);
    printNumber(num);
}
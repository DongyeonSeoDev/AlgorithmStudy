#include <iostream>
using namespace std;

long long add(long long input, long long num, long long total = 0)
{
    total += input / (1 * num);

    if (num == 1)
        return total;

    return(add(input -= input / (1 * num) * num, num / 10, total));
}

long long lastCheck(long long input, long long last = 1)
{
    if ((input < 10) && (input > -10))
    {
        return 1;
    }

    if ((input / (last * 10)) <= 0)
    {
        return last;
    }
    else
    {
        return(lastCheck(input, last * 10));
    }
}

int main()
{
    long long input;
    long long last;
    cout << "숫자를 입력받아 각 자릿수의 숫자를 모두 더한 값을 출력하는 프로그램" << endl << endl;
    cout << "숫자를 입력해 주세요: ";
    cin >> input;

    if (input == 0)
    {
        cout << "각 자릿수의 숫자를 모두 더한 값은 0입니다." << endl;
        return 0;
    }

    last = lastCheck(input);
    cout << "각 자릿수의 숫자를 모두 더한 값은 "<< add(input, last) << "입니다." << endl;
}
#include <iostream>
using namespace std;

int main()
{
    unsigned long long num;
    unsigned long long total = 0;

    cout << "1부터 4294967295까지의 수 중에서 1개를 입력해 주세요: ";
    cin >> num;
    cout << endl;

    if (num < 1 || num > 4294967295)
    {
        cout << "잘못된 숫자 입니다." << endl;
        return 0;
    }

    total = ((1 + num) * num) / 2;

    cout << "1부터 " << num << "까지 연속한 수를 모두 더한 값은 " << total << "입니다" << endl;
}
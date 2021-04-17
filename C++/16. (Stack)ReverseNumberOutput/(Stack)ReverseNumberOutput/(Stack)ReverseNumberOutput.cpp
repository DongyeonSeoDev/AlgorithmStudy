#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<long long> s;

	long long num;
	long long digit = 1;

	cout << "숫자 거꾸로 출력하기(스택 사용)" << endl;
	cout << "0 이상 100경 미만의 숫자를 입력해주세요: ";
	cin >> num;

	if (cin.fail() || num >= 1000000000000000000)
	{
		cout << "잘못된 숫자 입니다." << endl;
		return 0;
	}

	while (true)
	{
		if (num - digit < 0)
		{
			digit /= 10;
			break;
		}

		digit *= 10;
	}

	for (long long i = 1; i <= digit; i *= 10)
	{
		s.push(num / (digit / i));
		num -= num / (digit / i) * (digit / i);
	}

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}
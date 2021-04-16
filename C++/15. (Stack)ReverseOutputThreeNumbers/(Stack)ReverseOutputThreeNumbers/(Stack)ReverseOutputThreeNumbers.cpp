#include <iostream>
#include <stack>
using namespace std;

int main()
{
	long long num[3];
	stack<long long> s;

	cout << "세 정수 거꾸로 출력하기 (스택 사용)" << endl;

	cout << "-920경 이상 920경 이하의 숫자를 입력해주세요" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << "번째 숫자 입력: ";
		cin >> num[i];

		if (cin.fail() || num[i] < -9200000000000000000 || num[i] > 9200000000000000000)
		{
			cout << "잘못된 숫자 입니다." << endl;
			return 0;
		}

		s.push(num[i]);
	}

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string inputData;
stack<string> dataStack;

int main()
{
	int count;

	cout << "데이터의 갯수를 입력해 주세요: ";
	cin >> count;

	if (cin.fail() || count > 1000 || count < 1)
	{
		cout << "잘못된 입력 입니다." << endl;
		return 0;
	}

	cin.ignore();
	for (int i = 0; i < count; i++)
	{
		cout << i + 1 << "번째 데이터를 입력해 주세요: ";
		getline(cin, inputData);
		dataStack.push(inputData);
	}

	cout << endl;

	while (!dataStack.empty())
	{
		cout << dataStack.top() << endl;
		dataStack.pop();
	}
}
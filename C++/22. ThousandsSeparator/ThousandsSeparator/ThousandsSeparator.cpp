#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int input = 0;
	int digit = 1;
	int numCount = 0;
	bool isMinus = false;
	stack<int> numStack;
	stack<char> charStack;

	string numString = "";

	cout << "숫자를 입력해주세요: ";
	cin >> input;

	if (cin.fail() || input >= 1000000000 || input <= -1000000000)
	{
		cout << "잘못된 숫자 입니다." << endl;
		return 0;
	}

	if (input < 0)
	{
		isMinus = true;
		input = -input;
	}

	while (true)
	{
		if (input - digit < 0)
		{
			digit /= 10;
			break;
		}

		digit *= 10;
	}

	for (int i = 1; i <= digit; i *= 10)
	{
		numStack.push(input / (digit / i));
		input -= input / (digit / i) * (digit / i);
	}

	while (!numStack.empty())
	{
		charStack.push(numStack.top() + '0');
		numCount++;

		numStack.pop();

		if (numCount % 3 == 0 && !numStack.empty())
		{
			charStack.push(',');
		}
	}

	cout << "결과: ";

	if (isMinus == true) cout << "-";

	while (!charStack.empty())
	{
		cout << charStack.top();
		charStack.pop();
	}
}
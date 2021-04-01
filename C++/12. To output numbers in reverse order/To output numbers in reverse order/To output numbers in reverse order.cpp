#include <iostream>
using namespace std;

void print(int num)
{
	cout << num << endl;

	if (num == 1)
		return;

	return(print(num - 1));
}

int main()
{
	int input;
	cout << "입력한 숫자부터 1까지의 숫자를 역순으로 출력하기" << endl << endl;
	cout << "숫자를 입력해 주세요(1 ~ 4000): ";
	cin >> input;
	cout << endl;

	if (input < 1 || input > 4000)
	{
		cout << "잘못된 숫자 입니다" << endl;
		return 0;
	}

	print(input);
}
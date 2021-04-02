#include <iostream>
using namespace std;

void print(int minNum, int maxNum, int num, int EvenOrOdd)
{
	if (num % 2 == EvenOrOdd)
	{
		cout << num << " ";
	}

	if (num == maxNum)
	{
		return;
	}

	return(print(minNum, maxNum, num + 1, EvenOrOdd));
}

int main()
{
	int input1;
	int input2;

	int EvenOrOdd;

	cout << "숫자 2개를 입력 받아 두 수 사이의 홀수나 짝수 출력하기" << endl << endl;

	cout << "0 또는 1를 입력해 주세요 (짝수를 출력: 0, 홀수를 출력: 1): ";
	cin >> EvenOrOdd;
	cout << endl;

	if (EvenOrOdd != 0 && EvenOrOdd != 1)
	{
		cout << "잘못된 숫자 입니다" << endl;
		return 0;
	}

	cout << "첫번째 숫자 ( 0 ~ 4000사이로 입력해 주세요 ): ";
	cin >> input1;

	if (input1 < 0 || input1 > 4000)
	{
		cout << "잘못된 숫자 입니다" << endl;
		return 0;
	}

	cout << "두번째 숫자 ( 0 ~ 4000사이로 입력해 주세요 ): ";
	cin >> input2;

	if (input2 < 0 || input2 > 4000)
	{
		cout << "잘못된 숫자 입니다" << endl;
		return 0;
	}

	cout << endl;

	if (EvenOrOdd == 1)
	{
		cout << input1 << "과 " << input2 << "사이의 " << "홀수를 출력" << endl << endl;
	}
	else
	{
		cout << input1 << "과 " << input2 << "사이의 " << "짝수를 출력" << endl << endl;
	}


	if (input1 < input2)
	{
		print(input1, input2, input1, EvenOrOdd);
	}
	else
	{
		print(input2, input1, input2, EvenOrOdd);
	}
}
#include <iostream>
using namespace std;

long long compare(int num, long long value = -9223372036854775807)
{
	long long input;
	cin >> input;

	if (num == 1)
		return(input > value ? input : value);

	return(input > value ? compare(num - 1, input) : compare(num - 1, value));
}

int main()
{
	int count;

	cout << "입력받은 숫자 중에서 최댓값을 출력하는 프로그램" << endl << endl;

	cout << "입력할 숫자의 개수를 입력해 주세요(최소 2개 ~ 최대 100개): ";
	cin >> count;
	cout << endl;

	if (count < 2 || count > 100)
	{
		cout << "잘못된 숫자 입니다" << endl;
		return 0;
	}

	cout << "숫자를 " << count << "개 입력해 주세요: ";
	cout << endl << "입력하신 숫자 중에서 제일 큰 숫자는 " << compare(count) << "입니다." << endl;
}
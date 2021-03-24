#include <iostream>
using namespace std;

int getCurrentYear()
{
	time_t current_time;
	struct tm current_tm = { 0 };
	current_time = time(NULL);
	localtime_s(&current_tm, &current_time);
	return current_tm.tm_year + 1900;
}

void printYear(int year)
{
	int currentYear = getCurrentYear();
	cout << "나이: " << currentYear - year + 1 << endl;
	cout << "출생년도: " << year << endl;
}

void chcekInput7(char input[])
{
	int year = 0;
	int code = input[6] - '0';
	string massage[] = { "여자 입니다.", "남자 입니다" };

	cout << massage[code % 2] << endl;
	if (code <= 2)
	{
		year = 1900;
	}
	else
	{
		year = 2000;
	}

	year += ((input[0] - '0') * 10) + (input[1] - '0');
	printYear(year);
}

void printArea(int areaNum)
{
	int areaCode[11] = { 8, 4, 3, 3, 7, 9, 5, 8, 7, 12, 24 };
	string areaName[11] = { "서울", "부산", "인천", "경기도 주요 도시", "그 밖의 경기도", "강원도", "충청북도", "충청남도", "전라북도", "전리남도", "경상도" };
	int sum = 0;

	for (int i = 0; i < 11; i++)
	{
		sum += areaCode[i];

		if (areaNum <= sum)
		{
			cout << areaName[i] << endl;
			break;
		}
	}
}

int main()
{
	char input[14];

	cout << "주만번호 13자리 입력: ";
	cin >> input;

	chcekInput7(input);

	int areaNum = ((input[7] - '0') * 10) + (input[8] - '0');

	printArea(areaNum);

	int value = 2;
	int total = 0;

	for (int i = 0; i < 8; i++)
	{
		total += (input[i] - '0') * value;
		value++;
	}

	value = 2;

	for (int i = 8; i < 12; i++)
	{
		total += (input[i] - '0') * value;
		value++;
	}

	if ((input[12] - '0') == ((11 - (total % 11)) % 10))
	{
		cout << "유효합니다." << endl;
	}
	else
	{
		cout << "유효하지 않습니다." << endl;
	}

	return 0;
}
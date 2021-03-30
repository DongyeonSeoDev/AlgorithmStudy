#include <iostream> //기둥 개수 설정, 이동한 횟수 보여주기
using namespace std;

int number = 0;

void calculation(int num, char from, char by, char to) //from에 꽂혀 있는 num개의 원반을 by를 거쳐서 to로 이동
{
    if (num == 1)
    {
        cout << "원반1을" << from << "에서" << to << "로 이동" << endl;
        number++;
        return;
    }

    calculation(num - 1, from, to, by);
    cout << "원반" << num << "을" << from << "에서" << to << "로 이동" << endl;
    number++;
    calculation(num - 1, by, from, to);

}

int main()
{
    cout << "하노이 탑" << endl;
    int input;
    cout << "원반의 개수를 입력해 주세요 (1~10개): ";
    cin >> input;

    if (input < 1 || input > 10)
    {
        cout << "잘못된 숫자 입니다" << endl;
        return 0;
    }

    cout << "기둥 A의 원반 " << input << "개를 기둥 B를 경유하여 기둥 C로 이동" << endl << endl;

    calculation(input, 'A', 'B', 'C');
    cout << endl;
    cout << number << "번 움직였습니다." << endl;
}

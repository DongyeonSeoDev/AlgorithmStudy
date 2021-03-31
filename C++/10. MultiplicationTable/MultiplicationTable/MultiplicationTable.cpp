#include <iostream>
using namespace std;

void Multiplication(int num = 1, int num2 = 1)
{
    cout << num << " X " << num2 << " = " << num * num2 << endl;

    if (num == 9 && num2 == 9)
        return;

    if (num2 == 9)
    {
        num++;
        num2 = 1;
        cout << endl;
    }
    else
    {
        num2++;
    }

    return(Multiplication(num, num2));
}

int main()
{
    Multiplication();
}
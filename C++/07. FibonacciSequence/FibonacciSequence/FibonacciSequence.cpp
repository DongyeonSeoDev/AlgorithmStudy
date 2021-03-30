#include <iostream>
using namespace std;

int calculation(int n)
{
    if (n == 1 || n == 2)
        return 1;

    return(calculation(n - 1) + calculation(n - 2));
}

int main()
{
    int i;
    cout << "피보나치 수열 구현하기" << endl;
    for (i = 1; i <= 30; i++)
        cout << i << ": " << calculation(i) << endl;
}
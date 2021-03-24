#include <iostream>
using namespace std;

int main()
{
    const int num = 10;

    int a[num][num] = { 0, };
    int i = 0;
    int j = 0;

    for (i = 0; i < num; i++)
    {
        a[i][0] = 1;
    }

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            if (i > 0 && j > 0)
            {
                a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
            }

            if (a[i][j] > 0)
            {
                cout << a[i][j] << " ";
            }
        }

        cout << endl;
    }
}
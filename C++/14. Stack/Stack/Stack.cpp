#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> s1;
    stack<char> s2;

    s1.push('d');
    s1.push('a');
    s1.push('t');
    s1.push('a');

    s2.push('s');
    s2.push('t');
    s2.push('a');
    s2.push('c');
    s2.push('k');

    cout << "s1의 top포인터가 가리키고 있는 값: " << s1.top() << endl;
    cout << "s2의 top포인터가 가리키고 있는 값: " << s2.top() << endl;
    cout << endl;

    s1.pop();
    s2.pop();

    cout << "pop을 한 후에 s1의 top포인터가 가리키고 있는 값: " << s1.top() << endl;
    cout << "pop을 한 후에 s2의 top포인터가 가리키고 있는 값: " << s2.top() << endl;

    cout << endl;

    cout << "s1에 남아있는 값들: ";
    while (!s1.empty())
    {
        cout << s1.top();
        s1.pop();
    }

    cout << endl;

    cout << "s2에 남아있는 값들: ";
    while (!s2.empty())
    {
        cout << s2.top();
        s2.pop();
    }

    cout << endl;
}

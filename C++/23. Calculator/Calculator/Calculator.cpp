#include <iostream>
#include <stack>
using namespace std;

bool numCheck(char ch) //숫자인지 아닌지 확인
{
    return ch >= '0' && ch <= '9';
}

bool errorCheck(string input) //오류가 있는지 없는지 확인하는 함수
{
    bool isCheckNum = false;
    bool isCheckCalculation = false;
    bool isUseParenthesis = false;

    for (int i = 0; i < (int)input.length() - 1; i++)
    {
        if (!numCheck(input[i])) //input이 숫자가 아니면 실행
        {
            if (input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] != '(' && input[i] != ')') //사칙연산자나 괄호가 아니면 리턴
            {
                cout << "0~9 + - * / = () 만 사용이 가능합니다." << endl;
                return false;
            }

            if (input[i] == '(' && isCheckNum) // ( 이전에 숫자가 들어간다면 리턴
            {
                cout << "숫자와 괄호 사이에 사칙연산이 있어야 합니다." << endl;
                return false;
            }
            else if (input[i] == '(') // ( 이후에는 숫자여야함
            {
                if (input[i + 1] == '(' || input[i + 1] == ')') // ( 이후에 ( 나 )가 들어오면 리턴
                {
                    cout << "괄호 바로 뒤에 괄호가 오면 안됩니다." << endl;
                    return false;
                }

                if (isUseParenthesis) // ( 안에 ( 를 사용하면 리턴
                {
                    cout << "괄호 안에 괄호를 사용할 수 없습니다." << endl;
                    return false;
                }

                isCheckNum = false;
                isUseParenthesis = true;
            }
            else if (input[i] == ')' && !isCheckNum) // ) 이전에 연산자가 들어간다면 리턴
            {
                cout << "닫는괄호 앞에는 숫자가 들어가야 합니다." << endl;
                return false;
            }
            else if (input[i] == ')') // ) 이후에는 사칙연산 이어야함
            {
                if (numCheck(input[i + 1])) // ) 다음것이 숫자라면 리턴
                {
                    cout << "괄호 뒤에는 사칙연산이 들어가야 합니다." << endl;
                    return false;
                }

                if (input[i + 1] == '(' || input[i + 1] == ')') // ( 이후에 ( 나 )가 들어오면 리턴
                {
                    cout << "여는괄호 바로 뒤에 닫는괄호가 오면 안됩니다." << endl;
                    return false;
                }

                if (!isUseParenthesis) // ( 없이 )를 사용하면 리턴 // 오류 발생 //괄호를 닫는괄호와 여는 괄호 구분하기
                {
                    cout << "여는괄호와 닫는괄호는 같이 사용해야 합니다." << endl;
                    return false;
                }

                isUseParenthesis = false;
            }
            else if (!isCheckNum) //사칙연산이 중복으로 나오거나 처음에 사칙연산이 나오면 리턴
            {
                cout << "사칙연산뒤에 사칙연산이 나오거나 처음에 사칙연산이 나오면 안됩니다." << endl;
                return false;
            }
            else
            {
                isCheckNum = false;
                isCheckCalculation = true;
            }

        }
        else
        {
            isCheckNum = true;
        }
    }

    if (input[(int)input.length() - 1] != '=') //마지막이 '=' 이 아니거나 사칙연산뒤에 =이 오거나 =만 있는 식이거나 사칙연산이 없다면 리턴
    {
        cout << "마지막에는 =을 사용해야 합니다." << endl;
        return false;
    }
    else if (!isCheckNum)
    {
        cout << "사칙연산뒤에 =이 오면 안됩니다." << endl;
        return false;
    }
    else if (!isCheckCalculation)
    {
        cout << "사칙연산을 1개 이상 사용해야 합니다." << endl;
        return false;
    }

    return true;
}

void calculation(stack<char>* calculationStack, stack<float>* numStack, int multiplicationCount, bool isParenthesis)
{
    bool isCalculationCheck = false;

    while (!isCalculationCheck)
    {
        if (multiplicationCount <= 0)
        {
            while (true)
            {
                char temp;

                if (isParenthesis)
                {
                    temp = calculationStack->top();
                    calculationStack->pop();

                    if (temp == '(')
                    {
                        isCalculationCheck = true;
                        break;
                    }
                }
                else
                {
                    if (numStack->size() <= 1)
                    {
                        isCalculationCheck = true;
                        break;
                    }

                    temp = calculationStack->top();
                    calculationStack->pop();
                }

                float temp1 = numStack->top();
                numStack->pop();
                float temp2 = numStack->top();
                numStack->pop();
                float result = 0;

                result = temp2 + temp1;
                numStack->push(result);
            }
        }
        else
        {
            stack<float> sFloatTemp;
            stack<char> sCharTemp;
            bool isCalculation = false;

            while (!isCalculation)
            {
                char temp = calculationStack->top();
                calculationStack->pop();

                if (temp == '*')
                {
                    float temp1 = numStack->top();
                    numStack->pop();
                    float temp2 = numStack->top();
                    numStack->pop();
                    float result;
                    
                    result = temp2 * temp1;
                    numStack->push(result);

                    while (!sFloatTemp.empty())
                    {
                        numStack->push(sFloatTemp.top());
                        sFloatTemp.pop();
                    }

                    while (!sCharTemp.empty())
                    {
                        calculationStack->push(sCharTemp.top());
                        sCharTemp.pop();
                    }

                    multiplicationCount--;
                    isCalculation = true;
                }
                else
                {
                    sFloatTemp.push(numStack->top());
                    numStack->pop();
                    sCharTemp.push(temp);
                }
            }
        }
    }
}

float changeMinus(float temp)
{
    return -temp;
}

float changeDivision(float temp)
{
    return 1 / temp;
}

float addNum(float input, bool isMinus)
{
    if (isMinus) return changeMinus(input);

    return input;
}

float addNum(float input, float temp)
{
    if (temp >= 0) return temp * 10 + input;

    return temp * 10 - input;
}

int main()
{
    string input;
    stack<float> numStack;
    stack<char> calculationStack;

    int numCount = 0;
    int multiplicationCount = 0;
    int outMultiplicationCount = 0;

    bool isUseParenthesis = false;
    bool isNextMinus = false;
    bool isNextDivision = false;

    cin >> input;

    if (!errorCheck(input)) return 0;

    for (int i = 0; i < (int)input.length() - 1; i++)
    {
        if (numCheck(input[i]))
        {
            numCount++;
            float inputNum = (float)(input[i] - '0');

            if (isNextMinus)
            {
                isNextMinus = false;
                numStack.push(addNum(inputNum, true));
            }
            else if (numCount < 2)
            {
                numStack.push(addNum(inputNum, false));
            }
            else
            {
                float temp = numStack.top();
                numStack.pop();
                numStack.push(addNum(inputNum, temp));
            }
        }
        else
        {
            numCount = 0;

            if (isNextDivision)
            {
                isNextDivision = false;
                float temp = numStack.top();
                numStack.pop();
                numStack.push(changeDivision(temp));
            }

            if ((input[i] == '*' || input[i] == '/') && isUseParenthesis)
            {
                multiplicationCount++;
            }
            else if ((input[i] == '*' || input[i] == '/') && !isUseParenthesis)
            {
                outMultiplicationCount++;
            }

            if (input[i] == '-')
            {
                isNextMinus = true;
                calculationStack.push('+');
                continue;
            }

            if (input[i] == '/')
            {
                isNextDivision = true;
                calculationStack.push('*');
                continue;
            }

            calculationStack.push(input[i]);

            if (input[i] == '(')
            {
                isUseParenthesis = true;
            }

            if (input[i] == ')')
            {
                calculationStack.pop();
                calculation(&calculationStack, &numStack, multiplicationCount, true);

                isUseParenthesis = false;
                multiplicationCount = 0;
            }
        }
    }

    if (isNextDivision)
    {
        isNextDivision = false;
        float temp = numStack.top();
        numStack.pop();
        numStack.push(changeDivision(temp));
    }

    calculation(&calculationStack, &numStack, outMultiplicationCount, false);

    cout << numStack.top() << endl;
    return 0;
}
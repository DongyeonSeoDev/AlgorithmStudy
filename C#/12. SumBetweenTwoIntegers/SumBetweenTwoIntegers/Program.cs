/*
[문제 12] 두 정수 사이의 합
두 정수 a, b가 주어졌을 때 a와 b 사이에 속한 모든 정수의 합을 return 하는 함수를 완성하세요.
예를 들어 a = 3, b = 5인 경우, 3 + 4 + 5 = 12이므로 12를 return 합니다.
*/

using System;

namespace SumBetweenTwoIntegers
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Soulution(3, 5));
        }

        static public int Soulution(int num1, int num2)
        {
            int total = 0;

            for (int i = Math.Min(num1, num2); i <= Math.Max(num1, num2); i++)
            {
                total += i;
            }

            return total;
        }
    }
}

/*
[문제 16] 소수 찾기
1부터 입력받은 숫자 n 사이에 있는 소수의 개수를 반환하는 함수를 완성하세요.
소수는 1과 자기 자신으로만 나누어지는 수를 의미합니다. (1은 소수가 아닙니다.)
*/

using System;

namespace FindPrimeNumber
{
    class Program
    {
        static void Main(string[] args)
        {
            
            Console.WriteLine(Solution());
        }

        static int Solution()
        {
            int count = 0;

            if (!int.TryParse(Console.ReadLine(), out int num) || num <= 1)
            {
                Console.WriteLine("잘못된 입력 입니다.");
                return 0;
            }

            for (int i = 2; i < num; i++)
            {
                for (int j = 2; j < i / 2 + 1; j++)
                {
                    if (i % j == 0)
                    {
                        count++;
                        break;
                    }
                }
            }

            return num - count - 2;
        }
    }
}

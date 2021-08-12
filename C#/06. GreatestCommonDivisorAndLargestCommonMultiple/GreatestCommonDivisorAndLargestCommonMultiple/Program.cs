/*
[문제 06] 최대공약수와 최소공배수
두 수를 입력받아 두 수의 최대공약수와 최소공배수를 반환하는 함수를 완성해보세요. 
배열의 맨 앞에 최대공약수, 그다음 최소공배수를 넣어 반환하면 됩니다. 
예를 들어 두 수 3, 12의 최대공약수는 3, 최소공배수는 12이므로 solution(3, 12)는 3, 12를 반환해야 합니다.
(두 수는 1 이상 1000000이하의 자연수입니다.)
*/

using System;

namespace GreatestCommonDivisorAndLargestCommonMultiple
{
    class Program
    {
        static void Main(string[] args)
        {
            Array.ForEach(Solution(2, 10), x => Console.WriteLine(x + " "));
            Console.WriteLine();

            Array.ForEach(Solution2(2, 10), x => Console.WriteLine(x + " "));
            Console.WriteLine();

            Array.ForEach(Solution(2, 10), x => Console.WriteLine(x + " "));
            Console.WriteLine();
        }

        static int[] Solution(int num1, int num2)
        {
            int[] num = new int[2] { 0, 0 };

            if (num1 < 1 || num1 > 1000000 || num2 < 1 || num2 > 1000000)
            {
                Console.WriteLine("잘못된 입력 입니다.");
                return num;
            }

            //최대공약수
            for (int i = Math.Min(num1, num2); i > 0; i--)
            {
                if (num1 % i == 0 && num2 % i == 0)
                {
                    num[0] = i;
                    break;
                }
            }

            //최대공배수 = n x m / 최소공약수
            num[1] = num1 * num2 / num[0];

            return num;
        }

        static int[] Solution2(int num1, int num2)
        {
            int[] num = new int[2] { 0, 0 };

            if (num1 < 1 || num1 > 1000000 || num2 < 1 || num2 > 1000000)
            {
                Console.WriteLine("잘못된 입력 입니다.");
                return num;
            }

            //최소공배수
            for (int i = 1; i < num1 + 1; i++)
            {
                for (int j = 1; j < num2 + 1; j++)
                {
                    if (num2 * i == num1 * j)
                    {
                        num[1] = num2 * i;
                        i = num1 + 1;
                        break;
                    }
                }
            }

            //최대공약수 = n x m / 최소공배수
            num[0] = num1 * num2 / num[1];

            return num;
        }

        //유클리드 호제법
        static int[] EuclideanAlgorithm(int num1, int num2)
        {
            int min = Math.Min(num1, num2);
            int max = Math.Max(num1, num2);
            int temp = 0;

            while (min != 0)
            {
                temp = max % min;
                max = min;
                min = temp;
            }

            return new int[] { max, num1 * num2 / max };
        }
    }
}

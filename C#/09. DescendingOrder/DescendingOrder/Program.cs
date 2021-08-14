/*
[문제 09] 정수 내림차순으로 배치하기
함수 solution은 정수 n을 매개변수로 입력받습니다. n의 각 자릿수를 큰 것부터 작은 순으로 정렬한 새로운 정수를 return 해 주세요. 
예를 들어, n이 118372면 873211을 return 하면 됩니다.
(n은 1 이상 8000000000 이하인 자연수입니다.)
*/

using System;
using System.Linq;

namespace DescendingOrder
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Solution(135792468));
            Console.WriteLine(Solution2(135792468));
        }

        static long Solution(long n)
        {
            if (n < 1 || n > 8000000000)
            {
                Console.WriteLine("잘못된 n 입니다.");
                return 0;
            }

            char[] chars = n.ToString().ToCharArray();

            Array.Sort(chars);
            Array.Reverse(chars);

            return long.Parse(new string(chars));
        }

        static long Solution2(long n)
        {
            if (n < 1 || n > 8000000000)
            {
                Console.WriteLine("잘못된 n 입니다.");
                return 0;
            }

            return long.Parse(new string(n.ToString().OrderByDescending(x => x).ToArray()));
        }
    }
}

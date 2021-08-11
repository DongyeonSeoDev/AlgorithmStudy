/*
[문제 04] 평균 구하기
정수를 담고 있는 배열 arr의 평균값을 return하는 함수를 완성해보세요.
(arr은 길이 1 이상, 100이하인 배열입니다. arr의 원소는 –10,000 이상 10,000 이하인 정수입니다.)
*/

using System;
using System.Linq;

namespace Average
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Average(new int[] { 10, 20, 30, 40, 50 }));
            Console.WriteLine(Average2(new int[] { 10, 20, 30, 40, 50 }));
        }

        static double Average(int[] arr)
        {
            if (arr.Length < 1 || arr.Length > 100 || !arr.All(x => x >= -10000 && x <= 10000))
            {
                Console.WriteLine("잘못된 arr 입니다.");
                return 0;
            }

            return (double)arr.Sum() / arr.Length;
        }

        static double Average2(int[] arr)
        {
            if (arr.Length < 1 || arr.Length > 100 || !arr.All(x => x >= -10000 && x <= 10000))
            {
                Console.WriteLine("잘못된 arr 입니다.");
                return 0;
            }

            return arr.Average();
        }
    }
}

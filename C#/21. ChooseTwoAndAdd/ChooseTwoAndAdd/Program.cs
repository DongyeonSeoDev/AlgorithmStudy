/*
[문제 21] 두 개 뽑아서 더하기
정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아
더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 함수를 완성해주세요.
(numbers의 길이는 2 이상 100이하이며, 모든 수는 0 이상 100 이하입니다.)
*/

using System;
using System.Collections.Generic;
using System.Linq;

namespace ChooseTwoAndAdd
{
    class Program
    {
        static void Main(string[] args)
        {
            Array.ForEach(Solution(new int[] { 1, 2, 3, 4, 5 }), x => Console.Write(x + " "));
            Console.WriteLine();
        }

        static int[] Solution(int[] numbers)
        {
            if (numbers.Length < 2 || numbers.Length > 100 || !numbers.All(x => x >= 0 && x <= 100))
            {
                return null;
            }

            List<int> numberList = new List<int>();

            for (int i = 0; i < numbers.Length; i++)
            {
                for (int j = i + 1; j < numbers.Length; j++)
                {
                    numberList.Add(numbers[i] + numbers[j]);
                }
            }

            return numberList.Distinct().OrderBy(x => x).ToArray();
        }
    }
}

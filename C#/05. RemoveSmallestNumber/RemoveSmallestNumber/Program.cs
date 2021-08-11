/*
[문제 05] 제일 작은 수 제거하기
정수를 저장한 배열, arr에서 가장 작은 수를 제거한 배열을 리턴하는 함수를 완성해주세요.
단, return 하려는 배열이 빈 배열인 경우엔 배열에 –1을 채워 return 하세요. 예를 들어 arr이 [4,3,2,1]인 경우는[4, 3, 2]를 return 하고, [10]이면 [-1] 를 return 합니다.
(arr는 길이 1 이상인 배열입니다.인덱스 i, j에 대해 i ≠ j이면 arr[i] ≠ arr[j] 입니다.)
(입력된 수, num은 1 이상 8000000 미만인 정수입니다.)
*/

using System;
using System.Collections.Generic;
using System.Linq;

namespace RemoveSmallestNumber
{
    class Program
    {
        static void Main(string[] args)
        {
            Array.ForEach(RemoveSmallestNumber(new int[] { 1, 2, 3, 4, 5 }), x => Console.Write(x + " "));
            Console.WriteLine();

            Array.ForEach(RemoveSmallestNumber2(new int[] { 1, 2, 3, 4, 5 }), x => Console.Write(x + " "));
            Console.WriteLine();
        }

        static int[] RemoveSmallestNumber(int[] arr)
        {
            if (arr.Length < 1 || arr.Length != arr.Distinct().Count() || !arr.All(x => x >= 1 && x <= 8000000))
            {
                Console.WriteLine("잘못된 arr 입니다.");
                return null;
            }

            if (arr.Length == 1)
            {
                return new int[1] { -1 };
            }

            List<int> numbers = arr.ToList();

            numbers.Remove(arr.Min());

            return numbers.ToArray();
        }

        static int[] RemoveSmallestNumber2(int[] arr)
        {
            if (arr.Length < 1 || arr.Length != arr.Distinct().Count() || !arr.All(x => x >= 1 && x <= 8000000))
            {
                Console.WriteLine("잘못된 arr 입니다.");
                return null;
            }

            return arr.Length == 1 ? new int[1] { -1 } : arr.Where(x => x != arr.Min()).ToArray();
        }
    }
}

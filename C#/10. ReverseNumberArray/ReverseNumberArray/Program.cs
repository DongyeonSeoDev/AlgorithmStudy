/*
[문제 10] 자연수 뒤집어 배열로 만들기
자연수 n을 뒤집어 각 자리 숫자를 원소로 가지는 배열 형태로 return 해 주세요. 
예를 들어 n이 12345이면 [5,4,3,2,1]을 리턴합니다.
*/

using System;
using System.Linq;

namespace ReverseNumberArray
{
    class Program
    {
        static void Main(string[] args)
        {
            Array.ForEach(Solution(12345), x => Console.Write(x + " "));
        }

        static int[] Solution(int n)
        {
            return n.ToString()
                .ToCharArray()
                .Reverse()
                .Select(x => int.Parse(x.ToString()))
                .ToArray();
        }
    }
}

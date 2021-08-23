/*
[문제 19] 문자열 내림차순으로 배치하기
문자열 s에 나타나는 문자를 큰 것부터 작은 순으로 정렬해 새로운 문자열을 return하는 함수를 완성해주세요.
s는 영문 대소문자로만 구성되어 있으며, 대문자는 소문자보다 작은 것으로 간주합니다.
*/

using System;
using System.Linq;

namespace StringDescendingOrder
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Solution("ABCDabcd"));
        }

        static string Solution(string s)
        {
            return new string(s.ToCharArray().OrderByDescending(x => x).ToArray());
        }
    }
}

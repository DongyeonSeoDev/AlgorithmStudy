/*
[문제 17] 문자열 다루기 기본
문자열 s의 길이가 4 혹은 6이고, 숫자로만 구성돼있는지 확인해주는 함수를 완성해주세요.
예를 들어, s가 “a234”이면 False를 return 하고 “1234”라면 True를 return 하면 됩니다.
*/

using System;
using System.Linq;

namespace String
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Solution("a234"));
            Console.WriteLine(Solution("1234"));
        }

        static bool Solution(string s)
        {
            return (s.Length == 4 || s.Length == 6) && s.All(c => '0' <= c && c <= '9');
        }
    }
}

/*
[문제 11] 자릿수 더하기
자연수 N이 주어지면, N의 각 자릿수의 합을 구해서 return 하는 soulution 함수를 만들어주세요. 
예를 들어 N이 123이면 1 + 2 + 3 = 6을 return 하면 됩니다.
*/

using System;
using System.Linq;

namespace AddDigits
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Soulution(12345));
        }

        static public int Soulution(int n)
        {
            return n.ToString().ToCharArray().Sum(x => int.Parse(x.ToString()));
        }
    }
}

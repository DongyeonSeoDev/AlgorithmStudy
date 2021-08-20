/*
[문제 15] 수박수박수박수박수박수?
길이가 n이고, “수박수박수박수…”와 같은 패턴을 유지하는 문자열을 return 하는 함수를 완성하세요.
예를 들어 n이 4이면 “수박수박”을 return하고 3이라면 “수박수”를 return 하면 됩니다.
*/
using System;

namespace RepeatString
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Solution(4));
        }

        static string Solution(int num)
        {
            string s = "";

            for (int i = 0; i < num; i++)
            {
                s += i % 2 == 0 ? "수" : "박";
            }

            return s;
        }
    }
}

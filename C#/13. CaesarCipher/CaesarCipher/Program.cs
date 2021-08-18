/*
[문제 13] 시저 암호
어떤 문장의 각 알파벳을 일정한 거리만큼 밀어서 다른 알파벳으로 바꾸는 암호화 방식을 시저 암호라고 합니다. 
예를 들어 “AB”는 1만큼 밀면 “BC”가 되고, 3만큼 밀면 “DE”가 됩니다. “z”는 1만큼 밀면 “a”가 됩니다. 
문자열 s와 거리 n을 입력받아 s를 n만큼 민 암호문을 만드는 함수를 완성해보세요.
(공백은 아무리 밀어도 공백입니다. s는 알파벳 소문자, 대문자, 공백으로만 이루어져 있습니다. 
s의 길이는 8000 이하입니다. n은 1 이상, 25 이하인 자연수입니다.)
*/

using System;
using System.Linq;

namespace CaesarCipher
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Soulution("ABCDabcd", 2));
        }

        static string Soulution(string s, int n)
        {
            if (s.Length > 8000 
                || (n < 1 && n > 25) 
                || !s.All(x => ('A' <= x && x <= 'Z') || ('a' <= x && x <= 'z') || x == ' '))
            {
                return null;
            }

            return new string(s.ToCharArray().Select(x =>
            {
                if ('a' <= x && x <= 'z')
                {
                    return x + n <= 'z' ? (char)(x + n) : (char)((x + n) % 'z' + 'a' - 1);
                }
                else if ('A' <= x && x <= 'Z')
                {
                    return x + n <= 'Z' ? (char)(x + n) : (char)((x + n) % 'Z' + 'A' - 1);
                }

                return x;
            }).ToArray());
        }
    }
}
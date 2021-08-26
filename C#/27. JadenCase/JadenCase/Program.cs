/*
[문제 27] JadenCase 문자열 만들기
JadenCase란 모든 단어의 첫 문자가 대문자이고, 그 외의 알파벳은 소문자인 문자열입니다.
문자열 s가 주어졌을 때, s를 JadenCase로 바꾼 문자열을 return 하는 함수를 완성해주세요.
(s는 길이 1 이상인 문자열입니다. s는 알파벳과 공백문자로 이루어져 있습니다.
첫 문자가 영문이 아닐 때는 이어지는 영문은 소문자로 씁니다.)
*/

using System;
using System.Linq;

namespace JadenCase
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(JadenCase("abc ABC"));
        }

        static string JadenCase(string s)
        {
            return string.Join(" ",
                s.Split(' ')
                .Select(x => new string(x.Select((y, z) => z == 0 ? char.ToUpper(y) : char.ToLower(y)).ToArray()))
                .ToArray());
        }
    }
}

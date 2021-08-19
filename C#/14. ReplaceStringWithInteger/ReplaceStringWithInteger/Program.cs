/*
[문제 14] 문자열을 정수로 바꾸기
문자열 s를 숫자로 변환한 결과를 반환하는 함수를 완성하세요.
(s의 길이는 1 이상 5 이하입니다. s의 맨 앞에는 부호(+,-)가 올 수 있습니다. s는 부호와 숫자로만 이루어져 있습니다. s는 “0”으로 시작하지 않습니다.)
*/

using System;
using System.Linq;

namespace ReplaceStringWithInteger
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Soulution("-1234"));
        }

        static int Soulution(string num)
        {
            if (num.Length < 1 
                || num.Length > 5 
                || !(('1' <= num[0] && num[0] <= '9') || num[0] == '+' || num[0] == '-')
                || !num.Substring(1).All(x => '0' <= x && x <= '9'))
            {
                Console.WriteLine("잘못된 num 입니다.");
                return 0;
            }


            return int.Parse(num);
        }
    }
}

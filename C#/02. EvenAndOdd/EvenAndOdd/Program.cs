/*
[문제 02] 짝수와 홀수
정수 num이 짝수일 경우 “Even”을 반환하고, 홀수인 경우 “Odd”를 반환하는 함수를 완성해주세요.
(num은 int 범위의 정수입니다. 0은 짝수입니다.)
*/
using static System.Console;

namespace EvenAndOdd
{
    class Program
    {
        static void Main(string[] args)
        {
            if (!int.TryParse(ReadLine(), out int num))
            {
                return;
            }

            WriteLine(Soulution(num));
        }

        static string Soulution(int num)
        {
            return num % 2 == 0 ? "Even" : "Odd";
        }
    }
}

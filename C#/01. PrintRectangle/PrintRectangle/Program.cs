/*
[문제 01] 직사각형 별 찍기
이 문제에는 표준 입력으로 두 개의 정수 n과 m이 주어집니다. 별(*) 문자를 이용해 가로의 길이가 n, 세로의 길이가 m인 직사각형 형태를 출력해보세요.
(n과 m은 각각 1000 이하인 자연수입니다.)
*/

using static System.Console;

namespace PrintRectangle
{
    class Program
    {
        static void Main(string[] args)
        {
            if (!int.TryParse(ReadLine(), out int n) || n > 1000)
            {
                WriteLine("잘못된 입력 입니다.");
                return;
            }

            if (!int.TryParse(ReadLine(), out int m) || m > 1000)
            {
                WriteLine("잘못된 입력 입니다.");
                return;
            }

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Write("*");
                }

                WriteLine();
            }
        }
    }
}

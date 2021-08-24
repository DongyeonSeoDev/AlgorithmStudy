/*
[문제 24] 모의고사
수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.
1번 수포자: 1,2,3,4,5,1,2,3,4,5,…
2번 수포자: 2,1,2,3,2,4,2,5,2,1,2,3,2,4,2,5,…
3번 수포자: 3,3,1,1,2,2,4,4,5,5,3,3,1,1,2,2,4,4,5,5,…
1번 문제부터 마지막 문제까지의 정답이 순서대로 있는 배열 answers가 주어졌을 때,
가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하는 함수를 작성해주세요.
(제한조건) -시험은 최대 10,000 문제로 구성되어 있습니다.
- 문제의 정답은 1,2,3,4,5 중 하나입니다.
- 가장 높은 점수를 받은 사람이 여럿일 경우, return 하는 값을 오름차순 정렬해주세요.
*/

using System;
using System.Linq;

namespace MockTest
{
    class Program
    {
        static readonly int[][] choice = new int[][]
        {
            new int[] { 1, 2, 3, 4, 5 },
            new int[] { 2, 1, 2, 3, 2, 4, 2, 5 },
            new int[] { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }
        };

        static void Main(string[] args)
        {
            Array.ForEach(Solution(new int[] { 1, 2, 3, 4, 5 }), x => Console.Write(x + " "));
            Console.WriteLine();

            Array.ForEach(Solution(new int[] { 2, 1, 2, 3, 4, 5 }), x => Console.Write(x + " "));
            Console.WriteLine();

            Array.ForEach(Solution(new int[] { 3, 4, 1, 1, 2, 5 }), x => Console.Write(x + " "));
            Console.WriteLine();
        }

        static string[] Solution(int[] answers)
        {
            if (answers.Length > 10000 || !answers.All(x => x >= 1 && x <= 5))
            {
                return null;
            }

            int[] count = new int[choice.Length]
                .Select((x, y) => answers.Where((a, b) => a == choice[y][b % choice[y].Length]).Count())
                .ToArray();

            return count.Select((x, y) => x == count.Max() ? x = y : x = -1)
                .Where(x => x != -1)
                .Select(x => x + 1 + "번 수포자")
                .OrderBy(x => x[0])
                .ToArray();
        }
    }
}
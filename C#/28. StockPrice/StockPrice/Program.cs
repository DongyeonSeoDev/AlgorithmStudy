/*
[문제 28] 주식 가격
초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때,
가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.
(prices의 각 가격은 1 이상 10,000 이하인 자연수입니다. prices의 길이는 2 이상 100,000 이하입니다.)
*/

using System;
using System.Linq;

namespace StockPrice
{
    class Program
    {
        static void Main(string[] args)
        {
            Array.ForEach(Solution(new int[] { 1, 2, 3, 2, 3 }), x => Console.Write(x + " "));
            Console.WriteLine();
        }

        static int[] Solution(int[] prices)
        {
            if (!prices.All(x => x >= 1 && x <= 10000)
                || prices.Length < 2
                || prices.Length > 100000)
            {
                return null;
            }

            return new int[prices.Length].Select((x, y) =>
            {
                x = Array.FindIndex(prices, y, z => prices[y] > z) - y;

                return x < 0 ? prices.Length - y - 1 : x;

            }).ToArray();
        }
    }
}

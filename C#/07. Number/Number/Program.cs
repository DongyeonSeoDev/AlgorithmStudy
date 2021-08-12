/*
[문제 07] x만큼 간격이 있는 n개의 숫자
함수 solution은 정수 x와 자연수 n을 입력받아, x부터 시작해 x씩 증가하는 숫자를 n개 지니는 리스트를 return 해야 합니다. 
다음 제한조건을 보고, 조건을 만족하는 함수 solution을 완성해주세요.
(제한조건) – x는 - 10000000 이상, 10000000 이하인 정수입니다.
 - n은 1000 이하인 자연수입니다.
*/
using System;
using System.Collections.Generic;

namespace Number
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution(10, 10).ForEach(x => Console.Write(x + " "));
            Console.WriteLine();
        }

        static List<long> Solution(long x, int n)
        {
            if (x < -10000000 || x > 10000000 || n < 1 || n > 1000)
            {
                Console.WriteLine("잘못된 입력 입니다.");
                return null;
            }

            List<long> numberList = new List<long>();

            for (int i = 0; i < n; i++)
            {
                numberList.Add(x + (x * i));
            }

            return numberList;
        }
    }
}

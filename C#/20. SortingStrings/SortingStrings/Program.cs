/*
[문제 20] 문자열 내 마음대로 정렬하기
문자열로 구성된 리스트 strings와 정수 n이 주어졌을 때,
각 문자열의 인덱스 n번째 글자를 기준으로 오름차순 정렬하려 합니다.
예를 들어, strings가[“sun”, “bed”, “car”]이고 n이 1이면 각 단어의 인덱스 1의 문자 “u”. “e”, “a”로 strings를 정렬합니다. 
[“car”, “bed”, “sun”]
*/

using System;
using System.Collections.Generic;
using System.Linq;

namespace SortingStrings
{
    class Program
    {
        static void Main(string[] args)
        {
            List<List<string>> strings = new List<List<string>> 
            { 
                new List<string> { "sun", "bed", "car" }, 
                new List<string> { "ABC", "BCA", "CAB" } 
            };

            strings.ForEach(x => 
            { 
                for (int i = 0; i < 3; i++)
                {
                    Console.Write(i + "번째 인덱스 기준으로 오름차순 정렬: ");
                    Solution(x, i).ForEach(y => Console.Write(y + " "));
                    Console.WriteLine();
                }

                Console.WriteLine();
            });
        }

        static List<string> Solution(List<string> strings, int n)
        {
            return strings.OrderBy(x => x[n]).ToList();
        }
    }
}

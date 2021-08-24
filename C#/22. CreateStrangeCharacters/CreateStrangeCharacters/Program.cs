﻿/*
[문제 22] 이상한 문자 만들기
문자열 s는 한 개 이상의 단어로 구성되어 있습니다.
각 단어는 하나 이상의 공백 문자로 구분되어 있습니다.
각 단어의 짝수번째 알파벳은 대문자로, 홀수번째 알파벳은 소문자로 바꾼 문자열을 return 하는 함수, solution을 완성하세요.
(문자열 전체의 짝/홀수 인덱스가 아니라, 단어(공백을 기준)별로 짝/홀수 인덱스를 판단해야 합니다.
첫 번째 글자는 0번째 인덱스로 보아 짝수번째 알파벳으로 처리해야 합니다.)
*/

using System;
using System.Text;

namespace CreateStrangeCharacters
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Solution("ABC abc"));
        }

        static string Solution(string s)
        {
            StringBuilder sb = new StringBuilder(s.Length);

            Array.ForEach(s.Split(' '), x => 
            {
                for (int i = 0; i < x.Length; i++)
                {
                    sb.Append(i % 2 == 0 ? x[i].ToString().ToUpper() : x[i].ToString().ToLower());
                }

                sb.Append(' ');
            });

            return sb.ToString();
        }
    }
}
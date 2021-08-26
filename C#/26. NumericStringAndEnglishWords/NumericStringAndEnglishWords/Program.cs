/*
[문제 26] 2021 카카오 채용연계형 인턴쉽 기출문제

네오와 프로도가 숫자놀이를 하고 있습니다. 
네오가 프로도에게 숫자를 건넬 때 일부 자릿수를 영단어로 바꾼 카드를 건네주면 프로도는 원래 숫자를 찾는 게임입니다.

다음은 숫자의 일부 자릿수를 영단어로 바꾸는 예시입니다.
- 1478 -> one4seveneight
- 234567 -> 23four5six7
- 10203 -> 1zerotwozero3

이렇게 숫자의 일부 자릿수가 영단어로 바뀌어졌거나, 혹은 바뀌지 않고 그대로인 문자열 s가 매개변수로 주어집니다.
s가 의미하는 원래 숫자를 return하도록 solution 함수를 완성해주세요. 
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NumericStringAndEnglishWords
{
    class Program
    {
        static string[] number = new string[] 
        { 
            "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" 
        };

        static void Main(string[] args)
        {
            Console.WriteLine(Soulution("one4seveneight"));
            Console.WriteLine(Soulution("23four5six7"));
            Console.WriteLine(Soulution("1zerotwozero3"));
        }

        static int Soulution(string s)
        {
            StringBuilder sb = new StringBuilder(s.Length);

            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] < '0' || s[i] > '9')
                {
                    for (int j = 0; j < number.Length; j++)
                    {
                        if (s[i] == number[j][0] && s[i + 1] == number[j][1])
                        {
                            sb.Append(j.ToString());
                            i += number[j].Length - 1;

                            break;
                        }
                    }
                }
                else
                {
                    sb.Append(s[i].ToString());
                }
            }

            return int.Parse(sb.ToString());
        }
    }
}

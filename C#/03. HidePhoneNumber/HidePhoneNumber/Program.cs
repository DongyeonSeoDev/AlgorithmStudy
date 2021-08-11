/*
[문제 03] 핸드폰 번호 가리기
개인정보 보호를 위해 고지서를 보낼 때 고객들의 전화번호의 일부를 가립니다.
전화번호가 문자열 phone_number로 주어졌을 때, 전화번호의 뒷 4자리를 제외한 나머지 숫자를 전부 *으로 가린 문자열을 return 하는 함수를 완성해주세요.
(s는 길이 4 이상, 20이하인 문자열입니다.)
*/

using System;
using System.Text;

namespace HidePhoneNumber
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(HidePhoneNumber("010-1234-5678"));
        }

        static string HidePhoneNumber(string phone_number)
        {
            if (phone_number.Length < 4 || phone_number.Length > 20)
            {
                Console.WriteLine("잘못된 phone_number 입니다.");
                return null;
            }

            StringBuilder sb = new StringBuilder(phone_number.Length);

            for (int i = 0; i < phone_number.Length - 4; i++)
            {
                sb.Append(char.IsDigit(phone_number[i]) ? '*' : phone_number[i]);
            }

            for (int i = 4; i > 0; i--)
            {
                sb.Append(phone_number[phone_number.Length - i]);
            }

            return sb.ToString();
        }
    }
}

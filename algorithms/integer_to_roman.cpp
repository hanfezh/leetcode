/*
 * =====================================================================================
 *
 *       Filename:  integer_to_roman.cpp
 *
 *    Description:  Given an integer, convert it to a roman numeral. Input is guaranteed 
 *                  to be within the range from 1 to 3999.
 *
 *        Version:  1.0
 *        Created:  06/28/18 11:02:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <math.h>
#include <stdio.h>
#include <string>

class Solution
{
public:
    std::string intToRoman(int num)
    {
        if (num < 1 || num > 3999)
        {
            return "";
        }

        std::string roman;
        int idx = 0;
        while (num > 0)
        {
            int digit = num % 10;
            digit *= pow(10, idx);
            if (digit == 0)
            {
                ; // Ignore
            }
            else if (digit < 10)
            {
                if (digit < 4)
                {
                    while (digit-- > 0)
                    {
                        roman += "I";
                    }
                }
                else if (digit == 4)
                {
                    roman = "IV";
                }
                else if (digit < 9)
                {
                    roman = "V";
                    while (digit-- > 5)
                    {
                        roman += "I";
                    }
                }
                else
                {
                    // digit == 9
                    roman = "IX";
                }
            }
            else if (digit < 100)
            {
                if (digit < 40)
                {
                    while (digit > 0)
                    {
                        roman = "X" + roman;
                        digit -= 10;
                    }
                }
                else if (digit == 40)
                {
                    roman = "XL" + roman;
                }
                else if (digit < 90)
                {
                    std::string tmp = "L";
                    while (digit > 50)
                    {
                        tmp += "X";
                        digit -= 10;
                    }
                    roman = tmp + roman;
                }
                else
                {
                    // digit == 90
                    roman = "XC" + roman;
                }
            }
            else if (digit < 1000)
            {
                if (digit < 400)
                {
                    while (digit > 0)
                    {
                        roman = "C" + roman;
                        digit -= 100;
                    }
                }
                else if (digit == 400)
                {
                    roman = "CD" + roman;
                }
                else if (digit < 900)
                {
                    std::string tmp = "D";
                    while (digit > 500)
                    {
                        tmp += "C";
                        digit -= 100;
                    }
                    roman = tmp + roman;
                }
                else
                {
                    // digit == 900
                    roman = "CM" + roman;
                }
            }
            else 
            {
                // 1000 ~ 3000
                while (digit > 0)
                {
                    roman = "M" + roman;
                    digit -= 1000;
                }
            }

            idx += 1;
            num /= 10;
        }

        return roman;
    }
};

int main(int argc, char* argv[])
{
    int num = 2398;
    std::string roman = Solution().intToRoman(num);
    printf("%d -> %s\n", num, roman.c_str());

    return 0;
}

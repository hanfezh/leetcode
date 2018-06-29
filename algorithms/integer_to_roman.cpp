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
#include <stdio.h>
#include <string>
#include <vector>

class Solution
{
public:
    std::string intToRoman(int num)
    {
        if (num < 1 || num > 3999)
        {
            return "";
        }

        using sym_pair = std::pair<int, std::string>;
        std::vector<sym_pair> symbols = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"},
        };

        std::string roman;
        for (auto iter = symbols.rbegin(); iter != symbols.rend(); iter++)
        {
            while (num >= iter->first)
            {
                roman += iter->second;
                num -= iter->first;
            }
            if (num < 1)
            {
                break;
            }
        }

        return roman;
    }
};

int main(int argc, char* argv[])
{
    int num = 2398;
    if (argc > 1)
    {
        num = std::atoi(argv[1]);
    }
    std::string roman = Solution().intToRoman(num);
    printf("%d -> %s\n", num, roman.c_str());

    return 0;
}

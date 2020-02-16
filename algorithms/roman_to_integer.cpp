/*
 * =====================================================================================
 *
 *       Filename:  roman_to_integer.cpp
 *
 *    Description:  Given a roman numeral, convert it to an integer. Input is guaranteed 
 *                  to be within the range from 1 to 3999.
 *
 *        Version:  1.0
 *        Created:  06/29/18 07:32:10
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
    int romanToInt(const std::string& roman)
    {
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

        int num = 0;
        size_t idx = 0;
        for (auto iter = symbols.rbegin(); iter != symbols.rend(); iter++)
        {
            while (iter->second == roman.substr(idx, iter->second.length()))
            {
                num += iter->first;
                idx += iter->second.length();
            }
            if (idx >= roman.length())
            {
                break;
            }
        }

        return num;
    }
};

int main(int argc, char* argv[])
{
    std::string roman = "LVIII";
    if (argc > 1)
    {
        roman = argv[1];
    }
    int num = Solution().romanToInt(roman);
    printf("%s -> %d\n", roman.c_str(), num);

    return 0;
}

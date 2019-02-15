/*
 * =====================================================================================
 *
 *       Filename:  letter_combinations.cpp
 *
 *    Description:  Letter Combinations of a Phone Number. 
 *                  Given a string containing digits from 2-9 inclusive, return all 
 *                  possible letter combinations that the number could represent.
 *
 *        Version:  1.0
 *        Created:  02/15/19 02:41:12
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
#include <map>

class Solution
{
public:
    std::vector<std::string> letterCombinations(const std::string& digits)
    {
        std::vector<std::string> combs;
        if (digits.length() > 0)
        {
            combine(digits, 0, std::string(), combs);
        }

        return combs;
    }

    int combine(const std::string& digits, int idx, const std::string& prefix, std::vector<std::string>& combs)
    {
        static std::map<char, std::string> letters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        if (prefix.length() == digits.length())
        {
            combs.push_back(prefix);
            return 0;
        }

        auto iter = letters.find(digits[idx]);
        if (iter == letters.end())
        {
            // Invalid digit
            return -1;
        }

        for (auto chr: iter->second)
        {
            combine(digits, idx + 1, prefix + chr, combs);
        }

        return 0;
    }
};

int main(int argc, char* argv[])
{
    const std::string digits = "23";
    auto combs = Solution().letterCombinations(digits);
    for (const auto& s: combs)
    {
        printf("%s\n", s.c_str());
    }

    return 0;
}

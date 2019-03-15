/*
 * =====================================================================================
 *
 *       Filename:  regular_expression_matching.cpp
 *
 *    Description:  Regular Expression Matching. 
 *                  Given an input string (s) and a pattern (p), implement regular 
 *                  expression matching with support for '.' and '*'.
 *
 *        Version:  1.0
 *        Created:  03/15/19 11:20:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string>

class Solution
{
public:
    bool isMatch(const std::string& s, const std::string& p)
    {
        if (p.empty())
        {
            return s.empty();
        }

        bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');

        if (p.length() > 1 && p[1] == '*')
        {
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        }
        else
        {
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};

int main(int argc, char* argv[])
{
    std::string s = "aab";
    std::string p = "c*a*b";
    if (argc > 2)
    {
        s = argv[1];
        p = argv[2];
    }
    auto matched = Solution().isMatch(s, p);
    printf("Input string: `%s`, pattern: `%s`\n", s.c_str(), p.c_str());
    printf("Is matched? %s\n", (matched ? "Yes" : "No"));
    return 0;
}

// =====================================================================================
//
//       Filename:  wildcard_matching.cpp
//
//    Description:  44. Wildcard Matching. Given an input string (s) and a pattern (p), 
//                  implement wildcard pattern matching with support for '?' and '*'.
//
//        Version:  1.0
//        Created:  10/12/2019 10:33:38 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <string>

class Solution
{
public:
    bool isMatch(std::string& s, std::string& p)
    {
        int s_idx = 0;
        int p_idx = 0;
        int prev_idx = 0;
        int star_idx = (int)std::string::npos;

        while (s_idx < s.size())
        {
            if (p_idx < p.size() && (s[s_idx] == p[p_idx] || p[p_idx] == '?'))
            {
                // `?` match any single character
                s_idx++;
                p_idx++;
                continue;
            }
            if (p_idx < p.size() && p[p_idx] == '*')
            {
                // `*` match empty sequence
                star_idx = p_idx;
                prev_idx = s_idx;
                p_idx++;
                continue;
            }
            if (star_idx != std::string::npos)
            {
                // `*` match any single character
                p_idx = star_idx + 1;
                s_idx = ++prev_idx;
                continue;
            }

            // Mismatch
            return false;
        }

        while (p_idx < p.size() && p[p_idx] == '*')
        {
            // `*` match empty sequence
            p_idx++;
        }
        return (p_idx == p.size());
    }
};

int main(int argc, char* argv[])
{
    std::string s = "adceb";
    std::string p = "*a*b";
    if (argc > 2)
    {
        s = argv[1];
        p = argv[2];
    }

    bool matched = Solution().isMatch(s, p);
    printf("`%s` `%s` matched? %s\n", s.c_str(), p.c_str(), (matched ? "Yes" : "No"));
    return 0;
}

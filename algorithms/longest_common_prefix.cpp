/*
 * =====================================================================================
 *
 *       Filename:  longest_common_prefix.cpp
 *
 *    Description:  14. Longest Common Prefix: Write a function to find the longest 
 *                  common prefix string amongst an array of strings.
 *
 *        Version:  1.0
 *        Created:  06/29/18 10:48:56
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

// Vertical scanning
class Solution
{
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }

        for (int i = 0; i < strs[0].size(); i++)
        {
            char chr = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (i == strs[j].size() || strs[j][i] != chr)
                {
                    // Stop scanning
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};

int main(int argc, char* argv[])
{
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    if (argc > 2)
    {
        strs.clear();
        for (int i = 1; i < argc; i++)
        {
            strs.push_back(argv[i]);
        }
    }

    std::string prefix = Solution().longestCommonPrefix(strs);
    printf("longest common prefix: %s\n", prefix.c_str());

    return 0;
}

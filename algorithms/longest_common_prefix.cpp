/*
 * =====================================================================================
 *
 *       Filename:  longest_common_prefix.cpp
 *
 *    Description:  Write a function to find the longest common prefix string amongst an 
 *                  array of strings.
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

class Solution
{
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        else if (strs.size() == 1)
        {
            return strs[0];
        }

        const auto& first = strs[0];
        size_t len = 0;
        bool stop = false;
        for (int i = 0; i < first.size(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (i >= strs[j].size() || strs[j][i] != first[i])
                {
                    stop = true;
                    break;
                }
            }

            if (stop)
            {
                break;
            }

            len += 1;
        }

        return first.substr(0, len);
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

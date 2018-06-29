/*
 * =====================================================================================
 *
 *       Filename:  str_str.cpp
 *
 *    Description:  Implement strStr(). 
 *                  Return the index of the first occurrence of needle in haystack, or 
 *                  -1 if needle is not part of haystack.
 *
 *        Version:  1.0
 *        Created:  06/29/18 07:49:02
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
    int strStr(const std::string& haystack, const std::string& needle)
    {
        if (needle.empty())
        {
            return 0;
        }

        int idx = -1;
        for (size_t i = 0; i < haystack.size(); i++)
        {
            if ((i + needle.size()) > haystack.size())
            {
                break;
            }
            if (haystack.substr(i, needle.size()) == needle)
            {
                idx = i;
                break;
            }
        }

        return idx;
    }
};

int main(int argc, char* argv[])
{
    std::string haystack = "hello";
    std::string needle = "ll";
    if (argc > 2)
    {
        haystack = argv[1];
        needle = argv[2];
    }

    int idx = Solution().strStr(haystack, needle);
    printf("haystack: %s, needle: %s, index: %d\n", haystack.c_str(), needle.c_str(), idx);

    return 0;
}

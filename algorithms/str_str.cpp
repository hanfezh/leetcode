/*
 * =====================================================================================
 *
 *       Filename:  str_str.cpp
 *
 *    Description:  28. Implement strStr().
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

// Brute-force
class Solution1
{
public:
    int strStr(const std::string& haystack, const std::string& needle)
    {
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++)
        {
            int j = 0;
            for ( ; j < m; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
            }
            if (j == m)
            {
                return i;
            }
        }

        return -1;
    }
};

// KMP
class Solution2
{
public:
    int strStr(const std::string& haystack, const std::string& needle)
    {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0)
        {
            return 0;
        }

        auto lps = computeLps(needle);
        int i = 0;
        int j = 0;

        while (i < n)
        {
            if (j < m && haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            if (j == m)
            {
                // Found needle
                return i - j;
            }
            else if (i < n && haystack[i] != needle[j])
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }

        return -1;
    }

private:
    std::vector<int> computeLps(const std::string& needle)
    {
        std::vector<int> lps(needle.size(), 0);
        int len = 0;
        int idx = 1;

        while (idx < needle.size())
        {
            if (needle[idx] == needle[len])
            {
                len++;
                lps[idx++] = len;
            }
            else if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[idx++] = 0;
            }
        }

        return lps;
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    std::string haystack = "mississippi";
    std::string needle = "issip";
    if (argc > 2)
    {
        haystack = argv[1];
        needle = argv[2];
    }

    int idx = Solution().strStr(haystack, needle);
    printf("haystack: %s, needle: %s, index: %d\n", haystack.c_str(), needle.c_str(), idx);

    return 0;
}

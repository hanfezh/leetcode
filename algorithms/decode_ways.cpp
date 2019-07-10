/*
 * =====================================================================================
 *
 *       Filename:  decode_ways.cpp
 *
 *    Description:  91. Decode Ways.
 *
 *        Version:  1.0
 *        Created:  07/09/2019 07:48:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string>
#include <vector>

class Solution1;
class Solution2;
using Solution = Solution2;

// Recursive
class Solution1
{
public:
    int numDecodings(std::string& str)
    {
        return numDecodings(str, 0);
    }

private:
    int numDecodings(const std::string& str, int idx)
    {
        int num = 0;
        if (idx < str.size())
        {
            int val = str[idx] - '0';
            if (val >= 1 && val <= 9)
            {
                num += numDecodings(str, idx + 1);
            }
        }
        if (idx < (str.size() - 1))
        {
            int val = (str[idx] - '0') * 10 + str[idx + 1] - '0';
            if (val >= 10 && val <= 26)
            {
                num += numDecodings(str, idx + 2);
            }
        }
        if (idx >= str.size())
        {
            return 1;
        }

        return num;
    }
};

// Non-recursive
class Solution2
{
public:
    int numDecodings(std::string& str)
    {
        if (str.size() == 0)
        {
            return 0;
        }

        std::vector<int> dp(str.size() + 1, 0);
        dp[str.size()] = 1;
        dp[str.size() - 1] = ((str[str.size() - 1] != '0') ? 1 : 0);
        for (int i = str.size() - 2; i >= 0; i--)
        {
            if (str[i] == '0')
            {
                continue;
            }
            int val = (str[i] - '0') * 10 + (str[i + 1] - '0');
            if (val >= 1 && val <= 26)
            {
                dp[i] = dp[i + 1] + dp[i + 2];
            }
            else
            {
                dp[i] = dp[i + 1];
            }
        }

        return dp[0];
    }
};

int main(int argc, char* argv[])
{
    // std::string str = "12";
    std::string str = "6065812287883668764831544958683283296479682877898293612168136334983851946827579555449329483852397155";
    int num = Solution().numDecodings(str);
    printf("Input: %s\nWays: %d\n", str.c_str(), num);
    return 0;
}

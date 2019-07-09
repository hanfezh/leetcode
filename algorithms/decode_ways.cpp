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

class Solution
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

int main(int argc, char* argv[])
{
    std::string str = "12";
    int num = Solution().numDecodings(str);
    printf("Input: %s\nWays: %d\n", str.c_str(), num);
    return 0;
}

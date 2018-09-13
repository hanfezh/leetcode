/*
 * =====================================================================================
 *
 *       Filename:  count_and_say.cpp
 *
 *    Description:  Count and Say: Given an integer n, generate the nth term of the 
 *                  count-and-say sequence.
 *
 *        Version:  1.0
 *        Created:  09/13/18 01:25:26
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
    std::string countAndSay(int n)
    {
        if (n < 1 || n > 30)
        {
            return "";
        }
        else if (n == 1)
        {
            return "1";
        }

        std::string last = countAndSay(n - 1);
        std::string curr;

        char prev = last[0];
        int count = 1;
        for (size_t i = 1; i < last.size(); i++)
        {
            if (last[i] == prev)
            {
                count += 1;
            }
            else
            {
                curr += std::to_string(count) + prev;
                prev = last[i];
                count = 1;
            }
        }

        curr += std::to_string(count) + prev;
        return curr;
    }
};

int main(int argc, char* argv[])
{
    int num = 3;
    if (argc > 1)
    {
        num = atoi(argv[1]);
    }

    std::string str = Solution().countAndSay(num);
    printf("%d -> %s\n", num, str.c_str());

    return 0;
}

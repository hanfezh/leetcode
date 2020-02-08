/*
 * =====================================================================================
 *
 *       Filename:  count_and_say.cpp
 *
 *    Description:  38. Count and Say: Given an integer n, generate the nth term of the 
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

        for (size_t i = 0; i < last.size(); i++)
        {
            int count = 1;
            while ((i + 1 < last.size()) && (last[i] == last[i + 1]))
            {
                i++;
                count++;
            }

            curr += std::to_string(count) + last[i];
        }

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

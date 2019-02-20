/*
 * =====================================================================================
 *
 *       Filename:  integer_replacement.cpp
 *
 *    Description:  Integer Replacement.
 *
 *        Version:  1.0
 *        Created:  02/20/19 06:56:11
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
#include <limits.h>

class Solution
{
public:
    int integerReplacement(int n)
    {
        if (n <= 1)
        {
            return 0;
        }
        else if ((n & 0x1) == 0)
        {
            return (integerReplacement(n >> 1) + 1);
        }
        else
        {
            int a = integerReplacement(n - 1) + 1;
            int b = 0;
            if (n == INT_MAX)
            {
                // Ignore overflow
                int64_t x = n;
                b = integerReplacement((x + 1) / 2) + 2;
            }
            else
            {
                b = integerReplacement(n + 1) + 1;
            }
            return (a > b ? b : a);
        }
    }
};

int main(int argc, char* argv[])
{
    int n = 1000;
    if (argc > 1)
    {
        n = atoi(argv[1]);
    }

    auto steps = Solution().integerReplacement(n);
    printf("%d -> 1? via %d steps\n", n, steps);

    return 0;
}


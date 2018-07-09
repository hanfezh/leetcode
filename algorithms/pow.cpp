/*
 * =====================================================================================
 *
 *       Filename:  pow.cpp
 *
 *    Description:  Pow(x, n): Implement pow(x, n), which calculates x raised to the 
 *                  power n.
 *
 *        Version:  1.0
 *        Created:  07/09/18 01:30:21
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
    double myPow(double x, int n)
    {
        if (x == -1)
        {
            return (n & 0x01 ? -1 : 1);
        }

        double k = 1;
        if (n == INT_MIN)
        {
            k /= x;
            n += 1;
        }

        bool minus = (n < 0 ? true : false);
        n = (minus ? -n : n);

        while (n > 0)
        {
            if (minus)
            {
                k /= x;
            }
            else
            {
                k *= x;
            }
            if (k == 0.0)
            {
                break;
            }
            else if (abs(x) < 2.0 && k == 1.0)
            {
                break;
            }
            n -= 1;
        }

        return k;
    }
};

int main(int argc, char* argv[])
{
    double x = 2.0;
    int n = 10;
    if (argc > 2)
    {
        x = atof(argv[1]);
        n = atoi(argv[2]);
    }

    double x_pow = Solution().myPow(x, n);
    printf("pow(%F, %d)  = %F\n", x, n, x_pow);

    return 0;
}


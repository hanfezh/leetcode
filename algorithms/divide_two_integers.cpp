/*
 * =====================================================================================
 *
 *       Filename:  divide_two_integers.cpp
 *
 *    Description:  Divide Two Integers: Given two integers dividend and divisor, divide 
 *                  two integers without using multiplication, division and mod operator.
 *                  Return the quotient after dividing dividend by divisor. The integer 
 *                  division should truncate toward zero.
 *
 *        Version:  1.0
 *        Created:  08/02/18 01:50:59
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
    int divide(int dividend, int divisor)
    {
        bool minus = (dividend ^ divisor) < 0 ? true : false;
        unsigned int x = ((dividend < 0) ? (~dividend + 1) : dividend);
        unsigned int y = ((divisor < 0) ? (~divisor + 1) : divisor);
        unsigned int z = 0;

        if (x == y)
        {
            z = 1;
        }
        else if (x > y)
        {
            do {
                int n = 0;
                while (x >= (y << 1))
                {
                    n += 1;
                    y <<= 1;
                    if (x == y)
                    {
                        break;
                    }
                }

                // printf("%x, %x, ", x, y);
                x -= y;
                y = ((divisor < 0) ? (~divisor + 1) : divisor);
                z |= (1 << n);
                // printf("%x, %x, %x\n", x, y, z);
            } while (x >= y);
        }

        if (minus)
        {
            return -(int)z;
        }
        else if (z > INT_MAX)
        {
            return INT_MAX;
        }

        return z;
    }
};

int main(int argc, char* argv[])
{
    int dividend = 10;
    int divisor = 3;
    if (argc == 3)
    {
        dividend = atoi(argv[1]);
        divisor = atoi(argv[2]);
    }

    int quotient = Solution().divide(dividend, divisor);
    printf("%d / %d = %d\n", dividend, divisor, quotient);

    return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  sum_of_two_integers.cpp
 *
 *    Description:  Sum of Two Integers. Calculate the sum of two integers a and b, but 
 *                  you are not allowed to use the operator + and -.
 *
 *        Version:  1.0
 *        Created:  03/04/19 12:37:37
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

class Solution
{
public:
    int getSum(int a, int b)
    {
        int sum = 0;

        while (b != 0)
        {
            sum = a ^ b;
            b = (unsigned int)(a & b) << 1;
            a = sum;
        }

        return sum;
    }
};

int main(int argc, char* argv[])
{
    int a = 1;
    int b = 2;
    if (argc > 2)
    {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }

    int sum = Solution().getSum(a, b);
    printf("(%d) + (%d) = %d\n", a, b, sum);
    return 0;
}

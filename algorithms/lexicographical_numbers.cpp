/*
 * =====================================================================================
 *
 *       Filename:  lexicographical_numbers.cpp
 *
 *    Description:  Lexicographical Numbers.
 *                  Given an integer n, return 1 - n in lexicographical order.
 *
 *        Version:  1.0
 *        Created:  07/02/18 07:06:59
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
#include <vector>

class Solution
{
public:
    std::vector<int> lexicalOrder(int n)
    {
        std::vector<int> nums;

        int k = 1;
        for (int i = 0; i < n; i++)
        {
            nums.push_back(k);
            if (k * 10 <= n)
            {
                k *= 10;
            }
            else
            {
                k += 1;
                if ((k % 10) == 0)
                {
                    k /= 10;
                }
                else if (k > n)
                {
                    k /= 10;
                    k += 1;
                }
                while ((k % 10) == 0)
                {
                    k /= 10;
                }
            }
        }

        return nums;
    }
};

int main(int argc, char* argv[])
{
    int num = 29;
    if (argc > 1)
    {
        num = atoi(argv[1]);
    }

    std::vector<int> nums = Solution().lexicalOrder(num);
    for (int n: nums)
    {
        printf("%d\n", n);
    }

    return 0;
}


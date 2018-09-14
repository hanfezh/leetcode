/*
 * =====================================================================================
 *
 *       Filename:  plus_one.cpp
 *
 *    Description:  Plus One: Given a non-empty array of digits representing a 
 *                  non-negative integer, plus one to the integer.
 *
 *        Version:  1.0
 *        Created:  09/14/18 02:05:04
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
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        bool extra = false;

        for (int i = (digits.size() - 1); i >= 0; i--)
        {
            digits[i] += 1;
            if (digits[i] < 10)
            {
                break;
            }

            digits[i] -= 10;
            if (i == 0)
            {
                extra = true;
            }
        }

        if (extra)
        {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> digits = {1, 2, 3};
    auto nums = Solution().plusOne(digits);
    for (auto n: nums)
    {
        printf("%d ", n);
    }
    printf("\n");
}

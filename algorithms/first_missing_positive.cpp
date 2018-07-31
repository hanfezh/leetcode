/*
 * =====================================================================================
 *
 *       Filename:  first_missing_positive.cpp
 *
 *    Description:  First Missing Positive: Given an unsorted integer array, find the 
 *                  smallest missing positive integer.
 *
 *        Version:  1.0
 *        Created:  07/31/18 03:27:18
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
    int firstMissingPositive(const std::vector<int>& nums)
    {
        std::vector<bool> flags;
        flags.resize(nums.size());
        for (size_t i = 0; i < flags.size(); i++)
        {
            flags[i] = false;
        }

        for (auto n: nums)
        {
            if ((n < 1) || (n > nums.size()))
            {
                continue;
            }

            flags[n - 1] = true;
        }

        int fmp = 0;
        for (size_t i = 0; i < flags.size(); i++)
        {
            if (!flags[i])
            {
                fmp = i + 1;
                break;
            }
        }
        if (fmp == 0)
        {
            fmp = flags.size() + 1;
        }

        return fmp;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    if (argc > 4)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    int fmp = Solution().firstMissingPositive(nums);
    for (auto n: nums)
    {
        printf("%d ", n);
    }
    printf("-> %d\n", fmp);

    return 0;
}

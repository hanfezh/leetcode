/*
 * =====================================================================================
 *
 *       Filename:  three_sum_closest.cpp
 *
 *    Description:  3Sum Closest: Given an array nums of n integers and an integer 
 *                  target, find three integers in nums such that the sum is closest to 
 *                  target. Return the sum of the three integers. You may assume that 
 *                  each input would have exactly one solution.
 *
 *        Version:  1.0
 *        Created:  07/26/18 05:05:10
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
#include <algorithm>
#include <vector>

class Solution
{
public:
    int threeSumClosest(std::vector<int>& nums, int target)
    {
        if (nums.size() < 3)
        {
            return 0;
        }

        std::sort(nums.begin(), nums.end());
        int closest = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            int start = i + 1;
            int end = nums.size() - 1;

            while (start < end)
            {
                sum = nums[i] + nums[start] + nums[end];
                if (sum == target)
                {
                    return target;
                }

                if (closest == INT_MAX)
                {
                    closest = sum;
                }
                else if (std::abs(sum - target) < std::abs(closest - target))
                {
                    closest = sum;
                }

                if ((sum - target) < 0)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }

        return closest;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    if (argc > 2)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    int closest = Solution().threeSumClosest(nums, target);
    for (const auto n: nums)
    {
        printf("%d ", n);
    }
    printf("target %d, closest %d\n", target, closest);

    return 0;
}

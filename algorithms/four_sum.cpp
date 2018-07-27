/*
 * =====================================================================================
 *
 *       Filename:  four_sum.cpp
 *
 *    Description:  4Sum: Given an array nums of n integers and an integer target, are 
 *                  there elements a, b, c, and d in nums such that a + b + c + d = 
 *                  target? Find all unique quadruplets in the array which gives the 
 *                  sum of target.
 *
 *        Version:  1.0
 *        Created:  07/27/18 11:06:51
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
#include <algorithm>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
    {
        std::vector<std::vector<int>> sum_list;
        if (nums.size() < 4)
        {
            return sum_list;
        }

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < (nums.size() - 3); i++)
        {
            if ((i > 0) && (nums[i] == nums[i - 1]))
            {
                // Ignore duplicated
                continue;
            }

            std::vector<std::vector<int>> three_list;
            threeSum(std::vector<int>(nums.begin() + i + 1, nums.end()), target - nums[i], &three_list);
            for (auto& num_list: three_list)
            {
                num_list.insert(num_list.begin(), nums[i]);
                sum_list.push_back(num_list);
            }
        }

        return sum_list;
    }

private:
    void threeSum(const std::vector<int>& nums, int target, std::vector<std::vector<int>>* sum_list)
    {
        for (int i = 0; i < (nums.size() - 2); i++)
        {
            if ((i > 0) && (nums[i] == nums[i - 1]))
            {
                // Ignore duplicated
                continue;
            }

            int sum = 0;
            int start = i + 1;
            int end = nums.size() - 1;

            while (start < end)
            {
                sum = nums[i] + nums[start] + nums[end];
                if (sum == target)
                {
                    sum_list->push_back(std::vector<int>({nums[i], nums[start], nums[end]}));
                    while ((start < (end - 1)) && (nums[start] == nums[start + 1]))
                    {
                        // Ignore duplicated
                        start++;
                    }
                    while ((end > (start + 1)) && (nums[end] == nums[end - 1]))
                    {
                        // Ignore duplicated
                        end--;
                    }
                    start++;
                    end--;
                }
                else if (sum < target)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
    }
};

int main(int argc, char* argv[])
{
    // std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    // std::vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};
    std::vector<int> nums = {-5, -4, -2, -2, -2, -1, 0, 0, 1};
    int target = 0;
    if (argc > 4)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    auto sum_list = Solution().fourSum(nums, target);
    for (const auto& num_list: sum_list)
    {
        for (auto n: num_list)
        {
            printf("%d ", n);
        }
        printf("\n");
    }

    return 0;
}

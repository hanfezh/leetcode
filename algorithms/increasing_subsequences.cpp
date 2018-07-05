/*
 * =====================================================================================
 *
 *       Filename:  increasing_subsequences.cpp
 *
 *    Description:  Increasing Subsequences.
 *                  Given an integer array, your task is to find all the different 
 *                  possible increasing subsequences of the given array, and the length 
 *                  of an increasing subsequence should be at least 2.
 *
 *        Version:  1.0
 *        Created:  07/05/18 03:34:52
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
    std::vector<std::vector<int> > findSubsequences(const std::vector<int>& nums)
    {
        std::vector<std::vector<int> > sub_nums;
        if (nums.size() < 2)
        {
            return sub_nums;
        }
        if (nums.size() == 2)
        {
            if (nums[0] <= nums[1])
            {
                sub_nums.push_back(nums);
            }
            return sub_nums;
        }

        auto iter = nums.begin();
        int first = *iter;
        std::vector<int> new_nums(++iter, nums.end());
        sub_nums = findSubsequences(new_nums);

        size_t sub_size = sub_nums.size();
        for (size_t i = 0; i < sub_size; i++)
        {
            auto tmp_nums = sub_nums[i];
            if (first > tmp_nums[0])
            {
                continue;
            }
            tmp_nums.insert(tmp_nums.begin(), first);

            bool found = false;
            for (size_t j = 0; j < sub_nums.size(); j++)
            {
                if (tmp_nums == sub_nums[j])
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                sub_nums.push_back(tmp_nums);
            }
        }

        for (size_t i = 0; i < new_nums.size(); i++)
        {
            if (first > new_nums[i])
            {
                continue;
            }

            std::vector<int> tmp_nums;
            tmp_nums.push_back(first);
            tmp_nums.push_back(new_nums[i]);

            bool found = false;
            for (size_t j = 0; j < sub_nums.size(); j++)
            {
                if (tmp_nums == sub_nums[j])
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                sub_nums.push_back(tmp_nums);
            }
        }

        return sub_nums;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {4, 6, 7, 7};
    if (argc > 2)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    auto sub_nums = Solution().findSubsequences(nums);
    for (const auto& sub_arr: sub_nums)
    {
        for (size_t i = 0; i < sub_arr.size(); i++)
        {
            if (i != 0)
            {
                printf(", ");
            }
            printf("%d", sub_arr[i]);
        }
        printf("\n");
    }

    return 0;
}

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
#include <set>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int> > findSubsequences(const std::vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return std::vector<std::vector<int> >{};
        }

        std::vector<int> tmp_nums;
        std::set<std::vector<int> > sub_nums;
        dfs(nums, 0, &tmp_nums, &sub_nums);
        return std::vector<std::vector<int> >(sub_nums.begin(), sub_nums.end());
    }

private:
    void dfs(const std::vector<int>& nums, int idx, std::vector<int>* tmp_nums, std::set<std::vector<int> >* sub_nums)
    {
        if (idx >= nums.size())
        {
            return;
        }

        dfs(nums, idx + 1, tmp_nums, sub_nums);

        bool pushed = false;
        if ((tmp_nums->size() == 0) || (*(tmp_nums->rbegin()) <= nums[idx]))
        {
            pushed = true;
            tmp_nums->push_back(nums[idx]);
        }

        dfs(nums, idx + 1, tmp_nums, sub_nums);

        if (tmp_nums->size() > 1)
        {
            std::vector<int> new_nums(*tmp_nums);
            sub_nums->insert(new_nums);
        }
        if (pushed)
        {
            tmp_nums->pop_back();
        }
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

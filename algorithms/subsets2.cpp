/*
 * =====================================================================================
 *
 *       Filename:  subsets2.cpp
 *
 *    Description:  Subsets II: Given a collection of integers that might contain 
 *                  duplicates, nums, return all possible subsets (the power set).
 *
 *        Version:  1.0
 *        Created:  07/05/18 09:32:19
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
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int> > subsetsWithDup(const std::vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return std::vector<std::vector<int> >{};
        }

        std::vector<int> seq_nums(nums);
        std::sort(seq_nums.begin(), seq_nums.end());

        std::vector<int> tmp_nums;
        std::set<std::vector<int> > sub_nums;
        dfs(seq_nums, 0, &tmp_nums, &sub_nums);
        return std::vector<std::vector<int> >(sub_nums.begin(), sub_nums.end());
    }

private:
    void dfs(const std::vector<int>& nums, int idx, std::vector<int>* tmp_nums, std::set<std::vector<int> >* sub_nums)
    {
        if (idx == 0)
        {
            sub_nums->insert(std::vector<int>{});
        }
        if (idx >= nums.size())
        {
            return;
        }

        dfs(nums, idx + 1, tmp_nums, sub_nums);
        tmp_nums->push_back(nums[idx]);
        dfs(nums, idx + 1, tmp_nums, sub_nums);

        std::vector<int> new_nums(*tmp_nums);
        sub_nums->insert(new_nums);
        tmp_nums->pop_back();
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 2, 2};
    if (argc > 2)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    auto sub_nums = Solution().subsetsWithDup(nums);
    for (const auto& sub_arr: sub_nums)
    {
        printf("[");
        for (size_t i = 0; i < sub_arr.size(); i++)
        {
            if (i != 0)
            {
                printf(", ");
            }
            printf("%d", sub_arr[i]);
        }
        printf("]\n");
    }

    return 0;
}

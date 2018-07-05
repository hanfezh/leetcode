/*
 * =====================================================================================
 *
 *       Filename:  subsets.cpp
 *
 *    Description:  Subsets: Given a set of distinct integers, nums, return all possible 
 *                  subsets (the power set).
 *
 *        Version:  1.0
 *        Created:  07/05/18 08:33:59
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
    std::vector<std::vector<int> > subsets(const std::vector<int>& nums)
    {
        std::vector<std::vector<int> > sub_nums;
        if (nums.size() == 0)
        {
            return sub_nums;
        }

        std::vector<int> tmp_nums;
        dfs(nums, 0, &tmp_nums, &sub_nums);
        return sub_nums;
    }

private:
    void dfs(const std::vector<int>& nums, int idx, std::vector<int>* tmp_nums, std::vector<std::vector<int> >* sub_nums)
    {
        if (idx == 0)
        {
            sub_nums->push_back(std::vector<int>{});
        }
        if (idx >= nums.size())
        {
            return;
        }

        dfs(nums, idx + 1, tmp_nums, sub_nums);
        tmp_nums->push_back(nums[idx]);
        dfs(nums, idx + 1, tmp_nums, sub_nums);

        std::vector<int> new_nums(*tmp_nums);
        sub_nums->push_back(new_nums);
        tmp_nums->pop_back();
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 2, 3};
    if (argc > 2)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    auto sub_nums = Solution().subsets(nums);
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

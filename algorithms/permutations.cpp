/*
 * =====================================================================================
 *
 *       Filename:  permutations.cpp
 *
 *    Description:  Permutations: Given a collection of distinct integers, return all 
 *                  possible permutations.
 *
 *        Version:  1.0
 *        Created:  09/03/18 11:05:59
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
    std::vector<std::vector<int>> permute(const std::vector<int>& nums)
    {
        std::vector<std::vector<int>> perms;
        if (nums.size() == 0)
        {
            return perms;
        }

        std::vector<bool> visited(nums.size(), false);
        std::vector<int> current;
        dfs(nums, &visited, &current, &perms);
        return perms;
    }

private:
    void dfs(const std::vector<int>& nums, std::vector<bool>* visited, std::vector<int>* current, std::vector<std::vector<int>>* perms)
    {
        if (current->size() == nums.size())
        {
            perms->push_back(*current);
            return;
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (!visited->at(i))
            {
                visited->at(i) = true;
                current->push_back(nums[i]);
                dfs(nums, visited, current, perms);
                current->pop_back();
                visited->at(i) = false;
            }
        }
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 2, 3, 4};
    if (argc > 3)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    auto perms = Solution().permute(nums);
    for (auto& p: perms)
    {
        for (auto n: p)
        {
            printf("%d ", n);
        }
        printf("\n");
    }

    return 0;
}

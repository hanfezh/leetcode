/*
 * =====================================================================================
 *
 *       Filename:  permutations2.cpp
 *
 *    Description:  47. Permutation II. Given a collection of numbers that might contain 
 *                  duplicates, return all possible unique permutations.
 *
 *        Version:  1.0
 *        Created:  04/03/19 05:14:34
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
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
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
    void dfs(const std::vector<int>& nums, std::vector<bool>* visited, 
             std::vector<int>* current, std::vector<std::vector<int>>* perms)
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
                if (i > 0 && nums[i] == nums[i - 1] && !visited->at(i - 1))
                {
                    continue;
                }
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
    std::vector<int> nums = {1, 1, 2};
    if (argc > 3)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    auto perms = Solution().permuteUnique(nums);
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

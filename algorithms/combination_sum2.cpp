/*
 * =====================================================================================
 *
 *       Filename:  combination_sum2.cpp
 *
 *    Description:  40. Combination Sum II. Given a collection of candidate numbers 
 *                  (candidates) and a target number (target), find all unique 
 *                  combinations in candidates where the candidate numbers sums to target.
 *                  Each number in candidates may only be used once in the combination.
 *
 *        Version:  1.0
 *        Created:  03/28/19 01:55:55
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
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)
    {
        std::vector<std::vector<int>> combx;
        std::vector<int> current;
        std::sort(candidates.begin(), candidates.end());
        combine(candidates, 0, target, &current, &combx);
        return combx;
    }

private:
    void combine(const std::vector<int>& candidates, int start, int remain, std::vector<int>* current, std::vector<std::vector<int>>* combx)
    {
        if (remain == 0)
        {
            if (current->size() > 0)
            {
                combx->push_back(*current);
            }
            return;
        }
        else if (remain < 0)
        {
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            current->push_back(candidates[i]);
            combine(candidates, i + 1, remain - candidates[i], current, combx);
            current->pop_back();
        }
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    auto combx = Solution().combinationSum2(nums, target);
    printf("Number of combinations: %lu\n", combx.size());
    for (const auto& item: combx)
    {
        for (auto n: item)
        {
            printf("%d ", n);
        }
        printf("\n");
    }
    return 0;
}


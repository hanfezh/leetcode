/*
 * =====================================================================================
 *
 *       Filename:  combination_sum.cpp
 *
 *    Description:  39. Combination Sum. Given a set of candidate numbers (candidates) 
 *                  (without duplicates) and a target number (target), find all unique 
 *                  combinations in candidates where the candidate numbers sums to target.
 *
 *        Version:  1.0
 *        Created:  03/26/19 02:01:38
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
    std::vector<std::vector<int>> combinationSum(const std::vector<int>& candidates, int target)
    {
        std::vector<std::vector<int>> combx;
        std::vector<int> current;
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
        }
        else if (remain < 0)
        {
            return;
        }
        else
        {
            for (int i = start; i < candidates.size(); i++)
            {
                current->push_back(candidates[i]);
                combine(candidates, i, remain - candidates[i], current, combx);
                current->pop_back();
            }
        }
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {2, 3, 5};
    int target = 8;
    auto combx = Solution().combinationSum(nums, target);
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



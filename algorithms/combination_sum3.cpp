/*
 * =====================================================================================
 *
 *       Filename:  combination_sum3.cpp
 *
 *    Description:  216. Combination Sum III. Find all possible combinations of k 
 *                  numbers that add up to a number n, given that only numbers from 1 to 
 *                  9 can be used and each combination should be a unique set of numbers.
 *
 *        Version:  1.0
 *        Created:  03/28/19 02:22:17
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
    std::vector<std::vector<int>> combinationSum3(int k, int n)
    {
        std::vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::vector<std::vector<int>> combx;
        std::vector<int> current;
        combine(candidates, 0, k, n, &current, &combx);
        return combx;
    }

private:
    void combine(const std::vector<int>& candidates, int start, int count, int remain, 
                 std::vector<int>* current, std::vector<std::vector<int>>* combx)
    {
        if (remain == 0)
        {
            if (current->size() > 0 && current->size() == count)
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
            current->push_back(candidates[i]);
            combine(candidates, i + 1, count, remain - candidates[i], current, combx);
            current->pop_back();
        }
    }
};

int main(int argc, char* argv[])
{
    int k = 3;
    int n = 9;
    auto combx = Solution().combinationSum3(k, n);
    printf("Number of combinations: %lu\n", combx.size());
    for (const auto& item: combx)
    {
        for (auto num: item)
        {
            printf("%d ", num);
        }
        printf("\n");
    }
    return 0;
}


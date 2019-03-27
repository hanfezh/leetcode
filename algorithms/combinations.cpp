/*
 * =====================================================================================
 *
 *       Filename:  combinations.cpp
 *
 *    Description:  77. Combinations. Given two integers n and k, return all possible 
 *                  combinations of k numbers out of 1 ... n.
 *
 *        Version:  1.0
 *        Created:  03/27/19 03:31:54
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
    std::vector<std::vector<int>> combine(int n, int k)
    {
        std::vector<std::vector<int>> combx;
        std::vector<int> current;
        combine(n, k, 1, &current, &combx);
        return combx;
    }

private:
    void combine(int n, int k, int start, std::vector<int>* current, std::vector<std::vector<int>>* combx)
    {
        if (n < 1 || k < 1 || k > n)
        {
            return;
        }
        else if (current->size() == k)
        {
            combx->push_back(*current);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            current->push_back(i);
            combine(n, k, i + 1, current, combx);
            current->pop_back();
        }
    }
};

int main(int argc, char* argv[])
{
    int n = 4;
    int k = 2;
    auto combx = Solution().combine(n, k);
    printf("Size of combinations: %lu\n", combx.size());
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

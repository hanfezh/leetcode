/*
 * =====================================================================================
 *
 *       Filename:  house_robber.cpp
 *
 *    Description:  198. House Robber. 
 *
 *        Version:  1.0
 *        Created:  03/28/19 11:46:30
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

// Recursive
class Solution1
{
public:
    int rob(const std::vector<int>& nums)
    {
        std::vector<int> amounts(nums.size(), -1);
        return rob(nums, nums.size() - 1, &amounts);
    }

private:
    int rob(const std::vector<int>& nums, int idx, std::vector<int>* amounts)
    {
        if (idx < 0)
        {
            return 0;
        }
        else if (amounts->at(idx) != -1)
        {
            return amounts->at(idx);
        }

        int prev = rob(nums, idx - 1, amounts);
        int curr = nums[idx] + rob(nums, idx - 2, amounts);
        amounts->at(idx) = (prev > curr ? prev : curr);
        return amounts->at(idx);
    }
};

// Iterative
class Solution2
{
public:
    int rob(const std::vector<int>& nums)
    {
        int adj = 0;
        int pre = 0;
        int cur = 0;
        for (const auto val: nums)
        {
            cur = std::max(val + pre, adj);
            pre = adj;
            adj = cur;
        }
        return cur;
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    std::vector<int> nums = {2, 7, 9, 3, 1};
    auto money = Solution().rob(nums);
    printf("Rob money: %d\n", money);
    return 0;
}

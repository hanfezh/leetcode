/*
 * =====================================================================================
 *
 *       Filename:  combination_sum4.cpp
 *
 *    Description:  377. Combination Sum IV. Given an integer array with all positive 
 *                  numbers and no duplicates, find the number of possible combinations 
 *                  that add up to a positive integer target. Note that different 
 *                  sequences are counted as different combinations.
 *
 *        Version:  1.0
 *        Created:  03/28/19 06:18:02
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
    int combinationSum4(const std::vector<int>& nums, int target)
    {
        std::vector<int> counts(target + 1, -1);
        counts[0] = 1;
        return permute(nums, target, &counts);
    }

private:
    // Enable repetitive
    int permute(const std::vector<int>& nums, int remain, std::vector<int>* counts)
    {
        if (counts->at(remain) != -1)
        {
            return counts->at(remain);
        }

        int permx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (remain >= nums[i])
            {
                permx += permute(nums, remain - nums[i], counts);
            }
        }

        counts->at(remain) = permx;
        return permx;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 2, 3};
    int target = 4;
    auto count = Solution().combinationSum4(nums, target);
    printf("Number of combinations: %d\n", count);
    return 0;
}


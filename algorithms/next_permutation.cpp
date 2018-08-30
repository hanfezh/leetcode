/*
 * =====================================================================================
 *
 *       Filename:  next_permutation.cpp
 *
 *    Description:  Next Permutation: Implement next permutation, which rearranges 
 *                  numbers into the lexicographically next greater permutation of 
 *                  numbers. If such arrangement is not possible, it must rearrange it 
 *                  as the lowest possible order (ie, sorted in ascending order).
 *
 *        Version:  1.0
 *        Created:  08/21/18 11:10:00
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
#include <algorithm>

class Solution
{
public:
    void nextPermutation(std::vector<int>& nums)
    {
        int i = nums.size() - 1;
        int j = -1;

        for ( ; i > 0; i--)
        {
            if (nums[i] <= nums[i - 1])
            {
                continue;
            }

            for (j = i; j < nums.size(); j++)
            {
                if (nums[j] <= nums[i - 1])
                {
                    break;
                }
            }
            j -= 1;
            break;
        }

        if (i == 0)
        {
            // Reverse
            std::reverse(nums.begin(), nums.end());
        }
        else
        {
            // i > 0
            int a = nums[i - 1];
            nums[i - 1] = nums[j];
            nums[j] = a;
            std::reverse(nums.begin() + i, nums.end());
        }
    }
};

int main(int argc, char* argv[])
{
    // std::vector<int> nums = {1, 2, 3};
    // std::vector<int> nums = {5, 4, 7, 5, 3, 2};
    std::vector<int> nums = {4, 2, 0, 2, 3, 2, 0};
    if (argc > 3)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    for (auto n: nums)
    {
        printf("%d ", n);
    }
    printf("-> ");
    Solution().nextPermutation(nums);
    for (auto n: nums)
    {
        printf("%d ", n);
    }
    printf("\n");

    return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  find_duplicates.cpp
 *
 *    Description:  Find All Duplicates in an Array. 
 *                  Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some 
 *                  elements appear twice and others appear once. Find all the elements 
 *                  that appear twice in this array.
 *
 *        Version:  1.0
 *        Created:  02/18/19 09:57:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <vector>

class Solution
{
public:
    std::vector<int> findDuplicates(const std::vector<int>& nums)
    {
        std::vector<int> flags(nums.size(), 0);
        for (auto n: nums)
        {
            flags[n - 1] += 1;
        }

        std::vector<int> dups;
        for (int i = 0; i < flags.size(); i++)
        {
            if (flags[i] > 1)
            {
                dups.push_back(i + 1);
            }
        }

        return dups;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    auto dups = Solution().findDuplicates(nums);
    for (auto n: dups)
    {
        printf("%d ", n);
    }
    printf("\n");

    return 0;
}

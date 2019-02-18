/*
 * =====================================================================================
 *
 *       Filename:  find_disappeared_numbers.cpp
 *
 *    Description:  Find All Numbers Disappeared in an Array.
 *                  Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), 
 *                  some elements appear twice and others appear once. Find all the 
 *                  elements of [1, n] inclusive that do not appear in this array.
 *
 *        Version:  1.0
 *        Created:  02/18/19 11:22:08
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
    std::vector<int> findDisappearedNumbers(const std::vector<int>& nums)
    {
        std::vector<bool> flags(nums.size(), false);
        for (auto n: nums)
        {
            flags[n - 1] = true;
        }

        std::vector<int> dis_nums;
        for (int i = 0; i < flags.size(); i++)
        {
            if (flags[i] == false)
            {
                dis_nums.push_back(i + 1);
            }
        }

        return dis_nums;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    auto dis_nums = Solution().findDisappearedNumbers(nums);
    for (auto n: dis_nums)
    {
        printf("%d ", n);
    }
    printf("\n");

    return 0;
}

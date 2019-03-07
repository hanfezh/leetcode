/*
 * =====================================================================================
 *
 *       Filename:  find_the_duplicate_number.cpp
 *
 *    Description:  Find the Duplicate Number. Given an array nums containing n + 1 
 *                  integers where each integer is between 1 and n (inclusive), prove 
 *                  that at least one duplicate number must exist. Assume that there is 
 *                  only one duplicate number, find the duplicate one.
 *
 *        Version:  1.0
 *        Created:  03/05/19 11:34:18
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
    int findDuplicate(std::vector<int>& nums)
    {
        int i = 0;
        while (i < nums.size())
        {
            int j = nums[i];
            if (j <= 0 || j >= nums.size())
            {
                break;
            }
            if (j == nums[j])
            {
                // Found duplicate
                return j;
            }

            swap(&nums[i], &nums[j]);
        }

        return 0;
    }

private:
    void swap(int* a, int* b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 3, 4, 2, 2};
    if (argc > 1)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }
    auto dup_num = Solution().findDuplicate(nums);
    printf("Duplicate number: %d\n", dup_num);
    return 0;
}

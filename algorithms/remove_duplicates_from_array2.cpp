/*
 * =====================================================================================
 *
 *       Filename:  remove_duplicates_from_array2.cpp
 *
 *    Description:  80. Remove Duplicates from Sorted Array II. Given a sorted array 
 *                  nums, remove the duplicates in-place such that duplicates appeared 
 *                  at most twice and return the new length.
 *
 *        Version:  1.0
 *        Created:  05/21/2019 12:33:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
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
    int removeDuplicates(std::vector<int>& nums)
    {
        if (nums.size() <= 2)
        {
            return nums.size();
        }

        int last = 1;
        int idx = last + 1;
        while (idx < nums.size())
        {
            if ((nums[idx] == nums[last]) &&
                (nums[idx] == nums[last - 1]))
            {
                idx++;
            }
            else
            {
                if (idx > (last + 1))
                {
                    nums[last + 1] = nums[idx];
                }
                last++;
                idx++;
            }
        }

        return (last + 1);
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int len = Solution().removeDuplicates(nums);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
};

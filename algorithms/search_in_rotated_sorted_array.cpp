/*
 * =====================================================================================
 *
 *       Filename:  search_in_rotated_sorted_array.cpp
 *
 *    Description:  Search in Rotated Sorted Array. Suppose an array sorted in ascending 
 *                  order is rotated at some pivot unknown to you beforehand. You are 
 *                  given a target value to search. If found in the array return its 
 *                  index, otherwise return -1.
 *                  You may assume no duplicate exists in the array.
 *                  Your algorithm's runtime complexity must be in the order of O(log n).
 *
 *        Version:  1.0
 *        Created:  03/21/19 05:07:59
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
    int search(const std::vector<int>& nums, int target)
    {
        return lookup(nums, 0, nums.size() - 1, target);
    }

private:
    int lookup(const std::vector<int>& nums, int start, int end, int target)
    {
        if (start > end)
        {
            return -1;
        }

        int pivot = (start + end) / 2;
        if (nums[pivot] == target)
        {
            // Found target
            return pivot;
        }
        if (nums[pivot] < nums[end])
        {
            // Right half is ascending
            if (nums[pivot] > target || nums[end] < target)
            {
                return lookup(nums, start, pivot - 1, target);
            }
            return lookup(nums, pivot + 1, end, target);
        }
        else
        {
            // Left half is ascending
            // nums[pivot] > nums[end], assume no duplicate
            if (nums[start] > target || nums[pivot] < target)
            {
                return lookup(nums, pivot + 1, end, target);
            }
            return lookup(nums, start, pivot - 1, target);
        }
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    auto idx = Solution().search(nums, 3);
    printf("Found index? %d\n", idx);
    return 0;
}

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
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
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
                    end = pivot - 1;
                }
                else
                {
                    start = pivot + 1;
                }
            }
            else
            {
                // Left half is ascending
                // nums[pivot] > nums[end], assume no duplicate
                if (nums[start] > target || nums[pivot] < target)
                {
                    start = pivot + 1;
                }
                else
                {
                    end = pivot - 1;
                }
            }
        }

        return -1;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    auto idx = Solution().search(nums, 3);
    printf("Found index? %d\n", idx);
    return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  position_in_sorted_array.cpp
 *
 *    Description:  34. Find First and Last Position of Element in Sorted Array. 
 *                  Given an array of integers nums sorted in ascending order, find the 
 *                  starting and ending position of a given target value.
 *
 *        Version:  1.0
 *        Created:  08/30/18 11:52:53
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
    std::vector<int> searchRange(const std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        // Search for the leftmost index
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        // nums.size() == 0 || left == right
        if (left >= nums.size() || nums[left] != target)
        {
            // Not found
            return std::vector<int>(2, -1);
        }

        std::vector<int> indices(2, left);
        right = nums.size() - 1;

        // Search for the rightmost index
        while (left < right)
        {
            int mid = (left + right + 1) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
        }

        indices[1] = right;
        return indices;
    }
};

int main(int argc, char* argv[])
{
    // std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    if (argc > 2)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    std::vector<int> ranges = Solution().searchRange(nums, 6);
    for (auto n: ranges)
    {
        printf("%d ", n);
    }
    printf("\n");

    return 0;
}

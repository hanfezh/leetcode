/*
 * =====================================================================================
 *
 *       Filename:  position_in_sorted_array.cpp
 *
 *    Description:  Find First and Last Position of Element in Sorted Array: Given an 
 *                  array of integers nums sorted in ascending order, find the starting 
 *                  and ending position of a given target value.
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
        int found = -1;
        bool exist = searchRange(nums, 0, nums.size() - 1, target, &found);
        if (!exist)
        {
            return std::vector<int>({-1, -1});
        }

        int start = found;
        int end = found;
        while (start > 0)
        {
            if (nums[start - 1] != target)
            {
                break;
            }
            start--;
        }
        while (end < (nums.size() - 1))
        {
            if (nums[end + 1] != target)
            {
                break;
            }
            end++;
        }
        return std::vector<int>({start, end});
    }

private:
    bool searchRange(const std::vector<int>& nums, int start, int end, int target, int* found)
    {
        if (start > end)
        {
            return false;
        }
        if ((nums[start] > target) || (nums[end] < target))
        {
            return false;
        }

        int middle = (end + start) / 2 ;
        if (nums[middle] == target)
        {
            *found = middle;
            return true;
        }
        else if (nums[middle] < target)
        {
            return searchRange(nums, middle + 1, end, target, found);
        }
        else
        {
            return searchRange(nums, start, middle - 1, target, found);
        }
    }
};

int main(int argc, char* argv[])
{
    // std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    if (argc > 3)
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

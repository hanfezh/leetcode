/*
 * =====================================================================================
 *
 *       Filename:  search_in_rotated_sorted_array2.cpp
 *
 *    Description:  Search in Rotated Sorted Array II.
 *
 *        Version:  1.0
 *        Created:  03/22/19 09:23:48
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
    bool search(const std::vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            int pivot = (start + end) / 2;
            if (nums[pivot] == target)
            {
                // Found target
                return true;
            }
            if (nums[pivot] == nums[end])
            {
                end--;
            }
            else if (nums[pivot] == nums[start])
            {
                start++;
            }
            else if (nums[pivot] < nums[end])
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
                // nums[pivot] > nums[end]
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

        return false;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {2, 2, 2, 2, 3, 2, 2, 2};
    auto found = Solution().search(nums, 3);
    printf("Found index? %s\n", (found ? "Yes" : "No"));
    return 0;
}

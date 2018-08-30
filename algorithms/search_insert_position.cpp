/*
 * =====================================================================================
 *
 *       Filename:  search_insert_position.cpp
 *
 *    Description:  Search Insert Position: Given a sorted array and a target value, 
 *                  return the index if the target is found. If not, return the index 
 *                  where it would be if it were inserted in order.
 *
 *        Version:  1.0
 *        Created:  08/30/18 11:11:08
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

class Solution {
public:
    int searchInsert(const std::vector<int>& nums, int target)
    {
        size_t i;
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= target)
            {
                break;
            }
        }

        return i;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 2, 3};
    if (argc > 3)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    int idx = Solution().searchInsert(nums, 2);
    printf("%d\n", idx);

    return 0;
}

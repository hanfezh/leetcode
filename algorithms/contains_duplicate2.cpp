/*
 * =====================================================================================
 *
 *       Filename:  contains_duplicate2.cpp
 *
 *    Description:  Contains Duplicate II. Given an array of integers and an integer k, 
 *                  find out whether there are two distinct indices i and j in the array 
 *                  such that nums[i] = nums[j] and the absolute difference between i 
 *                  and j is at most k.
 *
 *        Version:  1.0
 *        Created:  02/26/19 09:03:17
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
#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k)
    {
#define __UNORDERED_MAP__
#ifdef __UNORDERED_MAP__
        std::unordered_map<int, size_t> indexes;
        for (size_t i = 0; i < nums.size(); i++)
        {
            auto iter = indexes.find(nums[i]);
            if (iter != indexes.end())
            {
                if (i - iter->second <= k)
                {
                    return true;
                }
            }

            // Update index
            indexes[nums[i]] = i;
        }

        return false;

#else
        if (k < 1 || nums.size() < 2)
        {
            return false; 
        }
        else if (k >= (nums.size() - 1))
        {
            // Same as 217 `Contains Duplicate`
            std::sort(nums.begin(), nums.end());
            for (size_t i = 1; i < nums.size(); i++)
            {
                if (nums[i] == nums[i - 1])
                {
                    return true;
                }
            }
            return false; 
        }

        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; ((j <= i + k) && (j < nums.size())); j++)
            {
                if (nums[i] == nums[j])
                {
                    return true;
                }
            }
        }

        return false;
#endif
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
    if (argc > 2)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }
    auto is_dup = Solution().containsNearbyDuplicate(nums, 3);
    printf("Contains duplicate? %s\n", (is_dup ? "Yes" : "No"));
    return 0;
}

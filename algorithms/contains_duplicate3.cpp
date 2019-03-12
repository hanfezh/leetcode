/*
 * =====================================================================================
 *
 *       Filename:  contains_duplicate3.cpp
 *
 *    Description:  Contains Duplicate III. Given an array of integers, find out whether 
 *                  there are two distinct indices i and j in the array such that the 
 *                  absolute difference between nums[i] and nums[j] is at most t and the 
 *                  absolute difference between i and j is at most k.
 *
 *        Version:  1.0
 *        Created:  03/12/19 02:16:15
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
#include <limits.h>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t)
    {
        auto contain_func = [](const std::unordered_map<int64_t, int64_t>& values, 
                               int64_t bucket, int64_t target, int t) -> bool {
            auto iter = values.find(bucket);
            return ((iter != values.end()) && (std::abs(target - iter->second) <= t));
        };

        if (t < 0)
        {
            return false;
        }

        std::unordered_map<int64_t, int64_t> values;
        for (int i = 0; i < nums.size(); i++)
        {
            int64_t target = (int64_t)nums[i] - INT_MIN;
            int64_t bucket = target / ((int64_t)t + 1);
            if (contain_func(values, bucket, target, t) ||
                contain_func(values, bucket - 1, target, t) ||
                contain_func(values, bucket + 1, target, t))
            {
                return true;
            }

            values[bucket] = target;
            if (i >= k)
            {
                bucket = ((int64_t)nums[i - k] - INT_MIN) / ((int64_t)t + 1);
                values.erase(bucket);
            }
        }

        return false;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 5, 9, 1, 5, 9};
    int k = 2;
    int t = 3;
    if (argc > 2)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }
    auto is_dup = Solution().containsNearbyAlmostDuplicate(nums, k, t);
    printf("Contains duplicate? %s\n", (is_dup ? "Yes" : "No"));
    return 0;
}

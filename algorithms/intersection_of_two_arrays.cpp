/*
 * =====================================================================================
 *
 *       Filename:  intersection_of_two_arrays.cpp
 *
 *    Description:  Intersection of Two Arrays.
 *
 *        Version:  1.0
 *        Created:  03/04/19 11:44:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    std::vector<int> intersection(const std::vector<int>& nums1, const std::vector<int>& nums2)
    {
        std::unordered_set<int> unordered_nums(nums1.begin(), nums1.end());
        std::vector<int> mixed_nums;
        for (auto num: nums2)
        {
            if (unordered_nums.count(num) > 0)
            {
                mixed_nums.push_back(num);
                unordered_nums.erase(num);
            }
        }

        return mixed_nums;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {3, 4, 5, 6, 7};
    auto mixed_nums = Solution().intersection(nums1, nums2);
    if (mixed_nums.size() > 0)
    {
        printf("Intersection:");
        for (auto num: mixed_nums)
        {
            printf(" %d", num);
        }
        printf("\n");
    }
    return 0;
}

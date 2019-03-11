/*
 * =====================================================================================
 *
 *       Filename:  intersection_of_two_arrays2.cpp
 *
 *    Description:  Intersection of Two Arrays II.
 *
 *        Version:  1.0
 *        Created:  03/11/19 05:17:17
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
#include <unordered_map>

class Solution
{
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::unordered_map<int, int> counts;
        for (auto n: nums1)
        {
            auto pa = counts.insert(std::make_pair(n, 1));
            if (!pa.second)
            {
                pa.first->second += 1;
            }
        }

        std::vector<int> mixed_nums;
        for (auto n: nums2)
        {
            auto it = counts.find(n);
            if (it == counts.end())
            {
                continue;
            }

            mixed_nums.push_back(n);
            it->second -= 1;
            if (it->second < 1)
            {
                counts.erase(it);
            }
        }

        return mixed_nums;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {3, 4, 5, 6, 7};
    auto mixed_nums = Solution().intersect(nums1, nums2);
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

/*
 * =====================================================================================
 *
 *       Filename:  set_mismatch.cpp
 *
 *    Description:  Set Mismatch.
 *
 *        Version:  1.0
 *        Created:  03/08/19 01:58:05
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
#include <unordered_set>

class Solution
{
public:
    std::vector<int> findErrorNums(std::vector<int>& nums)
    {
        /**
         * index: a b c d e
         * value: a b c c e
         * val = (a ^ b ^ c ^ d ^ e) ^ (a ^ b ^ c ^ c ^ e) = d ^ c
         * dup = c
         * mis = (d ^ c) ^ c = val ^ dup
         */
        std::unordered_set<int> s;
        int dup = 0;
        int mis = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (s.count(nums[i]) > 0)
            {
                dup = nums[i];
            }
            else
            {
                s.insert(nums[i]);
            }
            mis ^= (i + 1) ^ nums[i];
        }

        if (dup > 0)
        {
            mis ^= dup;
            return std::vector<int>({dup, mis});
        }

        return std::vector<int>();
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {3, 2, 3, 4, 6, 5};
    if (argc > 1)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    auto errors = Solution().findErrorNums(nums);
    if (errors.size() > 0)
    {
        printf("Error numbers:");
        for (auto n: errors)
        {
            printf(" %d", n);
        }
        printf("\n");
    }

    return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  longest_increasing_subsequence.cpp
 *
 *    Description:  300. Longest Increasing Subsequence. Given an unsorted array of 
 *                  integers, find the length of longest increasing subsequence.
 *
 *        Version:  1.0
 *        Created:  07/13/2019 04:56:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.size() < 1)
        {
            return 0;
        }

        vector<int> lens(nums.size(), 0);
        lens[0] = 1;

        int last_max = lens[0];
        for (int i = 1; i < nums.size(); i++)
        {
            lens[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    lens[i] = std::max(lens[j] + 1, lens[i]);
                }
            }

            last_max = std::max(last_max, lens[i]);
        }

        return last_max;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    if (argc > 1)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    auto max_len = Solution().lengthOfLIS(nums);
    printf("Length of LIS: %d\n", max_len);
    return 0;
}

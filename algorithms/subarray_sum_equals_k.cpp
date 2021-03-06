/*
 * =====================================================================================
 *
 *       Filename:  subarray_sum_equals_k.cpp
 *
 *    Description:  560. Subarray Sum Equals K. 
 *                  Given an array of integers and an integer k, you need to find the 
 *                  total number of continuous subarrays whose sum equals to k.
 *
 *        Version:  1.0
 *        Created:  04/30/19 01:47:51
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
#include<unordered_map>

class Solution1
{
public:
    int subarraySum(std::vector<int>& nums, int k)
    {
        int sum = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] == k)
                {
                    sum++;
                }
                if (j > i)
                {
                    nums[j] -= nums[i];
                }
            }
        }

        return sum;
    }
};

class Solution2
{
public:
    int subarraySum(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> pre_sums  = {{0, 1},};
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int sub = sum - k;
            auto it = pre_sums.find(sub);
            if (it != pre_sums.end())
            {
                cnt += it->second;
            }
            pre_sums[sum]++;
        }

        return cnt;
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 2, 1, 2, 1};
    int k = 3;
    int sum = Solution().subarraySum(nums, k);
    printf("Total number of continuous subarrays: %d\n", sum);
    return 0;

}

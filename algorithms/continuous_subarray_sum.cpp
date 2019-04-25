/*
 * =====================================================================================
 *
 *       Filename:  continuous_subarray_sum.cpp
 *
 *    Description:  523. Continuous Subarray sum. Given a list of non-negative numbers 
 *                  and a target integer k, write a function to check if the array has a 
 *                  continuous subarray of size at least 2 that sums up to the multiple 
 *                  of k, that is, sums up to n*k where n is also an integer.
 *
 *        Version:  1.0
 *        Created:  04/25/19 12:37:37
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
    bool checkSubarraySum(std::vector<int>& nums, int k)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }

        for (int i = 0; i < nums.size() - 1; i ++)
        {
            for (int j = i + 1 ; j < nums.size(); j++)
            {
                if ((k == 0 && nums[j] == 0) ||
                    (k != 0 && nums[j] % k == 0))
                {
                    return true;
                }
                nums[j] -= nums[i];
            }
        }

        return false;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {0, 0};
    int k = -1;
    bool exist = Solution().checkSubarraySum(nums, k);
    printf("Exist? %s\n", (exist ? "Yes" : "No"));
    return 0;
}

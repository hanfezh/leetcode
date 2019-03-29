/*
 * =====================================================================================
 *
 *       Filename:  maximum_product_subarray.cpp
 *
 *    Description:  152. Maximum Product Subarray. Given an integer array nums, find the
 *                  contiguous subarray within an array (containing at least one number) 
 *                  which has the largest product.
 *
 *        Version:  1.0
 *        Created:  03/29/19 03:21:10
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

class Solution
{
public:
    // Dynamic programming
    int maxProduct(const std::vector<int>& nums)
    {
        if (nums.size() < 1)
        {
            return 0;
        }

        std::vector<int> max_list(nums.size(), 0);
        std::vector<int> min_list(nums.size(), 0);
        int max_prod = nums[0];
        max_list[0] = nums[0];
        min_list[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                max_list[i] = std::max(nums[i], nums[i] * max_list[i - 1]);
                min_list[i] = std::min(nums[i], nums[i] * min_list[i - 1]);
            }
            else
            {
                max_list[i] = std::max(nums[i], nums[i] * min_list[i - 1]);
                min_list[i] = std::min(nums[i], nums[i] * max_list[i - 1]);
            }
            max_prod = std::max(max_prod, max_list[i]);
        }

        return max_prod;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {2, 3, -2, 4};
    if (argc > 1)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    int max_prod = Solution().maxProduct(nums);
    printf("Max product is: %d\n", max_prod);
    return 0;
}

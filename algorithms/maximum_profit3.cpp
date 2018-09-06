/*
 * =====================================================================================
 *
 *       Filename:  maximum_profit3.cpp
 *
 *    Description:  Best Time to Buy and Sell Stock III.
 *
 *        Version:  1.0
 *        Created:  09/06/18 06:30:33
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
#include <algorithm>
#include <vector>

class Solution
{
public:
    int maxProfit(const std::vector<int>& prices)
    {
        if (prices.size() < 2)
        {
            return 0;
        }

        std::vector<int> left(prices.size(), 0);
        std::vector<int> right(prices.size(), 0);

        int min_price = prices[0];
        for (size_t i = 1; i < prices.size(); i++)
        {
            if (prices[i] < min_price)
            {
                min_price = prices[i];
            }
            int cur_profit = prices[i] - min_price;
            left[i] = std::max(left[i - 1], cur_profit);
        }

        int max_price = *(prices.rbegin());
        for (int i = (prices.size() - 2); i >= 0; i--)
        {
            if (prices[i] > max_price)
            {
                max_price = prices[i];
            }
            int cur_profit = max_price - prices[i];
            right[i] = std::max(right[i + 1], cur_profit);
        }

        int max_profit = 0;
        for (size_t i = 0; i < left.size(); i++)
        {
            int cur_profit = left[i] + right[i];
            if (cur_profit > max_profit)
            {
                max_profit = cur_profit;
            }
        }

        return max_profit;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {3, 3, 5, 0, 0, 3, 1, 4};
    if (argc > 3)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    for (auto n: nums)
    {
        printf("%d ", n);
    }
    printf("\n");
    int max = Solution().maxProfit(nums);
    printf("%d\n", max);

    return 0;
}

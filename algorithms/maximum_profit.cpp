/*
 * =====================================================================================
 *
 *       Filename:  maximum_profit.cpp
 *
 *    Description:  Best Time to Buy and Sell Stock.
 *
 *        Version:  1.0
 *        Created:  09/06/18 01:49:21
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

class Solution
{
public:
    int maxProfit(const std::vector<int>& prices)
    {
        int min_price = INT_MAX;
        int max_profit = 0;

        for (size_t i = 0; i < prices.size(); i++)
        {
            int cur_profit = prices[i] - min_price;
            if (cur_profit > max_profit)
            {
                max_profit = cur_profit;
            }
            if (prices[i] < min_price)
            {
                min_price = prices[i];
            }
        }

        return max_profit;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {7, 1, 5, 3, 6, 4};
    if (argc > 3)
    {
        nums.clear();
        for (int i = 1; i < argc; i++)
        {
            nums.push_back(atoi(argv[i]));
        }
    }

    int max = Solution().maxProfit(nums);
    printf("%d\n", max);

    return 0;
}

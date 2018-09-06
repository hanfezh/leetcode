/*
 * =====================================================================================
 *
 *       Filename:  maximum_profit2.cpp
 *
 *    Description:  Best Time to Buy and Sell Stock II.
 *
 *        Version:  1.0
 *        Created:  09/06/18 02:39:36
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
        if (prices.size() == 0)
        {
            return 0;
        }

        int min_price = prices[0];
        int max_price = 0;
        int max_profit = 0;

        for (size_t i = 1; i < prices.size(); i++)
        {
            if (prices[i] >= prices[i - 1])
            {
                max_price = prices[i];
                continue;
            }

            if (max_price > min_price)
            {
                max_profit += max_price - min_price;
            }
            min_price = prices[i];
            max_price = 0;
        }

        if (max_price > min_price)
        {
            max_profit += max_price - min_price;
        }

        return max_profit;
    }
};

int main(int argc, char* argv[])
{
    // std::vector<int> nums = {7, 1, 5, 3, 6, 4};
    std::vector<int> nums = {1, 2, 3, 4, 5};
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

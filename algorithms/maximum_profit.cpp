/*
 * =====================================================================================
 *
 *       Filename:  maximum_profit.cpp
 *
 *    Description:  121. Best Time to Buy and Sell Stock.
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
#include <climits>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Solution {
 public:
  int maxProfit(const std::vector<int>& prices) {
    int min_price = INT_MAX;
    int max_profit = 0;

    for (size_t i = 0; i < prices.size(); i++) {
      int cur_profit = prices[i] - min_price;
      if (cur_profit > max_profit) {
        max_profit = cur_profit;
      }
      if (prices[i] < min_price) {
        min_price = prices[i];
      }
    }

    return max_profit;
  }
};

TEST(Solution, maxProfit) {
  std::vector<std::pair<std::vector<int>, int>> cases = {
      std::make_pair(std::vector<int>{0}, 0),
      std::make_pair(std::vector<int>{7, 1, 5, 3, 6, 4}, 5),
      std::make_pair(std::vector<int>{7, 6, 4, 3, 1}, 0),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().maxProfit(c.first), c.second);
  }
}

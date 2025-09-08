/*
 * =====================================================================================
 *
 *       Filename:  maximum_profit2.cpp
 *
 *    Description:  122. Best Time to Buy and Sell Stock II.
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

#include <vector>

#include "gtest/gtest.h"

// Peak Valley Approach
class Solution1 {
 public:
  int maxProfit(std::vector<int>& prices) {
    int max_profit = 0;
    int min_price = prices[0];
    int max_price = prices[0];

    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] > max_price) {
        max_price = prices[i];
      } else {
        max_profit += max_price - min_price;
        min_price = prices[i];
        max_price = prices[i];
      }
    }
    max_profit += max_price - min_price;
    return max_profit;
  }
};

// Optimized solution
class Solution2 {
 public:
  int maxProfit(const std::vector<int>& prices) {
    int max_profit = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] > prices[i - 1]) {
        max_profit += prices[i] - prices[i - 1];
      }
    }
    return max_profit;
  }
};

TEST(Solution, maxProfit) {
  std::vector<std::pair<std::vector<int>, int>> cases = {
      {{7, 1, 5, 3, 6, 4}, 7},
      {{1, 2, 3, 4, 5}, 4},
      {{7, 6, 4, 3, 1}, 0},
  };
  for (auto& [prices, max_profit] : cases) {
    EXPECT_EQ(Solution1().maxProfit(prices), max_profit);
    EXPECT_EQ(Solution2().maxProfit(prices), max_profit);
  }
}

/*
 * =====================================================================================
 *
 *       Filename:  coin_change.cpp
 *
 *    Description:  322. Coin Change. https://leetcode.com/problems/coin-change/
 *
 *        Version:  1.0
 *        Created:  04/03/23 10:26:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <climits>
#include <tuple>
#include <unordered_map>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace std;

// Dynamic programming, time limit exceeded
class Solution1 {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount < 0) {
      return -1;
    } else if (amount == 0) {
      return 0;
    }

    int res = INT_MAX;
    for (const int c : coins) {
      const int sub = coinChange(coins, amount - c);
      if (sub == -1) {
        continue;
      }
      res = std::min(res, sub + 1);
    }
    return (res == INT_MAX ? -1 : res);
  }
};

// Dynamic programming + hash table
class Solution2 {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount < 0) {
      return -1;
    } else if (amount == 0) {
      return 0;
    }

    auto it = nums_.find(amount);
    if (it != nums_.end()) {
      return it->second;
    }

    int res = INT_MAX;
    for (const int c : coins) {
      const int sub = coinChange(coins, amount - c);
      if (sub == -1) {
        continue;
      }
      res = std::min(res, sub + 1);
    }
    if (res == INT_MAX) {
      res = -1;
    }
    nums_[amount] = res;
    return res;
  }

 private:
  unordered_map<int, int> nums_;
};

TEST(Solution, coinChange) {
  vector<tuple<vector<int>, int, int>> cases = {
      std::make_tuple(vector<int>{1, 2, 5}, 11, 3),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution1().coinChange(std::get<0>(c), std::get<1>(c)), std::get<2>(c));
    EXPECT_EQ(Solution2().coinChange(std::get<0>(c), std::get<1>(c)), std::get<2>(c));
  }
}

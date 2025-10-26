/*
 * =====================================================================================
 *
 *       Filename:  house_robber.cpp
 *
 *    Description:  198. House Robber.
 *
 *        Version:  1.0
 *        Created:  03/28/19 11:46:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <utility>
#include <vector>

#include "gtest/gtest.h"

// Recursive
class Solution1 {
 public:
  int rob(const std::vector<int>& nums) {
    std::vector<int> amounts(nums.size(), -1);
    return rob(nums, nums.size() - 1, &amounts);
  }

 private:
  int rob(const std::vector<int>& nums, int idx, std::vector<int>* amounts) {
    if (idx < 0) {
      return 0;
    } else if (amounts->at(idx) != -1) {
      return amounts->at(idx);
    }

    int prev = rob(nums, idx - 1, amounts);
    int curr = nums[idx] + rob(nums, idx - 2, amounts);
    amounts->at(idx) = (prev > curr ? prev : curr);
    return amounts->at(idx);
  }
};

// Iterative
class Solution2 {
 public:
  int rob(const std::vector<int>& nums) {
    int adj = 0;
    int pre = 0;
    int cur = 0;
    for (const auto val : nums) {
      cur = std::max(val + pre, adj);
      pre = adj;
      adj = cur;
    }
    return cur;
  }
};

class Solution3 {
 public:
  int rob(std::vector<int>& nums) {
    std::vector<int> money(nums);
    int amount = 0;
    for (int i = 0; i < money.size(); i++) {
      if (i - 2 >= 0) {
        money[i] += money[i - 2];
      }
      if (i - 3 >= 0) {
        money[i] = std::max(money[i], money[i - 3] + nums[i]);
      }
      amount = std::max(amount, money[i]);
    }
    return amount;
  }
};

TEST(Solution, rob) {
  std::vector<std::pair<std::vector<int>, int>> cases = {
      {{1}, 1},
      {{1, 2}, 2},
      {{1, 2, 3, 1}, 4},
      {{2, 7, 9, 3, 1}, 12},
  };
  for (auto& [nums, amount] : cases) {
    EXPECT_EQ(Solution1().rob(nums), amount);
    EXPECT_EQ(Solution2().rob(nums), amount);
    EXPECT_EQ(Solution3().rob(nums), amount);
  }
}

/*
 * =====================================================================================
 *
 *       Filename:  race_car.cpp
 *
 *    Description:  818. Race Car
 *
 *        Version:  1.0
 *        Created:  11/19/2025 10:30:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Michael Zhu, xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <algorithm>
#include <map>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

// Time complexity: O(nlogn)
// Space complexity: O(logn)
class Solution {
 public:
  int racecar(int target) {
    std::map<int, int> dp;

    std::function<int(int)> race = [&](int t) -> int {
      auto it = dp.find(t);
      if (it != dp.end()) {
        return it->second;
      }

      int k = 1;
      while ((1 << k) - 1 < t) {
        k++;
      }

      // Case 1: exact hit
      int full = (1 << k) - 1;
      if (full == t) {
        dp[t] = k;
        return k;
      }

      // Case 2: overshoot
      int res = k + 1 + race(full - t);

      // Case 3: stop early
      int half = (1 << (k - 1)) - 1;
      for (int i = 0; i < k - 1; i++) {
        int back = (1 << i) - 1;
        int remain = t - (half - back);
        int j = race(remain);
        // (k - 1) * A, R, i * A, R + j * A
        res = std::min(res, (k - 1) + 1 + i + 1 + j);
      }

      dp[t] = res;
      return res;
    };

    return race(target);
  }
};

TEST(Solution, racecar) {
  std::vector<std::pair<int, int>> cases = {
      {3, 2},
      {6, 5},
      {10, 7},
  };
  for (auto [target, res] : cases) {
    EXPECT_EQ(Solution().racecar(target), res);
  }
}

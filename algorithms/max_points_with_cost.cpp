/*
 * =====================================================================================
 *
 *       Filename:  max_points_with_cost.cpp
 *
 *    Description:  1937. Maximum Number of Points with Cost
 *
 *        Version:  1.0
 *        Created:  11/04/2025 12:03:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <vector>

#include "gtest/gtest.h"

// Time complexity: O(m*n)
// Space complexity: O(n)
class Solution {
 public:
  long long maxPoints(std::vector<std::vector<int>>& points) {
    int m = points.size();
    int n = points[0].size();
    std::vector<long long> dp(n);
    long long num = 0;
    for (int i = 0; i < n; i++) {
      dp[i] = static_cast<long long>(points[0][i]);
      num = std::max(num, dp[i]);
    }

    std::vector<long long> left(n);
    std::vector<long long> right(n);
    for (int i = 1; i < m; i++) {
      // Caculate previous from left
      for (int k = 0; k < n; k++) {
        left[k] = dp[k];
        if (k > 0) {
          left[k] = std::max(left[k], left[k - 1] - 1);
        }
      }
      // Caculate previous from right
      for (int k = n - 1; k >= 0; k--) {
        right[k] = dp[k];
        if (k < n - 1) {
          right[k] = std::max(right[k], right[k + 1] - 1);
        }
      }
      for (int j = 0; j < n; j++) {
        dp[j] = std::max(left[j], right[j]) + points[i][j];
        num = std::max(num, dp[j]);
      }
    }
    return num;
  }
};

TEST(Solution, maxPoints) {
  std::vector<std::pair<std::vector<std::vector<int>>, long long>> cases = {
      {{{1, 2, 3}, {1, 5, 1}, {3, 1, 1}}, 9},
      {{{1, 5}, {2, 3}, {4, 2}}, 11},
  };
  for (auto& [points, num] : cases) {
    EXPECT_EQ(Solution().maxPoints(points), num);
  }
}

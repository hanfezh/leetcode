/*
 * =====================================================================================
 *
 *       Filename:  longest_increasing_path.cpp
 *
 *    Description:  329. Longest Increasing Path in a Matrix
 *
 *        Version:  1.0
 *        Created:  11/20/2025 11:26:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Michael Zhu, xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <algorithm>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    int res = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        res = std::max(res, dfs(matrix, i, j, dp));
      }
    }
    return res;
  }

 private:
  std::vector<std::pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  int dfs(const std::vector<std::vector<int>>& matrix, int i, int j,
          std::vector<std::vector<int>>& dp) {
    if (dp[i][j] != 0) {
      return dp[i][j];
    }

    int m = matrix.size();
    int n = matrix[0].size();
    int res = 1;

    for (auto [first, second] : moves) {
      int x = i + first;
      int y = j + second;
      if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) {
        continue;
      }
      res = std::max(res, 1 + dfs(matrix, x, y, dp));
    }

    dp[i][j] = res;
    return res;
  }
};

TEST(Solution, longestIncreasingPath) {
  std::vector<std::pair<std::vector<std::vector<int>>, int>> cases = {
      {{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}}, 4},
      {{{3, 4, 5}, {3, 2, 6}, {2, 2, 1}}, 4},
      {{{1}}, 1},
  };
  for (auto& [matrix, res] : cases) {
    EXPECT_EQ(Solution().longestIncreasingPath(matrix), res);
  }
}

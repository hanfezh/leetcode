/*
 * =====================================================================================
 *
 *       Filename:  maximal_square.cpp
 *
 *    Description:  221. Maximal Square
 *
 *        Version:  1.0
 *        Created:  12/20/2025 17:49:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Michael Zhu, xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <utility>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  int maximalSquare(std::vector<std::vector<char>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n));
    int res = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == '0') {
          continue;
        }

        int left = (j > 0) ? dp[i][j - 1] : 0;
        int up = (i > 0) ? dp[i - 1][j] : 0;
        int diagonal = (i > 0 && j > 0) ? dp[i - 1][j - 1] : 0;
        dp[i][j] = std::min({left, up, diagonal}) + 1;
        res = std::max(res, dp[i][j]);
      }
    }
    return res * res;
  }
};

TEST(Solution, maximalSquare) {
  std::vector<std::pair<std::vector<std::vector<char>>, int>> cases = {
      {{{'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}},
       4},
      {{{'0', '1'}, {'1', '0'}}, 1},
      {{{'0'}}, 0},
      {{{'1', '1', '1', '1', '0'},
        {'1', '1', '1', '1', '0'},
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'0', '0', '1', '1', '1'}},
       16},
  };
  for (auto& [matrix, res] : cases) {
    EXPECT_EQ(Solution().maximalSquare(matrix), res);
  }
}

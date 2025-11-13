/*
 * =====================================================================================
 *
 *       Filename:  filling_shelves.cpp
 *
 *    Description:  1105. Filling Bookcase Shelves
 *
 *        Version:  1.0
 *        Created:  11/13/2025 17:35:44
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

class Solution {
 public:
  int minHeightShelves(std::vector<std::vector<int>>& books, int shelf_width) {
    const int n = books.size();
    std::vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
      int total_width = 0;
      int max_height = 0;
      for (int j = i - 1; j >= 0; j--) {
        total_width += books[j][0];
        if (total_width > shelf_width) {
          break;
        }
        max_height = std::max(max_height, books[j][1]);
        dp[i] = std::min(dp[i], max_height + dp[j]);
      }
    }
    return dp[n];
  }
};

TEST(Solution, minHeightShelves) {
  std::vector<std::tuple<std::vector<std::vector<int>>, int, int>> cases = {
      {{{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}}, 4, 6},
      {{{1, 3}, {2, 4}, {3, 2}}, 6, 4},
  };
  for (auto& [books, shelf_width, res] : cases) {
    EXPECT_EQ(Solution().minHeightShelves(books, shelf_width), res);
  }
}

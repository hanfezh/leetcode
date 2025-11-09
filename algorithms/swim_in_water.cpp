/*
 * =====================================================================================
 *
 *       Filename:  swim_in_water.cpp
 *
 *    Description:  778. Swim in Rising Water
 *
 *        Version:  1.0
 *        Created:  11/09/2025 22:35:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <array>
#include <queue>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  struct Compare {
    bool operator()(const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) {
      return std::get<2>(a) > std::get<2>(b);
    }
  };

  int swimInWater(std::vector<std::vector<int>>& grid) {
    const int n = grid.size();
    if (n == 0 || grid[0].size() != n) {
      return 0;
    } else if (n == 1) {
      return grid[0][0];
    }

    const std::array<std::pair<int, int>, 4> moves{{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, Compare>
        min_heap;
    int tm = grid[0][0];
    min_heap.push({0, 0, grid[0][0]});
    visited[0][0] = true;
    while (!min_heap.empty()) {
      auto [a, b, c] = min_heap.top();
      min_heap.pop();
      tm = std::max(tm, c);
      for (auto [first, second] : moves) {
        int i = a + first;
        int j = b + second;
        if (i >= 0 && i < n && j >= 0 && j < n) {
          if (i == n - 1 && j == n - 1) {
            return std::max(tm, grid[i][j]);
          } else if (!visited[i][j]) {
            min_heap.push({i, j, grid[i][j]});
            visited[i][j] = true;
          }
        }
      }
    }
    return tm;
  }
};

TEST(Solution, swimInWater) {
  std::vector<std::pair<std::vector<std::vector<int>>, int>> cases = {
      {{{0, 2}, {1, 3}}, 3},
      {{{0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6}},
       16},
  };
  for (auto& [grid, tm] : cases) {
    EXPECT_EQ(Solution().swimInWater(grid), tm);
  }
}

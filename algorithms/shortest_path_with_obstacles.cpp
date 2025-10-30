/*
 * =====================================================================================
 *
 *       Filename:  shortest_path_with_obstacles.cpp
 *
 *    Description:  1293. Shortest Path in a Grid with Obstacles Elimination
 *
 *        Version:  1.0
 *        Created:  10/30/2025 22:57:10
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
#include <tuple>
#include <vector>

#include "gtest/gtest.h"

// Time complexity: O(m*n*k)
// Space complexity: O(m*n*k)
class Solution {
 public:
  int shortestPath(std::vector<std::vector<int>>& grid, int k) {
    if (grid.size() == 0 || grid[0].size() == 0) {
      return -1;
    }
    const int m = grid.size();
    const int n = grid[0].size();
    if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0) {
      return -1;
    }
    if (k >= m + n - 2) {
      return m + n - 2;
    }

    const std::array<std::pair<int, int>, 4> moves{{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};

    std::vector<std::vector<std::vector<bool>>> visited(
        m, std::vector<std::vector<bool>>(n, std::vector<bool>(k + 1, false)));
    std::queue<std::tuple<int, int, int>> q;
    int steps = 0;
    q.push({0, 0, k});
    visited[0][0][k] = true;
    while (!q.empty()) {
      int count = q.size();
      while (count-- > 0) {
        const auto [x, y, z] = q.front();
        if (x == m - 1 && y == n - 1) {
          return steps;
        }
        for (const auto [first, second] : moves) {
          int i = x + first;
          int j = y + second;
          if (i >= 0 && i < m && j >= 0 && j < n) {
            if (grid[i][j] == 0 && !visited[i][j][z]) {
              q.push({i, j, z});
              visited[i][j][z] = true;
            } else if (grid[i][j] == 1 && z > 0 && !visited[i][j][z - 1]) {
              q.push({i, j, z - 1});
              visited[i][j][z - 1] = true;
            }
          }
        }
        q.pop();
      }
      steps++;
    }
    return -1;
  }
};

TEST(Solution, shortestPath) {
  std::vector<std::tuple<std::vector<std::vector<int>>, int, int>> cases = {
      {{{0, 0, 0}, {1, 1, 0}, {0, 0, 0}, {0, 1, 1}, {0, 0, 0}}, 1, 6},
      {{{0, 1, 1}, {1, 1, 1}, {1, 0, 0}}, 1, -1},
  };
  for (auto& [grid, k, steps] : cases) {
    EXPECT_EQ(Solution().shortestPath(grid, k), steps);
  }
}

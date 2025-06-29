/*
 * =====================================================================================
 *
 *       Filename:  shortest_path.cpp
 *
 *    Description:  1091. Shortest Path in Binary Matrix
 *                  https://leetcode.com/problems/shortest-path-in-binary-matrix/
 *
 *        Version:  1.0
 *        Created:  06/29/2025 22:56:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.comclass Solution {
 *   Organization:
 *
 * =====================================================================================
 */

#include <queue>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) {
    const int visited = -1;
    const int n = grid.size();
    if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
      return -1;
    }

    const std::vector<std::pair<int, int>> moves{{1, 1},  {0, 1},  {1, 0},  {-1, 1},
                                                 {1, -1}, {0, -1}, {-1, 0}, {-1, -1}};
    std::queue<std::pair<int, int>> q;
    int levels = 0;
    int count = 0;

    q.push({0, 0});
    grid[0][0] = visited;
    while (!q.empty()) {
      levels++;
      count = q.size();
      while (count-- > 0) {
        auto [i, j] = q.front();
        if (i == n - 1 && j == n - 1) {
          return levels;
        }

        q.pop();
        for (auto [x, y] : moves) {
          x += i;
          y += j;
          if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 0) {
            continue;
          }
          q.push({x, y});
          grid[x][y] = visited;
        }
      }
    }

    return -1;
  }
};

TEST(Solution, shortestPathBinaryMatrix) {
  std::vector<std::pair<std::vector<std::vector<int>>, int>> cases = {
      {{{0, 1}, {1, 0}}, 2},
      {{{0, 0, 0}, {1, 1, 0}, {1, 1, 0}}, 4},
      {{{1, 0, 0}, {1, 1, 0}, {1, 1, 0}}, -1},
  };
  for (auto& [grid, dist] : cases) {
    EXPECT_EQ(Solution().shortestPathBinaryMatrix(grid), dist);
  }
}

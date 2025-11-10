/*
 * =====================================================================================
 *
 *       Filename:  max_detonation.cpp
 *
 *    Description:  2101. Detonate the Maximum Bombs
 *
 *        Version:  1.0
 *        Created:  11/10/2025 14:42:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <bitset>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  int dfs(int i, std::vector<std::vector<int>>& g, std::bitset<100>& detonated) {
    if (!detonated[i]) {
      detonated[i] = true;
      for (auto j : g[i]) {
        dfs(j, g, detonated);
      }
    }
    return detonated.count();
  }

  int maximumDetonation(std::vector<std::vector<int>>& bombs) {
    const int n = bombs.size();
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n; i++) {
      long long a = bombs[i][0], b = bombs[i][1], c = (long long)bombs[i][2] * bombs[i][2];
      for (int j = 0; j < n; j++) {
        if (j == i) {
          continue;
        }
        int x = bombs[j][0], y = bombs[j][1];
        if ((a - x) * (a - x) + (b - y) * (b - y) <= c) {
          g[i].push_back(j);
        }
      }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
      std::bitset<100> detonated;
      res = std::max(res, dfs(i, g, detonated));
    }
    return res;
  }
};

TEST(Solution, maximumDetonation) {
  std::vector<std::pair<std::vector<std::vector<int>>, int>> cases = {
      {{{2, 1, 3}, {6, 1, 4}}, 2},
      {{{1, 1, 5}, {10, 10, 5}}, 1},
      {{{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}}, 5},
  };
  for (auto& [bombs, res] : cases) {
    EXPECT_EQ(Solution().maximumDetonation(bombs), res);
  }
}

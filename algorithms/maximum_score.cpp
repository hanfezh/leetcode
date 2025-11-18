/*
 * =====================================================================================
 *
 *       Filename:  maximum_score.cpp
 *
 *    Description:  2242. Maximum Score of a Node Sequence
 *
 *        Version:  1.0
 *        Created:  11/18/2025 10:16:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <algorithm>
#include <tuple>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  int maximumScore(std::vector<int>& scores, std::vector<std::vector<int>>& edges) {
    const int n = scores.size();
    std::vector<std::vector<int>> neighbours(n);
    for (auto e : edges) {
      neighbours[e[0]].push_back(e[1]);
      neighbours[e[1]].push_back(e[0]);
    }

    // Sort by descending order, O(nlog(n))
    for (auto& nei : neighbours) {
      std::sort(nei.begin(), nei.end(),
                [&](const int i, const int j) -> bool { return scores[i] > scores[j]; });
    }

    int res = -1;

    // Walk through every edge
    for (auto& e : edges) {
      int l = e[0];
      int r = e[1];

      int base = scores[l] + scores[r];
      for (int i = 0; i < std::min(3, (int)neighbours[l].size()); i++) {
        int x = neighbours[l][i];
        if (x == r) {
          continue;
        }

        for (int j = 0; j < std::min(3, (int)neighbours[r].size()); j++) {
          int y = neighbours[r][j];
          if (y == l || y == x) {
            continue;
          }

          res = std::max(res, base + scores[x] + scores[y]);
        }
      }
    }

    return res;
  }
};

TEST(Solution, maximumScore) {
  std::vector<std::tuple<std::vector<int>, std::vector<std::vector<int>>, int>> cases = {
      {{5, 2, 9, 8, 4}, {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}}, 24},
  };
  for (auto& [scores, edges, res] : cases) {
    EXPECT_EQ(Solution().maximumScore(scores, edges), res);
  }
}

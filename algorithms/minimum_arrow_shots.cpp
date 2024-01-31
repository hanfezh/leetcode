/*
 * =====================================================================================
 *
 *       Filename:  minimum_arrow_shots.cpp
 *
 *    Description:  452. Minimum Number of Arrows to Burst Balloons
 *
 *        Version:  1.0
 *        Created:  01/31/2024 09:56:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <algorithm>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::vector;

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() == 0) {
      return 0;
    }

    std::sort(points.begin(), points.end(),
              [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

    int arrows = 1;
    int a = INT_MIN;
    int b = INT_MAX;
    for (const auto& p : points) {
      a = std::max(a, p[0]);
      b = std::min(b, p[1]);
      if (a > b) {
        arrows++;
        a = p[0];
        b = p[1];
      }
    }

    return arrows;
  }
};

TEST(Solution, findMinArrowShots) {
  vector<std::pair<vector<vector<int>>, int>> cases = {
      std::make_pair(vector<vector<int>>{{10, 16}, {2, 8}, {1, 6}, {7, 12}}, 2),
      std::make_pair(vector<vector<int>>{{1, 2}, {3, 4}, {5, 6}, {7, 8}}, 4),
      std::make_pair(vector<vector<int>>{{1, 2}, {2, 3}, {3, 4}, {4, 5}}, 2),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().findMinArrowShots(c.first), c.second);
  }
}

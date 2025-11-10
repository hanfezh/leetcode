/*
 * =====================================================================================
 *
 *       Filename:  min_time_difference.cpp
 *
 *    Description:  539. Minimum Time Difference
 *
 *        Version:  1.0
 *        Created:  11/10/2025 08:47:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <string>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  int findMinDifference(std::vector<std::string>& points) {
    if (points.size() < 2) {
      return 0;
    }

    auto convert = [](const std::string& s) -> int {
      const int n = s.length();
      if (n == 0 || n != 5 || s[2] != ':') {
        return 0;  // Invalid format
      }
      const int h = std::stoi(s.substr(0, 2));
      const int m = std::stoi(s.substr(3, 2));
      return (h * 60 + m);
    };

    std::vector<int> minutes(points.size());
    for (int i = 0; i < points.size(); i++) {
      minutes[i] = convert(points[i]);
    }
    std::sort(minutes.begin(), minutes.end());

    int diff = minutes.front() + 24 * 60 - minutes.back();
    for (int i = 1; i < minutes.size(); i++) {
      diff = std::min(diff, minutes[i] - minutes[i - 1]);
    }
    return diff;
  }
};

TEST(Solution, findMinDifference) {
  std::vector<std::pair<std::vector<std::string>, int>> cases = {
      {{"23:59", "00:00"}, 1},
      {{"00:00", "23:59", "00:00"}, 0},
  };
  for (auto [points, diff] : cases) {
    EXPECT_EQ(Solution().findMinDifference(points), diff);
  }
}

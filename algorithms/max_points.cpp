// 149. Max Points on a Line: https://leetcode.com/problems/max-points-on-a-line
// Author: xianfeng.zhu@gmail.com

#include <map>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::vector;

class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    int max_num = 0;

    for (int i = 0; i < points.size(); i++) {
      std::map<std::pair<int, int>, int> nums;
      int dup_num = 1;

      for (int j = i + 1; j < points.size(); j++) {
        if (points[i] == points[j]) {
          dup_num += 1;
          continue;
        }

        int dx = points[j][0] - points[i][0];
        int dy = points[j][1] - points[i][1];
        int dz = gcd(dx, dy);
        nums[std::make_pair(dx / dz, dy / dz)] += 1;
      }

      max_num = std::max(max_num, dup_num);
      for (const auto& item : nums) {
        max_num = std::max(item.second + dup_num, max_num);
      }
    }

    return max_num;
  }

 private:
  int gcd(int a, int b) { return ((b == 0) ? a : gcd(b, a % b)); }
};

TEST(Solution, maxPoints) {
  vector<std::pair<vector<vector<int>>, int>> cases = {
      std::make_pair(vector<vector<int>>{{1, 1}, {2, 2}, {3, 3}}, 3),
      std::make_pair(vector<vector<int>>{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}}, 4),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().maxPoints(c.first), c.second);
  }
}

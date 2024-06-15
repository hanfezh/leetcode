/*
 * =====================================================================================
 *
 *       Filename:  third_maximum_number.cpp
 *
 *    Description:  414. Third Maximum Number
 *                  https://leetcode.com/problems/third-maximum-number/
 *
 *        Version:  1.0
 *        Created:  06/15/2024 09:43:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <set>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::vector;

class Solution {
 public:
  int thirdMax(vector<int>& nums) {
    std::set<int> s;
    for (const int n : nums) {
      s.insert(n);
    }
    if (s.size() > 2) {
      s.erase(*s.rbegin());
      s.erase(*s.rbegin());
    }
    return *s.rbegin();
  }
};

TEST(Solution, thirdMax) {
  vector<std::pair<vector<int>, int>> cases = {std::make_pair(vector<int>{3, 2, 1}, 1),
                                               std::make_pair(vector<int>{1, 2}, 2),
                                               std::make_pair(vector<int>{2, 2, 3, 1}, 1)};
  for (auto& c : cases) {
    EXPECT_EQ(Solution().thirdMax(c.first), c.second);
  }
}

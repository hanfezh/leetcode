/*
 * =====================================================================================
 *
 *       Filename:  find_lhs.cpp
 *
 *    Description:  594. Longest Harmonious Subsequence.
 *                  https://leetcode.com/problems/longest-harmonious-subsequence/
 *
 *        Version:  1.0
 *        Created:  02/03/2023 17:38:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <unordered_map>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::unordered_map;
using std::vector;

// Hash table
class Solution {
 public:
  int findLHS(vector<int>& nums) {
    unordered_map<int, int> counts;
    for (const int n : nums) {
      counts[n] += 1;
    }

    int len = 0;
    for (const int n : nums) {
      const auto it = counts.find(n - 1);
      if (it != counts.end()) {
        len = std::max(len, it->second + counts[n]);
      }
    }
    return len;
  }
};

TEST(Solution, findLHS) {
  vector<std::pair<vector<int>, int>> cases = {
      std::make_pair(vector<int>{1, 2, 3, 4}, 2),
      std::make_pair(vector<int>{1, 1, 1, 1}, 0),
      std::make_pair(vector<int>{1, 3, 2, 2, 5, 2, 3, 7}, 5),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().findLHS(c.first), c.second);
  }
}

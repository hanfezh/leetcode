/*
 * =====================================================================================
 *
 *       Filename:  count_partitions.cpp
 *
 *    Description:  3432. Count Partitions with Even Sum Difference
 *                  https://leetcode.com/problems/count-partitions-with-even-sum-difference/
 *
 *        Version:  1.0
 *        Created:  01/26/2025 23:42:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::pair;
using std::vector;

class Solution {
 public:
  int countPartitions(vector<int>& nums) {
    int odd = 0;
    for (const auto& val : nums) {
      odd ^= val & 0x1;
    }
    if (odd || nums.size() == 0) {
      return 0;
    }
    return nums.size() - 1;
  }
};

TEST(Solution, countPartitions) {
  vector<pair<vector<int>, int>> cases = {
      std::make_pair(vector<int>{10, 10, 3, 7, 6}, 4),
      std::make_pair(vector<int>{1, 2, 2}, 0),
      std::make_pair(vector<int>{2, 4, 6, 8}, 3),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().countPartitions(c.first), c.second);
  }
}

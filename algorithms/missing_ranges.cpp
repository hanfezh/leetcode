/*
 * =====================================================================================
 *
 *       Filename:  missing_ranges.cpp
 *
 *    Description:  163. Missing Ranges. https://leetcode.com/problems/missing-ranges/
 *
 *        Version:  1.0
 *        Created:  06/29/2024 18:19:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::tuple;
using std::vector;

class Solution {
 public:
  vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
    if (nums.size() == 0) {
      return vector<vector<int>>{{lower, upper}};
    }
    vector<vector<int>> ranges;
    if (nums.front() - lower) {
      ranges.emplace_back(vector<int>{lower, nums.front() - 1});
    }
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] - nums[i - 1] > 1) {
        ranges.emplace_back(vector<int>{nums[i - 1] + 1, nums[i] - 1});
      }
    }
    if (nums.back() < upper) {
      ranges.emplace_back(vector<int>{nums.back() + 1, upper});
    }
    return ranges;
  }
};

TEST(Solution, findMissingRanges) {
  vector<tuple<vector<int>, int, int, vector<vector<int>>>> cases = {
      std::make_tuple(vector<int>{}, 1, 1, vector<vector<int>>{{1, 1}}),
      std::make_tuple(vector<int>{0, 1, 3, 50, 75}, 0, 99,
                      vector<vector<int>>{{2, 2}, {4, 49}, {51, 74}, {76, 99}}),
      std::make_tuple(vector<int>{-1}, -1, -1, vector<vector<int>>{}),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().findMissingRanges(std::get<0>(c), std::get<1>(c), std::get<2>(c)),
              std::get<3>(c));
  }
}

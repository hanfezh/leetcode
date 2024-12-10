/*
 * =====================================================================================
 *
 *       Filename:  special_array1.cpp
 *
 *    Description:  3151. Special Array I
 *                  https://leetcode.com/problems/special-array-i/
 *
 *        Version:  1.0
 *        Created:  12/10/2024 22:41:28
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

using std::vector;

class Solution {
 public:
  bool isArraySpecial(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
      if ((nums[i - 1] & 0x01) ^ (nums[i] & 0x01) ^ 0x01) {
        return false;
      }
    }
    return true;
  }
};

TEST(Solution, isArraySpecial) {
  vector<std::pair<vector<int>, bool>> cases = {
      std::make_pair(vector<int>{1}, true),
      std::make_pair(vector<int>{2, 1, 4}, true),
      std::make_pair(vector<int>{4, 3, 1, 6}, false),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().isArraySpecial(std::get<0>(c)), std::get<1>(c));
  }
}

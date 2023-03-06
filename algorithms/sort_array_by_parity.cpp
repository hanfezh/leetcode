/*
 * =====================================================================================
 *
 *       Filename:  sort_array_by_parity.cpp
 *
 *    Description:  905. Sort Array By Parity.
 *                  https://leetcode.com/problems/sort-array-by-parity/
 *
 *        Version:  1.0
 *        Created:  03/06/23 08:27:50
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

// Two pointers
class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    auto is_odd = [](const int n) { return (n % 2 == 1); };

    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      if (!is_odd(nums[l])) {
        l++;
      } else if (is_odd(nums[r])) {
        r--;
      } else {
        std::swap(nums[l], nums[r]);
      }
    }
    return nums;
  }
};

TEST(Solution, sortArrayByParityII) {
  auto verify = [](const vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (nums[r] % 2 == 1) {
      r--;
    }
    while (l <= r) {
      EXPECT_EQ(nums[l++] % 2, 0);
    }
  };
  vector<vector<int>> cases = {vector<int>{0}, vector<int>{2, 3},
                               vector<int>{4, 2, 5, 7},
                               vector<int>{2, 3, 1, 1, 4, 0, 0, 4, 3, 3}};
  for (auto& c : cases) {
    verify(Solution().sortArrayByParity(c));
  }
}

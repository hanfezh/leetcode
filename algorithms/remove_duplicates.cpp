/*
 * =====================================================================================
 *
 *       Filename:  remove_duplicates.cpp
 *
 *    Description:  26. Remove Duplicates from Sorted Array
 *                  https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *
 *        Version:  1.0
 *        Created:  03/08/23 10:18:51
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

// Two pointers, time O(N), space O(1)
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != nums[j]) {
        nums[++j] = nums[i];
      }
    }
    return (j + 1);
  }
};

TEST(Solution, removeDuplicates) {
  vector<std::pair<vector<int>, int>> cases = {
      std::make_pair(vector<int>{1, 1, 2}, 2),
      std::make_pair(vector<int>{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, 5),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().removeDuplicates(c.first), c.second);
  }
}

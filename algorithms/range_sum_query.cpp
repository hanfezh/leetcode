/*
 * =====================================================================================
 *
 *       Filename:  range_sum_query.cpp
 *
 *    Description:  303. Range Sum Query - Immutable.
 *                  https://leetcode.com/problems/range-sum-query-immutable/
 *
 *        Version:  1.0
 *        Created:  02/26/23 13:28:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::vector;

class NumArray {
 public:
  NumArray(vector<int>& nums) : sums(nums) {
    for (int i = 1; i < sums.size(); i++) {
      sums[i] += sums[i - 1];
    }
  }

  int sumRange(int left, int right) {
    if (left == 0) {
      return sums[right];
    } else {
      return (sums[right] - sums[left - 1]);
    }
  }

 private:
  vector<int> sums;
};

TEST(Solution, sumRange) {
  vector<int> nums = {-2, 0, 3, -5, 2, -1};
  NumArray numArray(nums);
  EXPECT_EQ(numArray.sumRange(0, 2), 1);
  EXPECT_EQ(numArray.sumRange(2, 5), -1);
  EXPECT_EQ(numArray.sumRange(0, 5), -3);
}

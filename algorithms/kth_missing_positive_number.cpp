/*
 * =====================================================================================
 *
 *       Filename:  kth_missing_positive_number.cpp
 *
 *    Description:  1539. Kth Missing Positive Number.
 *                  https://leetcode.com/problems/kth-missing-positive-number/
 *        Version:  1.0
 *        Created:  03/06/23 08:52:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <tuple>
#include <unordered_set>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::unordered_set;
using std::vector;

// Hash table
class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    unordered_set<int> nums(arr.begin(), arr.end());
    const int n = arr.size() + k + 1;
    int i = 1;
    for (; i < n; i++) {
      if (nums.count(i) == 0) {
        k--;
      }
      if (k <= 0) {
        break;
      }
    }
    return i;
  }
};

TEST(Solution, findKthPositive) {
  vector<std::tuple<vector<int>, int, int>> cases = {
      // std::make_tuple(vector<int>{1, 2, 3, 4}, 2, 6),
      std::make_tuple(vector<int>{2, 3, 4, 7, 11}, 5, 9),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().findKthPositive(std::get<0>(c), std::get<1>(c)),
              std::get<2>(c));
  }
}

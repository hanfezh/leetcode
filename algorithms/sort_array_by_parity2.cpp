/*
 * =====================================================================================
 *
 *       Filename:  sort_array_by_parity2.cpp
 *
 *    Description:  922. Sort Array By Parity II
 *                  https://leetcode.com/problems/sort-array-by-parity-ii/
 *
 *        Version:  1.0
 *        Created:  03/04/23 17:43:42
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

// Extra spaces
class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& nums) {
    auto is_odd = [](const int n) { return (n % 2 == 1); };

    vector<int> ans(nums.size());
    int i = 0;
    int j = 1;
    for (const int n : nums) {
      if (!is_odd(n)) {
        ans[i] = n;
        i += 2;
      } else {
        ans[j] = n;
        j += 2;
      }
    }
    return ans;
  }
};

TEST(Solution, sortArrayByParityII) {
  auto verify = [](const vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      EXPECT_EQ((i ^ nums[i]) % 2, 0);
    }
  };
  vector<vector<int>> cases = {vector<int>{2, 3}, vector<int>{4, 2, 5, 7},
                               vector<int>{2, 3, 1, 1, 4, 0, 0, 4, 3, 3}};
  for (auto& c : cases) {
    verify(Solution().sortArrayByParityII(c));
  }
}

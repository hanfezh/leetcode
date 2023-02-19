/*
 * =====================================================================================
 *
 *       Filename:  product_except_self.cpp
 *
 *    Description:  238. Product of Array Except Self.
 *                  https://leetcode.com/problems/product-of-array-except-self/
 *
 *        Version:  1.0
 *        Created:  02/19/2023 15:57:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <initializer_list>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::initializer_list;
using std::vector;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> prods(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++) {
      prods[i] = prods[i - 1] * nums[i - 1];
    }
    for (int i = nums.size() - 1, suffix = 1; i >= 0; i--) {
      prods[i] *= suffix;
      suffix *= nums[i];
    }
    return prods;
  }
};

TEST(Solution, productExceptSelf) {
  vector<std::pair<vector<int>, initializer_list<int>>> cases = {
      std::make_pair(vector<int>{1, 2, 3, 4}, initializer_list<int>{24, 12, 8, 6}),
      std::make_pair(vector<int>{-1, 1, 0, -3, 3}, initializer_list<int>{0, 0, 9, 0, 0}),
  };
  for (auto& c : cases) {
    EXPECT_THAT(Solution().productExceptSelf(c.first), testing::ElementsAreArray(c.second));
  }
}

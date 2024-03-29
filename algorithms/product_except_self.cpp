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
#include <functional>
#include <initializer_list>
#include <numeric>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::initializer_list;
using std::vector;

class Solution1 {
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

class Solution2 {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> prods(nums.size());
    vector<int> pres(nums.size(), 1);
    vector<int> sufs(nums.size(), 1);
    for (size_t i = 1; i < nums.size(); i++) {
      pres[i] = pres[i - 1] * nums[i - 1];
    }
    for (int i = nums.size() - 2; i >= 0; i--) {
      sufs[i] = sufs[i + 1] * nums[i + 1];
    }
    for (size_t i = 0; i < nums.size(); i++) {
      prods[i] = pres[i] * sufs[i];
    }
    return prods;
  }
};

class Solution3 {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> prods(nums.size());
    vector<int> pres(nums.size(), 1);
    vector<int> sufs(nums.size(), 1);
    std::partial_sum(nums.begin(), nums.end(), pres.begin(),
                     std::multiplies<int>());
    std::partial_sum(nums.rbegin(), nums.rend(), sufs.rbegin(),
                     std::multiplies<int>());
    for (size_t i = 0; i < nums.size(); i++) {
      prods[i] =
          (i > 0 ? pres[i - 1] : 1) * (i < nums.size() - 1 ? sufs[i + 1] : 1);
    }
    return prods;
  }
};

TEST(Solution, productExceptSelf) {
  vector<std::pair<vector<int>, initializer_list<int>>> cases = {
      std::make_pair(vector<int>{1, 2, 3, 4},
                     initializer_list<int>{24, 12, 8, 6}),
      std::make_pair(vector<int>{-1, 1, 0, -3, 3},
                     initializer_list<int>{0, 0, 9, 0, 0}),
  };
  for (auto& c : cases) {
    EXPECT_THAT(Solution1().productExceptSelf(c.first),
                testing::ElementsAreArray(c.second));
    EXPECT_THAT(Solution2().productExceptSelf(c.first),
                testing::ElementsAreArray(c.second));
    EXPECT_THAT(Solution3().productExceptSelf(c.first),
                testing::ElementsAreArray(c.second));
  }
}

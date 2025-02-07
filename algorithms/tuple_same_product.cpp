/*
 * =====================================================================================
 *
 *       Filename:  tuple_same_product.cpp
 *
 *    Description:  1726. Tuple with Same Product
 *                  https://leetcode.com/problems/tuple-with-same-product/
 *
 *        Version:  1.0
 *        Created:  02/07/2025 22:46:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <unordered_map>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::pair;
using std::unordered_map;
using std::vector;

class Solution {
 public:
  int tupleSameProduct(vector<int>& nums) {
    unordered_map<int, int> product_counts;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        product_counts[nums[i] * nums[j]] += 1;
      }
    }
    int sum = 0;
    for (const auto& [_, val] : product_counts) {
      sum += 8 * val * (val - 1) / 2;
    }
    return sum;
  }
};

TEST(Solution, tupleSameProduct) {
  vector<pair<vector<int>, int>> cases = {
      std::make_pair(vector<int>{2, 3, 4, 6}, 8),
      std::make_pair(vector<int>{1, 2, 4, 5, 10}, 16),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().tupleSameProduct(c.first), c.second);
  }
}

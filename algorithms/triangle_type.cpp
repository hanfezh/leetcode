/*
 * =====================================================================================
 *
 *       Filename:  triangle_type.cpp
 *
 *    Description:  3024. Type of Triangle
 *                  https://leetcode.com/problems/type-of-triangle/
 *
 *        Version:  1.0
 *        Created:  05/19/2025 10:32:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <algorithm>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

// std::unordered_set
class Solution1 {
 public:
  std::string triangleType(std::vector<int>& nums) {
    int a = nums[0], b = nums[1], c = nums[2];
    if (a > b) {
      std::swap(a, b);
    }
    if (b > c) {
      std::swap(b, c);
    }
    if (a + b <= c) {  // c is the max
      return "none";
    }

    std::unordered_set<int> lens(nums.begin(), nums.end());
    switch (lens.size()) {
      case 1:
        return "equilateral";
      case 2:
        return "isosceles";
      default:
        return "scalene";
    }
  }
};

// std::sort
class Solution2 {
 public:
  std::string triangleType(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int a = nums[0], b = nums[1], c = nums[2];
    if (a + b <= c) {
      return "none";
    } else if (a == c) {
      return "equilateral";
    } else if (a == b || b == c) {
      return "isosceles";
    } else {
      return "scalene";
    }
  }
};

TEST(Solution, triangleType) {
  std::vector<std::pair<std::vector<int>, std::string>> cases = {
      std::make_pair(std::vector<int>{3, 3, 3}, "equilateral"),
      std::make_pair(std::vector<int>{1, 3, 3}, "isosceles"),
      std::make_pair(std::vector<int>{2, 3, 4}, "scalene"),
      std::make_pair(std::vector<int>{1, 2, 3}, "none"),
      std::make_pair(std::vector<int>{2, 4, 8}, "none"),
  };
  for (auto& [nums, type] : cases) {
    EXPECT_EQ(Solution1().triangleType(nums), type);
    EXPECT_EQ(Solution2().triangleType(nums), type);
  }
}

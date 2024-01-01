/*
 * =====================================================================================
 *
 *       Filename:  maximum_swap.cpp
 *
 *    Description:  670. Maximum Swap. https://leetcode.com/problems/maximum-swap/
 *
 *        Version:  1.0
 *        Created:  12/31/2023 23:37:29
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
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::string;
using std::vector;

class Solution {
 public:
  int maximumSwap(int num) {
    string digits = std::to_string(num);
    int buckets[10] = {0};
    for (int i = 0; i < digits.length(); i++) {
      buckets[digits[i] - '0'] = i;
    }
    for (int i = 0; i < digits.length(); i++) {
      for (int j = 9; j > digits[i] - '0'; j--) {
        if (buckets[j] > i) {
          std::swap(digits[i], digits[buckets[j]]);
          return std::stoi(digits);
        }
      }
    }
    return num;
  }
};

TEST(Solution, calculate) {
  vector<std::pair<int, int>> cases = {
      std::make_pair(2736, 7236),
      std::make_pair(9973, 9973),
  };
  for (const auto& c : cases) {
    EXPECT_EQ(Solution().maximumSwap(c.first), c.second);
  }
}

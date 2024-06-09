/*
 * =====================================================================================
 *
 *       Filename:  armstrong_number.cpp
 *
 *    Description:  1134. Armstrong Number
 *
 *        Version:  1.0
 *        Created:  06/09/2024 10:32:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <cmath>
#include <initializer_list>
#include <utility>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::initializer_list;
using std::pair;

class Solution {
 public:
  bool isArmstrong(int n) {
    int m = n;
    int k = 0;
    while (m > 0) {
      k++;
      m /= 10;
    }

    int sum = 0;
    m = n;
    while (m > 0) {
      sum += std::pow(m % 10, k);
      if (sum > n) {
        return false;
      }
      m /= 10;
    }
    return (sum == n);
  }
};

TEST(Solution, isArmstrong) {
  initializer_list<pair<int, bool>> cases = {
      std::make_pair(153, true),
      std::make_pair(123, false),
  };
  for (const auto& c : cases) {
    EXPECT_EQ(Solution().isArmstrong(c.first), c.second);
  }
}

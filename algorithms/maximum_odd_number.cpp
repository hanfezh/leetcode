/*
 * =====================================================================================
 *
 *       Filename:  maximum_odd_number.cpp
 *
 *    Description:  2864. Maximum Odd Binary Number
 *
 *        Version:  1.0
 *        Created:  07/21/2024 15:59:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <string>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::pair;
using std::string;
using std::vector;

class Solution {
 public:
  string maximumOddBinaryNumber(string s) {
    string odd(s.size() + 1, '0');
    int l = 0;
    int r = s.size();
    for (const char c : s) {
      if (c == '1') {
        odd[l++] = c;
      } else {
        odd[r--] = c;
      }
    }
    std::swap(odd[0], odd[s.size()]);
    return odd.substr(1);
  }
};

TEST(Solution, maximumOddBinaryNumber) {
  vector<pair<string, string>> cases = {
      std::make_pair("010", "001"),
      std::make_pair("0101", "1001"),
  };
  for (auto& s : cases) {
    EXPECT_EQ(Solution().maximumOddBinaryNumber(s.first), s.second);
  }
}

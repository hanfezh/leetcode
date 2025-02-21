/*
 * =====================================================================================
 *
 *       Filename:  add_binary.cpp
 *
 *    Description:  Add Binary. Given two binary strings, return their sum.
 *
 *        Version:  1.0
 *        Created:  02/15/19 08:07:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <string>
#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Solution1 {
 public:
  std::string addBinary(const std::string& a, const std::string& b) {
    std::string c;
    auto iter1 = a.rbegin();
    auto iter2 = b.rbegin();
    int over = 0;
    while (iter1 != a.rend() || iter2 != b.rend()) {
      int sum = over;
      if (iter1 != a.rend()) {
        sum += *iter1 - '0';
        iter1++;
      }
      if (iter2 != b.rend()) {
        sum += *iter2 - '0';
        iter2++;
      }
      c.insert(0, 1, (sum & 0x01) + '0');
      over = sum / 2;
    }

    if (over != 0) {
      c.insert(0, 1, '1');
    }
    return c;
  }
};

class Solution2 {
 public:
  std::string addBinary(const std::string& a, const std::string& b) {
    const int len = std::max(a.length(), b.length()) + 1;
    std::string c(len, '0');
    auto iter1 = a.rbegin();
    auto iter2 = b.rbegin();
    auto iter3 = c.rbegin();
    int over = 0;
    while (iter1 != a.rend() || iter2 != b.rend()) {
      int sum = over;
      if (iter1 != a.rend()) {
        sum += *iter1 - '0';
        iter1++;
      }
      if (iter2 != b.rend()) {
        sum += *iter2 - '0';
        iter2++;
      }
      *iter3 = (sum & 0x01) + '0';
      over = (sum & 0x02) >> 1;
      iter3++;
    }
    if (over != 0) {
      *iter3 = '1';
    }
    const auto pos = c.find('1');
    if (pos != std::string::npos) {
      return c.substr(pos);
    }
    return "0";
  }
};

TEST(Solution, addBinary) {
  std::vector<std::tuple<std::string, std::string, std::string>> cases = {
      std::make_tuple(std::string("11"), std::string("1"), std::string("100")),
      std::make_tuple(std::string("1010"), std::string("1011"), std::string("10101")),
      std::make_tuple(std::string("0"), std::string("0"), std::string("0")),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution1().addBinary(std::get<0>(c), std::get<1>(c)), std::get<2>(c));
    EXPECT_EQ(Solution2().addBinary(std::get<0>(c), std::get<1>(c)), std::get<2>(c));
  }
}

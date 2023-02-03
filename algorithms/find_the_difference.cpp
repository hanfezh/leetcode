/*
 * =====================================================================================
 *
 *       Filename:  find_the_difference.cpp
 *
 *    Description:  389. Find the Difference.
 *                  https://leetcode.com/problems/find-the-difference/
 *
 *        Version:  1.0
 *        Created:  02/03/2023 12:01:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <array>
#include <string>
#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::array;
using std::string;
using std::tuple;
using std::vector;

// Hash table
class Solution1 {
 public:
  char findTheDifference(string s, string t) {
    array<int, 26> counts = {0};
    for (char c : s) {
      counts[c - 'a'] += 1;
    }
    for (char c : t) {
      counts[c - 'a'] -= 1;
      if (counts[c - 'a'] < 0) {
        return c;
      }
    }
    return ' ';
  }
};

// Bit manipulation
class Solution2 {
 public:
  char findTheDifference(string s, string t) {
    char c = 0;
    for (int i = 0; i < s.size(); i++) {
      c ^= s[i] ^ t[i];
    }
    return c ^= t[t.size() - 1];
  }
};

TEST(Solution, findTheDifference) {
  vector<tuple<string, string, char>> cases = {
      std::make_tuple(string("abcd"), string("abcde"), 'e'),
      std::make_tuple(string(""), string("y"), 'y'),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution1().findTheDifference(std::get<0>(c), std::get<1>(c)), std::get<2>(c));
    EXPECT_EQ(Solution2().findTheDifference(std::get<0>(c), std::get<1>(c)), std::get<2>(c));
  }
}

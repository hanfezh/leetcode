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

class Solution {
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

TEST(Solution, findTheDifference) {
  vector<tuple<string, string, char>> cases = {
      std::make_tuple(string("abcd"), string("abcde"), 'e'),
      std::make_tuple(string(""), string("y"), 'y'),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().findTheDifference(std::get<0>(c), std::get<1>(c)), std::get<2>(c));
  }
}

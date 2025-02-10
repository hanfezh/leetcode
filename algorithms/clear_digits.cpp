/*
 * =====================================================================================
 *
 *       Filename:  clear_digits.cpp
 *
 *    Description:  3174. Clear Digits. https://leetcode.com/problems/clear-digits/
 *
 *        Version:  1.0
 *        Created:  02/10/2025 13:29:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <cctype>
#include <deque>
#include <string>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::deque;
using std::pair;
using std::string;
using std::vector;

class Solution {
 public:
  string clearDigits(string s) {
    deque<char> q;
    for (const char& c : s) {
      if (std::isdigit(c) && q.size() > 0) {
        q.pop_back();
      } else {
        q.push_back(c);
      }
    }
    int i = 0;
    s.resize(q.size());
    while (!q.empty()) {
      s[i++] = q.front();
      q.pop_front();
    }
    return s;
  }
};

TEST(Solution, clearDigits) {
  vector<pair<string, string>> cases = {
      std::make_pair("abc", "abc"),
      std::make_pair("cb34", ""),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().clearDigits(c.first), c.second);
  }
}

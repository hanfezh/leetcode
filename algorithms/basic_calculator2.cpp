/*
 * =====================================================================================
 *
 *       Filename:  basic_calculator2.cpp
 *
 *    Description:  227. Basic Calculator II.
 *                  https://leetcode.com/problems/basic-calculator-ii/
 *
 *        Version:  1.0
 *        Created:  12/30/2023 20:38:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cctype>
#include <cwctype>
#include <stack>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::stack;
using std::string;
using std::vector;

class Solution {
 public:
  int calculate(string s) {
    stack<int> st;
    int cur = 0;
    char opt = '+';
    for (int i = 0; i < s.length(); i++) {
      const char c = s[i];
      if (std::isdigit(c)) {
        cur = cur * 10 + (c - '0');
      }
      if ((!std::isdigit(c) && !std::iswspace(c)) || (i == s.length() - 1)) {
        if (opt == '+') {
          st.push(cur);
        } else if (opt == '-') {
          st.push(-cur);
        } else if (opt == '*') {
          const int top = st.top();
          st.pop();
          st.push(top * cur);
        } else if (opt == '/') {
          const int top = st.top();
          st.pop();
          st.push(top / cur);
        }
        opt = c;
        cur = 0;
      }
    }

    int result = 0;
    while (!st.empty()) {
      result += st.top();
      st.pop();
    }
    return result;
  }
};

TEST(Solution, calculate) {
  vector<std::pair<string, int>> cases = {
      std::make_pair(string("3+2*2"), 7),
      std::make_pair(string(" 3/2 "), 1),
      std::make_pair(string(" 3+5 / 2 "), 5),
  };
  for (const auto& c : cases) {
    EXPECT_EQ(Solution().calculate(c.first), c.second);
  }
}

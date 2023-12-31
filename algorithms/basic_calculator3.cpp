/*
 * =====================================================================================
 *
 *       Filename:  basic_calculator3.cpp
 *
 *    Description:  772. Basic Calculator III.
 *                  https://leetcode.com/problems/basic-calculator-iii/
 *
 *        Version:  1.0
 *        Created:  12/31/2023 09:23:02
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
    int i = 0;
    return calculate(s, i);
  }

 private:
  int calculate(const string& s, int& i) {
    stack<int> st;
    int cur = 0;
    char opt = '+';
    for (; i < s.length(); i++) {
      const char c = s[i];
      if (c == '(') {
        i++;
        cur = calculate(s, i);
      } else if (std::isdigit(c)) {
        cur = cur * 10 + (c - '0');
      }

      if (c == '+' || c == '-' || c == '*' || c == '/' || c == ')' || (i == s.length() - 1)) {
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

      if (c == ')') {
        break;
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
      // std::make_pair(string("3+2*2"), 7),
      // std::make_pair(string(" 3/2 "), 1),
      // std::make_pair(string(" 3+5 / 2 "), 5),
      // std::make_pair(string(" (3+5) / 2 "), 4),
      std::make_pair(string("2*(5+5*2)/3+(6/2+8)"), 21),
  };
  for (const auto& c : cases) {
    EXPECT_EQ(Solution().calculate(c.first), c.second);
  }
}

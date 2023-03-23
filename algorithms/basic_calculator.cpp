/*
 * =====================================================================================
 *
 *       Filename:  basic_calculator.cpp
 *
 *    Description:  224. Basic Calculator.
 *                  https://leetcode.com/problems/basic-calculator/
 *
 *        Version:  1.0
 *        Created:  03/23/23 11:52:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cctype>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::stack;
using std::string;
using std::vector;

class Solution {
 public:
  int calculate(string s) {
    stack<int> prevs;
    int result = 0;
    int sign = 1;
    for (int i = 0; i < s.size(); i++) {
      const char c = s[i];
      if (std::isdigit(c)) {
        int num = c - '0';
        while (i + 1 < s.size() && std::isdigit(s[i + 1])) {
          num = num * 10 + (s[i + 1] - '0');
          i++;
        }
        result += sign * num;
      } else if (c == '+') {
        sign = 1;
      } else if (c == '-') {
        sign = -1;
      } else if (c == '(') {
        prevs.push(result);
        prevs.push(sign);
        result = 0;
        sign = 1;
      } else if (c == ')') {
        result *= prevs.top();
        prevs.pop();
        result += prevs.top();
        prevs.pop();
      } else {
        ;  // Ignore space and invalid expression
      }
    }
    return result;
  }
};

TEST(Solution, calculate) {
  vector<std::pair<string, int>> cases = {
      std::make_pair(string("1 + 1"), 2),
      std::make_pair(string(" 2-1 + 2 "), 3),
      std::make_pair(string("(1+(4+5+2)-3)+(6+8)"), 23),
  };
  for (const auto& c : cases) {
    EXPECT_EQ(Solution().calculate(c.first), c.second);
  }
}

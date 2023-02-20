/*
 * =====================================================================================
 *
 *       Filename:  eval_rpn.cpp
 *
 *    Description:  150. Evaluate Reverse Polish Notation.
 *                  https://leetcode.com/problems/evaluate-reverse-polish-notation/
 *
 *        Version:  1.0
 *        Created:  02/20/2023 08:14:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stack>
#include <string>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::stack;
using std::string;
using std::vector;

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    std::stack<int> nums;
    int res = 0;
    for (const string& s : tokens) {
      const char c = s[0];
      if (s.size() == 1 && (c == '+' || c == '-' || c == '*' || c == '/')) {
        const int b = nums.top();
        nums.pop();
        int& a = nums.top();
        if (c == '+') {
          a += b;
        } else if (c == '-') {
          a -= b;
        } else if (c == '*') {
          a *= b;
        } else {
          a /= b;
        }
      } else {
        nums.push(std::stoi(s));
      }
    }
    return nums.top();
  }
};

TEST(Solution, evalRPN) {
  vector<std::pair<vector<string>, int>> cases = {
      std::make_pair(vector<string>{"2", "1", "+", "3", "*"}, 9),
      std::make_pair(vector<string>{"4", "13", "5", "/", "+"}, 6),
      std::make_pair(
          vector<string>{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}, 22),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().evalRPN(c.first), c.second);
  }
}

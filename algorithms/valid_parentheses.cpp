// 20. Valid Parentheses: https://leetcode.com/problems/valid-parentheses
// Author: xianfeng.zhu@gmail.com
#include <stack>
#include <string>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Solution {
 public:
  bool isValid(const std::string& s) {
    std::stack<char> chrs;
    for (const auto c : s) {
      if (c == '(') {
        chrs.push(')');
      } else if (c == '[') {
        chrs.push(']');
      } else if (c == '{') {
        chrs.push('}');
      } else if (!chrs.empty() && chrs.top() == c) {
        chrs.pop();
      } else {
        return false;
      }
    }
    return chrs.empty();
  }
};

TEST(Solution, isValud) {
  std::vector<std::pair<std::string, bool>> cases = {
      std::make_pair(std::string("()"), true),
      std::make_pair(std::string("()[]{}"), true),
      std::make_pair(std::string("(]"), false),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().isValid(c.first), c.second);
  }
}

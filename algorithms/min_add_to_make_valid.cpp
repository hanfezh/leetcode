/*
 * =====================================================================================
 *
 *       Filename:  min_add_to_make_valid.cpp
 *
 *    Description:  921. Minimum Add to Make Parentheses Valid.
 *                  https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 *
 *        Version:  1.0
 *        Created:  03/01/23 20:25:09
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

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::string;

class Solution {
 public:
  int minAddToMakeValid(string s) {
    int left = 0;
    int right = 0;
    for (const auto c : s) {
      if (c == '(') {
        left++;
      } else if (left > 0) {
        left--;
      } else {
        right++;
      }
    }
    return (left + right);
  }
};

TEST(Solution, minAddToMakeValid) {
  std::vector<std::pair<string, int>> cases = {
      std::make_pair(string(""), 0),
      std::make_pair(string("())"), 1),
      std::make_pair(string("((("), 3),
      std::make_pair(string(")))"), 3),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().minAddToMakeValid(c.first), c.second);
  }
}

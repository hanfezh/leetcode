/*
 * =====================================================================================
 *
 *       Filename:  remove_occurrences.cpp
 *
 *    Description:  1910. Remove All Occurrences of a Substring
 *                  https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
 *
 *        Version:  1.0
 *        Created:  02/11/2025 11:06:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <string>
#include <tuple>
#include <vector>

#include "gtest/gtest.h"

using std::string;
using std::tuple;
using std::vector;

class Solution {
 public:
  string removeOccurrences(string s, string part) {
    const int plen = part.length();
    for (int i = plen - 1; i < s.length(); i++) {
      if (i >= plen - 1) {
        if (s.substr(i - plen + 1, plen) == part) {
          s.erase(i - plen + 1, plen);
          i = i - plen;
        }
      }
    }
    return s;
  }
};

TEST(Solution, removeOccurrences) {
  vector<tuple<string, string, string>> cases = {
      std::make_tuple("daabcbaabcbc", "abc", "dab"),
      std::make_tuple("axxxxyyyyb", "xy", "ab"),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().removeOccurrences(std::get<0>(c), std::get<1>(c)), std::get<2>(c));
  }
}

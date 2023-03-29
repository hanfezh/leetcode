/*
 * =====================================================================================
 *
 *       Filename:  longest_substring.cpp
 *
 *    Description:  3. Longest Substring Without Repeating Characters.
 *
 *        Version:  1.0
 *        Created:  01/29/2023 12:14:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <cstdio>
#include <initializer_list>
#include <string>
#include <unordered_map>
#include <utility>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::initializer_list;
using std::string;
using std::unordered_map;
using std::vector;

class Solution1 {
 public:
  int lengthOfLongestSubstring(string s) {
    int len = 0;
    int left = 0;
    for (int i = 0; i < s.size(); i++) {
      size_t p = s.find(s[i], left);
      if (p == string::npos || p >= i) {
        len = std::max(len, i - left + 1);
      } else {
        len = std::max(len, i - left);
        left = static_cast<int>(p + 1);
      }
    }
    return len;
  }
};

// Hash table
class Solution2 {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> indices;
    int len = 0;
    int left = -1;
    for (int i = 0; i < s.size(); i++) {
      auto it = indices.find(s[i]);
      if (it != indices.end() && it->second >= left) {
        left = it->second;
        it->second = i;
      } else {
        indices[s[i]] = i;
      }
      len = std::max(len, i - left);
    }
    return len;
  }
};

// Replace hash table with vector
class Solution3 {
 public:
  int lengthOfLongestSubstring(string s) {
    vector<int> indices(256, -1);
    int len = 0;
    int start = -1;
    for (int i = 0; i < s.size(); i++) {
      const int c = s[i];
      if (indices[c] > start) {
        start = indices[c];
      }
      indices[s[i]] = i;
      len = std::max(len, i - start);
    }
    return len;
  }
};

TEST(Solution, lengthOfLongestSubstring) {
  initializer_list<std::pair<string, int>> cases = {
      std::make_pair("abba", 2),
      std::make_pair("bbbbb", 1),
      std::make_pair("pwwkew", 3),
      std::make_pair("abcabcbb", 3),
  };
  for (const auto& c : cases) {
    EXPECT_EQ(Solution1().lengthOfLongestSubstring(c.first), c.second);
    EXPECT_EQ(Solution2().lengthOfLongestSubstring(c.first), c.second);
    EXPECT_EQ(Solution3().lengthOfLongestSubstring(c.first), c.second);
  }
}

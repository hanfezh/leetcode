/*
 * =====================================================================================
 *
 *       Filename:  min_window.cpp
 *
 *    Description:  76. Minimum Window Substring
 *                  https://leetcode.com/problems/minimum-window-substring/
 *
 *        Version:  1.0
 *        Created:  06/13/2025 22:28:21
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
#include <unordered_map>

#include <gtest/gtest.h>

class Solution {
 public:
  std::string minWindow(std::string s, std::string t) {
    std::unordered_map<char, int> t_char_counts;
    for (const char c : t) {
      t_char_counts[c]++;
    }

    std::unordered_map<char, int> s_char_counts;
    std::shared_ptr<std::string> window;
    bool contained = false;
    int l = 0, r = 0;
    while (r < s.length()) {
      s_char_counts[s[r]]++;
      contained = contained || contains(s_char_counts, t_char_counts);
      if (contained) {
        while (s_char_counts[s[l]] > t_char_counts[s[l]]) {
          s_char_counts[s[l]]--;
          l++;
        }
        if (window == nullptr || window->length() > (r - l + 1)) {
          window = std::make_shared<std::string>(s.substr(l, r - l + 1));
        }
      }
      r++;
    }
    if (window != nullptr) {
      return *window;
    }
    return "";
  }

 private:
  // Return true if a contains b
  bool contains(const std::unordered_map<char, int>& a, const std::unordered_map<char, int>& b) {
    for (const auto& [k, v] : b) {
      auto it = a.find(k);
      if (it == a.end() || it->second < v) {
        return false;
      }
    }
    return true;
  }
};

TEST(Solution, minWindow) {
  std::vector<std::tuple<std::string, std::string, std::string>> cases = {
      {"ADOBECODEBANC", "ABC", "BANC"},
      {"a", "a", "a"},
      {"a", "aa", ""},
  };
  for (auto& [a, b, c] : cases) {
    EXPECT_EQ(Solution().minWindow(a, b), c);
  }
}

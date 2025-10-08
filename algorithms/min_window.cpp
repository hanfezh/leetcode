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

class Solution1 {
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

// Time complexity: O(n)
// Space complexity: O(1)
class Solution2 {
 public:
  std::string minWindow(std::string s, std::string t) {
    if (s.empty() || t.empty() || s.length() < t.length()) {
      return "";
    }

    std::vector<int> t_char_counts(256, 0);
    for (char c : t) {
      t_char_counts[c]++;
    }

    int count = t.length();
    int left = 0, right = 0;
    int min_len = INT_MAX;
    int start_idx = 0;

    while (right < s.length()) {
      if (t_char_counts[s[right++]]-- > 0) {
        count--;
      }

      while (count == 0) {
        if (right - left < min_len) {
          start_idx = left;
          min_len = right - left;
        }

        if (t_char_counts[s[left++]]++ == 0) {
          count++;
        }
      }
    }

    return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
  }
};

TEST(Solution, minWindow) {
  std::vector<std::tuple<std::string, std::string, std::string>> cases = {
      {"ADOBECODEBANC", "ABC", "BANC"},
      {"a", "a", "a"},
      {"a", "aa", ""},
  };
  for (auto& [a, b, c] : cases) {
    EXPECT_EQ(Solution1().minWindow(a, b), c);
    EXPECT_EQ(Solution2().minWindow(a, b), c);
  }
}

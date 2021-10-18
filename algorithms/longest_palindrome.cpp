// 5. Longest Palindromic Substring
// Refer: https://leetcode.com/problems/longest-palindromic-substring
// Author: xianfeng.zhu@gmail.com

#include <algorithm>
#include <cstdio>
#include <string>

// Expand around center, O(n^2)
class Solution1 {
 public:
  std::string longestPalindrome(const std::string& s) {
    if (s.empty()) {
      return "";
    }

    int start = 0;
    int end = 0;
    for (int i = 0; i < s.size(); i++) {
      const int len1 = expandAroundCenter(s, i, i);
      const int len2 = expandAroundCenter(s, i, i + 1);
      const int max_len = std::max(len1, len2);
      if (max_len > (end - start + 1)) {
        start = i - (max_len - 1) / 2;
        end = i + max_len / 2;
      }
    }
    return s.substr(start, end - start + 1);
  }

 private:
  // Return the length of palindrome
  int expandAroundCenter(const std::string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      left--;
      right++;
    }
    return (right - left - 1);
  }
};

// Dynamic programming, O(n^2)
class Solution2 {
 public:
  std::string longestPalindrome(const std::string& s) {
    if (s.size() < 2) {
      return s;
    }

    int max_idx = 0;
    int max_len = 1;

    // dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j]
    std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));
    for (int i = 0; i < s.size(); i++) {
      dp[i][i] = true;
    }
    for (int j = 1; j < s.size(); j++) {
      for (int i = 0; i < j; i++) {
        if (s[i] != s[j]) {
          continue;
        }

        // Check (i + 1 <= j - 1)
        if (j - i < 3) {
          dp[i][j] = true;
        } else {
          dp[i][j] = dp[i + 1][j - 1];
        }
        if (dp[i][j] && (j - i + 1 > max_len)) {
          max_idx = i;
          max_len = j - i + 1;
        }
      }
    }
    return s.substr(max_idx, max_len);
  }
};

using Solution = Solution2;

int main(int argc, char* argv[]) {
  std::string s = "aba";
  if (argc > 1) {
    s = argv[1];
  }
  std::string pa = Solution().longestPalindrome(s);
  printf("%s => %s\n", s.c_str(), pa.c_str());
  return 0;
}

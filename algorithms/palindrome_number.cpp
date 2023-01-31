/*
 * =====================================================================================
 *
 *       Filename:  palindrome_number.cpp
 *
 *    Description:  9. Palindrome Number.
 *                  https://leetcode.com/problems/palindrome-number/
 *
 *        Version:  1.0
 *        Created:  01/31/2023 17:21:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <array>
#include <cstdio>
#include <string>

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    std::array<int, 10> digits;
    int j = -1;
    int y = x;
    while (y > 0) {
      digits[++j] = y % 10;
      y /= 10;
    }

    int i = 0;
    while (i < j) {
      if (digits[i++] != digits[j--]) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char* argv[]) {
  int x = 10;
  if (argc > 1) {
    x = std::stoi(std::string(argv[1]));
  }
  const bool is_pal = Solution().isPalindrome(x);
  printf("%d is palindrome? %s\n", x, (is_pal ? "Yes" : "No"));
  return 0;
}

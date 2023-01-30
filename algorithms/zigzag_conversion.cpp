/*
 * =====================================================================================
 *
 *       Filename:  zigzag_conversion.cpp
 *
 *    Description:  6. Zigzag Conversion.
 *                  https://leetcode.com/problems/zigzag-conversion/description/
 *
 *        Version:  1.0
 *        Created:  01/29/2023 22:16:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <string>

using std::string;

class Solution {
 public:
  string convert(string s, int rows) {
    if (rows <= 1) {
      return s;
    }

    string buf;
    buf.reserve(s.size());
    const int k = (rows - 1) * 2;
    for (int i = 0; i < rows; i++) {
      int gap = i * 2;
      if (gap == 0) {
        gap = k;
      }
      for (int j = i; j < s.size();) {
        buf.push_back(s[j]);
        if (gap != k) {
          gap = k - gap;
        }
        j += gap;
      }
    }
    return buf;
  }
};

int main(int argc, char* argv[]) {
  string s = "A";
  string z = Solution().convert(s, 1);
  printf("%s\n", z.c_str());
  return 0;
}

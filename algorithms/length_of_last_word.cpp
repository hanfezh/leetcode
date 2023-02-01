/*
 * =====================================================================================
 *
 *       Filename:  length_of_last_word.cpp
 *
 *    Description:  Length of Last Word. Given a string s consists of upper/lower-case
 *                  alphabets and empty space characters ' ', return the length of last
 *                  word in the string.
 *
 *        Version:  1.0
 *        Created:  02/19/19 12:00:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <string>

class Solution {
 public:
  int lengthOfLastWord(const std::string& str) {
    int j = str.size() - 1;
    while (j >= 0 && str[j] == ' ') {
      j--;
    }

    int i = j;
    while (i >= 0 && str[i] != ' ') {
      i--;
    }

    return (j - i);
  }
};

int main(int argc, char* argv[]) {
  std::string str = "Hello World";
  if (argc > 1) {
    str = argv[1];
  }

  auto len = Solution().lengthOfLastWord(str);
  printf("Input: `%s`\nLength of last word: %d\n", str.c_str(), len);

  return 0;
}


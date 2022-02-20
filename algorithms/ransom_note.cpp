/*
 * =====================================================================================
 *
 *       Filename:  ransom_note.cpp
 *
 *    Description:  383. Ransom Note https://leetcode.com/problems/ransom-note/
 *
 *        Version:  1.0
 *        Created:  02/20/2022 12:10:24
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
  bool canConstruct(const std::string& ransom, const std::string& magazine) {
    std::array<int, 26> counts = {0};
    for (const char c : magazine) {
      counts[c - 'a'] += 1;
    }
    for (const char c : ransom) {
      counts[c - 'a'] -= 1;
      if (counts[c - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char* argv[]) {
  std::string ransom = "aa";
  std::string magazine = "aab";
  if (argc > 2) {
    ransom = argv[1];
    magazine = argv[2];
  }
  const bool succ = Solution().canConstruct(ransom, magazine);
  printf("ransom = %s, magazine = %s\n", ransom.c_str(), magazine.c_str());
  printf("%s\n", succ ? "true" : "false");
  return 0;
}

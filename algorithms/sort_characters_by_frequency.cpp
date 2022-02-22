/*
 * =====================================================================================
 *
 *       Filename:  sort_characters_by_frequency.cpp
 *
 *    Description:  451. Sort Characters By Frequency
 *                  https://leetcode.com/problems/sort-characters-by-frequency/
 *
 *        Version:  1.0
 *        Created:  02/22/2022 22:11:17
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
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::string frequencySort(const std::string& s) {
    // Count frequency
    std::unordered_map<char, int> freq;
    for (const char c : s) {
      freq[c]++;
    }

    // Gather characters with same frequency
    std::vector<std::string> bucket(s.size() + 1);
    for (const auto& item : freq) {
      bucket[item.second].append(1, item.first);
    }

    // Assemble sorted string
    std::string res;
    for (int i = bucket.size() - 1; i > 0; i--) {
      if (bucket[i].empty()) {
        continue;
      }
      for (char c : bucket[i]) {
        res.append(i, c);
      }
    }
    return res;
  }
};

int main(int argc, char* argv[]) {
  std::string s = "tree";
  if (argc > 1) {
    s = argv[1];
  }
  const std::string res = Solution().frequencySort(s);
  printf("s = %s\n", s.c_str());
  printf("%s\n", res.c_str());
  return 0;
}

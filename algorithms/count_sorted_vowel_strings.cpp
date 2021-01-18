// 1641. Count Sorted Vowel Strings
// Refer: https://leetcode.com/problems/count-sorted-vowel-strings
// Author: xianfeng.zhu@gmail.com

#include <cstdio>
#include <cstdlib>
#include <vector>

class Solution {
 public:
  int countVowelStrings(int n) {
    const int vowel_chrs = 5;
    std::vector<int> counts(vowel_chrs, 1);
    for (int i = 0; i < n; i++) {
      for (int j = vowel_chrs - 2; j >= 0; j--) {
        counts[j] = counts[j] + counts[j + 1];
      }
    }
    return counts[0];
  }
};

int main(int argc, char* argv[]) {
  int n = 3;
  if (argc > 1) {
    n = atoi(argv[1]);
  }
  int count = Solution().countVowelStrings(n);
  printf("%d => %d\n", n, count);
  return 0;
}

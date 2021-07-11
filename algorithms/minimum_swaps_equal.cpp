// 1247. Minimum Swaps to Make Strings Equal
// Refer: https://leetcode.com/problems/minimum-swaps-to-make-strings-equal
// Author: xianfeng.zhu@gmail.com

#include <string>

class Solution {
 public:
  int minimumSwap(const std::string& s1, const std::string& s2) {
    int x = 0;
    int y = 0;
    const int len = s1.size();
    
    for (int i = 0; i < len; i++) {
      if (s1[i] != s2[i]) {
        if (s1[i] == 'x') {
          x++;
        } else {
          y++;
        }
      }
    }

    printf("x = %d, y = %d\n", x, y);
    if ((x + y) % 2 != 0) {
      return -1;
    }
    const int swaps = (x / 2 + y / 2 + x % 2 + y % 2);
    return swaps;
  }
};

int main(int argc, char* argv[]) {
  std::string s1 = "xxyyxyxyxx";
  std::string s2 = "xyyxyxxxyx";
  if (argc > 2) {
    s1 = argv[1];
    s2 = argv[2];
  }
  const int swaps = Solution().minimumSwap(s1, s2);
  printf("Minimum swaps = %d\n", swaps);
  return 0;
}

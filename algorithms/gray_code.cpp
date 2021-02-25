// 89. Gray Code
// Refer: https://leetcode.com/problems/gray-code
// Author: xianfeng.zhu@gmail.com

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>

class Solution {
 public:
  std::vector<int> grayCode(int n) {
    std::vector<int> codes = {0, 1};
    const size_t new_cap = pow((double)2, (double)n);
    codes.reserve(new_cap);

    while (--n > 0) {
      for (int& val: codes) {
        // append bit 0
        val <<= 1;
      }
      for (auto it = codes.rbegin(); it != codes.rend(); it++) {
        // append bit 1
        codes.push_back(*it + 1);
      }
    }

    return codes;
  }
};

int main(int argc, char* argv[]) {
  int n = 3;
  if (argc > 1) {
    n = atoi(argv[1]);
  }
  std::vector<int> codes = Solution().grayCode(n);
  for (const int val: codes) {
    printf("%d ", val);
  }
  printf("\n");
  return 0;
}

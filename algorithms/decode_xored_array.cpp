// 1720. Decode XORed Array: https://leetcode.com/problems/decode-xored-array
// Author: xianfeng.zhu@gmail.com

#include <cstdio>
#include <vector>

class Solution {
 public:
  std::vector<int> decode(std::vector<int>& encoded, int first) {
    std::vector<int> plain(encoded.size() + 1);
    plain[0] = first;

    for (int i = 0; i < encoded.size(); i++) {
      plain[i + 1] = encoded[i] ^ plain[i];
    }

    return plain;
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> encoded = {1, 2, 3};
  auto plain = Solution().decode(encoded, 1);
  for (const auto val: plain) {
    printf("%d ", val);
  }
  printf("\n");
  return 0;
}

// 1679. Max Number of K-Sum Pairs
// Refer: https://leetcode.com/problems/max-number-of-k-sum-pairs
// Author: xianfeng.zhu@gmail.com

#include <cstdio>
#include <vector>
#include <unordered_map>

class Solution {
 public:
  int maxOperations(std::vector<int>& nums, int k) {
    int ops = 0;
    std::unordered_map<int, int> counts;
    for (const int val: nums) {
      counts[val] += 1;
    }

    for (int val: nums) {
      auto iter1 = counts.find(val);
      if (iter1->second < 1) {
        continue;
      }

      val = k - val;
      if (val == 0) {
        continue;
      }

      auto iter2 = counts.find(val);
      if (iter1 == iter2) {
        if (iter1->second > 1) {
          iter1->second -= 2;
          ops += 1;
        }
      } else if (iter2 != counts.end()) {
        if (iter2->second > 0) {
          iter1->second -= 1;
          iter2->second -= 1;
          ops += 1;
        }
      }
    }

    return ops;
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums = {3, 1, 5, 1, 1, 1, 1, 1, 2, 2, 3, 2, 2};
  int k = 1;
  int ops = Solution().maxOperations(nums, k);
  printf("Max operations => %d\n", ops);
  return 0;
}

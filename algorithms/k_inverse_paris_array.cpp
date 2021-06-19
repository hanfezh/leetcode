// 629. K Inverse Pairs Array
// Refer: https://leetcode.com/problems/k-inverse-pairs-array
// Author: xianfeng.zhu@gmail.com

#include <cstdio>
#include <vector>
#include <map>

// Time Limit Exceeded
class Solution {
 public:
  int kInversePairs(int n, int k) {
    if (n < 1) {
      return 0;
    }

    // Caculate inverse pairs of factorial(n)
    // n = 1, factorial(1) = 1
    //   idx, val
    //   0, 0
    // n = 2, factorial(2) = 2
    //   idx, val
    //   0, 0
    //   1, 1
    // n = 3, factorial(3) = factorial(2) * 3 = 6
    //   idx, val
    //   0, 0
    //   1, 1
    //   2, 1
    //   3, 2
    //   4, 2
    //   5, 3
    std::vector<int> nums = {0};
    for (int x = 2; x <= n; x++) {
      const size_t size = nums.size();
      nums.reserve(x * size);
      for (int i = 1; i < x; i++) {
        for (int j = 0; j < size; j++) {
          nums.push_back(nums[j] + i);
        }
      }
    }

    // Caculate k pairs
    std::map<int, int> pairs;
    for (const auto val: nums) {
      pairs[val] += 1;
    }
    return pairs[k];
  }
};

int main(int argc, char* argv[]) {
  int n = 3;
  int k = 1;
  if (argc > 2) {
    n = atoi(argv[1]);
    k = atoi(argv[2]);
  }
  const int val = Solution().kInversePairs(n, k);
  printf("n = %d, k = %d -> k pairs = %d\n", n, k, val);
  return 0;
}

// 629. K Inverse Pairs Array
// Refer: https://leetcode.com/problems/k-inverse-pairs-array
// Author: xianfeng.zhu@gmail.com

#include <cstdio>
#include <vector>
#include <map>

// Brutal force, time limit exceeded
class Solution1 {
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

// Dynamic programming
class Solution2 {
 public:
  int kInversePairs(int n, int k) {
    if (n < 1 || k < 0) {
      return 0;
    }
    // Implementation logic:
    // 1. pair size, s(n)
    //    s(n) = s(n-1) + n - 1
    // 2. number for pairs, f(n)(k)
    //    f(n)(k) = f(n)(k-1) + f(n-n)(k)
    //    if (k > n) {
    //      f(n)(k) -= f(n-1)(k-n);
    //    }

    // Caculate pairs size
    std::vector<int> sizes(n + 1);
    sizes[0] = 1;
    for (int i = 1; i <= n; i++) {
      sizes[i] = sizes[i - 1] + i - 1;
    }

    // Verify k
    if (k >= sizes[n]) {
      // Invalid k
      return 0;
    } else if (k >= sizes[n] / 2) {
      // Correct k to first half
      k = sizes[n] - k - 1;
    }

    // Allocate arrays to store numbers
    std::vector<std::vector<int>> nums(n + 1, std::vector<int>(k + 1));

    // Caculate numbers
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        if (j == 0) {
          nums[i][j] = 1;
        } else if (j < sizes[i]) {
          nums[i][j] = nums[i][j - 1] + nums[i - 1][j];
          if (j >= i) {
            nums[i][j] -= nums[i - 1][j - i];
          }
        }
      }
    }

    return nums[n][k];
  }
};

using Solution = Solution2;

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

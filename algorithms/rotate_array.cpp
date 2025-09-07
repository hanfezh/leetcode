// 189. Rotate Array: https://leetcode.com/problems/rotate-array
// Author: xianfeng.zhu@gmail.com

#include <algorithm>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// Cyclic replacement
class Solution1 {
 public:
  void rotate(std::vector<int>& nums, int k) {
    int size = nums.size();
    if (size == 0 || (k % size) == 0) {
      return;
    }

    k %= size;
    int count = 0;

    for (int idx = 0; count < size; idx++) {
      int start = idx;
      int value = nums[idx];
      do {
        start = (start + k) % size;
        std::swap(value, nums[start]);
        count++;
      } while (start != idx);
    }
  }
};

class Solution2 {
 public:
  void rotate(std::vector<int>& nums, int k) {
    const int n = nums.size();
    k %= n;
    if (n == 1 || k == 0) {
      return;
    }
    reverse(nums, 0, n - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
  }

  void reverse(std::vector<int>& nums, int start, int end) {
    while (start < end) {
      std::swap(nums[start++], nums[end--]);
    }
  }
};

TEST(Solution, rotate) {
  std::vector<std::tuple<std::vector<int>, int, std::vector<int>>> cases = {
      {{1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4}},
      {{-1, -100, 3, 99}, 2, {3, 99, -1, -100}},
  };
  for (auto& [nums, k, result] : cases) {
    std::vector<int> nums1 = nums;
    std::vector<int> nums2 = nums;
    Solution1().rotate(nums1, k);
    Solution2().rotate(nums2, k);
    EXPECT_THAT(nums1, testing::ElementsAreArray(result));
    EXPECT_THAT(nums2, testing::ElementsAreArray(result));
  }
}


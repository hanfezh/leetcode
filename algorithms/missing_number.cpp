/*
 * =====================================================================================
 *
 *       Filename:  missing_number.cpp
 *
 *    Description:  Missing number. Given an array containing n distinct numbers taken
 *                  from 0, 1, 2, ..., n, find the one that is missing from the array.
 *
 *        Version:  1.0
 *        Created:  03/05/19 01:43:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// Sort algorithm, std::sort
class Solution1 {
 public:
  int missingNumber(std::vector<int>& nums) { return sortMissing(nums); }

 private:
  int sortMissing(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int supposed = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] != supposed) {
        // Find missing
        break;
      }
      supposed++;
    }
    return supposed;
  }
};

// Sort algorithm, quick sort
class Solution2 {
 public:
  int missingNumber(std::vector<int>& nums) { return sortMissing(nums); }

 private:
  int sortMissing(std::vector<int>& nums) {
    quickSort(nums, 0, nums.size() - 1);
    int supposed = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] != supposed) {
        // Find missing
        break;
      }
      supposed++;
    }
    return supposed;
  }

  void quickSort(std::vector<int>& nums, int left, int right) {
    if (left < right) {
      int middle = partition(nums, left, right);
      quickSort(nums, left, middle - 1);
      quickSort(nums, middle + 1, right);
    }
  }

  int partition(std::vector<int>& nums, int left, int right) {
    int midval = nums[right];
    int last = left;
    for (int i = left; i < right; i++) {
      if (nums[i] >= midval) {
        continue;
      }
      if (last != i) {
        swap(&nums[last], &nums[i]);
      }
      last++;
    }
    if (last != right) {
      swap(&nums[last], &nums[right]);
    }
    return last;
  }

  void swap(int* a, int* b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
  }
};

// Bit manipulation trick, xor
class Solution3 {
 public:
  int missingNumber(std::vector<int>& nums) {
    int supposed = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      supposed ^= i;
      supposed ^= nums[i];
    }
    supposed ^= nums.size();
    return supposed;
  }
};

// Gauss formula
class Solution4 {
 public:
  int missingNumber(std::vector<int>& nums) {
    int sum = nums.size() * (nums.size() + 1) / 2;
    for (const auto val : nums) {
      sum -= val;
    }
    return sum;
  }
};

TEST(Solution, missingNumber) {
  std::vector<std::pair<std::vector<int>, int>> cases{
      std::make_pair(std::vector<int>{3, 0, 1}, 2),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution1().missingNumber(c.first), c.second);
    EXPECT_EQ(Solution2().missingNumber(c.first), c.second);
    EXPECT_EQ(Solution3().missingNumber(c.first), c.second);
    EXPECT_EQ(Solution4().missingNumber(c.first), c.second);
  }
}

/*
 * =====================================================================================
 *
 *       Filename:  contains_duplicate.cpp
 *
 *    Description:  217. Contains Duplicate. Given an array of integers, find if the
 *                  array contains any duplicates.
 *
 *        Version:  1.0
 *        Created:  02/26/19 03:20:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <set>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// Quick sort
class Solution1 {
 public:
  bool containsDuplicate(std::vector<int>& nums) {
    bool is_dup = false;
    quickSort(nums, 0, nums.size() - 1, is_dup);
    return is_dup;
  }

 private:
  void quickSort(std::vector<int>& nums, int left, int right, bool& is_dup) {
    if (!is_dup && left < right) {
      int middle = partition(nums, left, right, is_dup);
      quickSort(nums, left, middle - 1, is_dup);
      quickSort(nums, middle + 1, right, is_dup);
    }
  }

  int partition(std::vector<int>& nums, int left, int right, bool& is_dup) {
    int midval = nums[right];
    int last = left;
    for (int i = left; i < right; i++) {
      if (nums[i] > midval) {
        continue;
      }
      if (nums[i] == midval) {
        // Stop partition
        is_dup = true;
        return last;
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

// std::sort
class Solution2 {
 public:
  bool containsDuplicate(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    for (size_t i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        return true;
      }
    }
    return false;
  }
};

// Hash table
class Solution3 {
 public:
  bool containsDuplicate(std::vector<int>& nums) {
    return nums.size() > std::set<int>(nums.begin(), nums.end()).size();
  }
};

TEST(Solution, containsDuplicate) {
  std::vector<std::pair<std::vector<int>, bool>> cases = {
      std::make_pair(std::vector<int>{1, 3, 2}, false),
      std::make_pair(std::vector<int>{1, 2, 3, 1}, true),
      std::make_pair(std::vector<int>{1, 2, 3, 4}, false),
      std::make_pair(std::vector<int>{10, 7, 8, 9, 1, 5, 1}, true),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution1().containsDuplicate(c.first), c.second);
    EXPECT_EQ(Solution2().containsDuplicate(c.first), c.second);
    EXPECT_EQ(Solution3().containsDuplicate(c.first), c.second);
  }
}

/*
 * =====================================================================================
 *
 *       Filename:  remove_duplicates_from_array2.cpp
 *
 *    Description:  80. Remove Duplicates from Sorted Array II. Given a sorted array
 *                  nums, remove the duplicates in-place such that duplicates appeared
 *                  at most twice and return the new length.
 *
 *        Version:  1.0
 *        Created:  05/21/2019 12:33:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <utility>
#include <vector>

#include "gtest/gtest.h"

class Solution1 {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    if (nums.size() <= 2) {
      return nums.size();
    }

    int last = 1;
    int idx = last + 1;
    while (idx < nums.size()) {
      if ((nums[idx] == nums[last]) && (nums[idx] == nums[last - 1])) {
        idx++;
      } else {
        if (idx > (last + 1)) {
          nums[last + 1] = nums[idx];
        }
        last++;
        idx++;
      }
    }

    return (last + 1);
  }
};

class Solution2 {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    int i = 0;
    bool duplicate = false;
    for (int j = 1; j < nums.size(); j++) {
      if (nums[j] == nums[i]) {
        if (duplicate) {
          continue;
        }
        duplicate = true;
      } else {
        duplicate = false;
      }
      if (j > ++i) {
        nums[i] = nums[j];
      }
    }
    return (nums.size() == 0 ? 0 : (i + 1));
  }
};

class Solution3 {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
      if (i < 2 || nums[j] != nums[i - 2]) {
        nums[i++] = nums[j];
      }
    }
    return i;
  }
};

TEST(Solution, removeDuplicates) {
  std::vector<std::pair<std::vector<int>, int>> cases = {
      {{1, 1, 1, 2, 2, 3}, 5},
      {{0, 0, 1, 1, 1, 1, 2, 3, 3}, 7},
  };
  for (auto& [nums, result] : cases) {
    EXPECT_EQ(Solution3().removeDuplicates(nums), result);
  }
}

/*
 * =====================================================================================
 *
 *       Filename:  merge_sorted_array.cpp
 *
 *    Description:  Merge Sorted Array. Given two sorted integer arrays nums1 and nums2,
 *                  merge nums2 into nums1 as one sorted array.
 *
 *        Version:  1.0
 *        Created:  02/18/19 04:42:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::tuple;
using std::vector;

// Intuitive
class Solution1 {
 public:
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int last = 0;
    for (int i = 0; i < n; i++) {
      while ((last < m) && (nums1[last] < nums2[i])) {
        last++;
      }

      for (int j = m; j > last; j--) {
        nums1[j] = nums1[j - 1];
      }
      nums1[last] = nums2[i];
      m++;
    }
  }
};

// Two pointers
class Solution2 {
 public:
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int k = m + n;
    int i = m - 1;
    int j = n - 1;

    while (j >= 0) {
      if (i >= 0 && nums1[i] > nums2[j]) {
        nums1[--k] = nums1[i--];
      } else {
        nums1[--k] = nums2[j--];
      }
    }
  }
};

TEST(Solution, merge) {
  vector<tuple<vector<int>, int, vector<int>, int, vector<int>>> cases = {
      std::make_tuple(vector<int>{1, 2, 3, 0, 0, 0}, 3, vector<int>{2, 5, 6}, 3,
                      vector<int>{1, 2, 2, 3, 5, 6}),
      std::make_tuple(vector<int>{1}, 1, vector<int>{}, 0, vector<int>{1}),
      std::make_tuple(vector<int>{0}, 0, vector<int>{1}, 1, vector<int>{1}),
  };
  for (auto& c : cases) {
    vector<int> copy = std::get<0>(c);
    Solution1().merge(std::get<0>(c), std::get<1>(c), std::get<2>(c), std::get<3>(c));
    EXPECT_THAT(std::get<0>(c), testing::ElementsAreArray(std::get<4>(c)));
    Solution2().merge(copy, std::get<1>(c), std::get<2>(c), std::get<3>(c));
    EXPECT_THAT(copy, testing::ElementsAreArray(std::get<4>(c)));
  }
}

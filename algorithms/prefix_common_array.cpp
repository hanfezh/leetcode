/*
 * =====================================================================================
 *
 *       Filename:  prefix_common_array.cpp
 *
 *    Description:  2657. Find the Prefix Common Array of Two Arrays
 *                  https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
 *
 *        Version:  1.0
 *        Created:  01/15/2025 22:35:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::vector;

class Solution {
 public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    const int n = A.size();
    vector<int> frequency(n, 0);
    vector<int> prefix(n, 0);
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        prefix[i] += prefix[i - 1];
      }
      if (++frequency[A[i] - 1] > 1) {
        prefix[i]++;
      }
      if (++frequency[B[i] - 1] > 1) {
        prefix[i]++;
      }
    }
    return prefix;
  }
};

TEST(Solution, findThePrefixCommonArray) {
  vector<std::tuple<vector<int>, vector<int>, vector<int>>> cases = {
      std::make_tuple(vector<int>{1, 3, 2, 4}, vector<int>{3, 1, 2, 4}, vector<int>{0, 2, 3, 4}),
      std::make_tuple(vector<int>{2, 3, 1}, vector<int>{3, 1, 2}, vector<int>{0, 1, 3}),
  };
  for (auto& c : cases) {
    EXPECT_THAT(Solution().findThePrefixCommonArray(std::get<0>(c), std::get<1>(c)),
                testing::ElementsAreArray(std::get<2>(c)));
  }
}

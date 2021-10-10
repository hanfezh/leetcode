/*
 * =====================================================================================
 *
 *       Filename:  median_sliding_window.cpp
 *
 *    Description: 480. Sliding Window Median.
 *                 https://leetcode.com/problems/sliding-window-median
 *
 *        Version:  1.0
 *        Created:  10/09/2021 21:42:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <iterator>
#include <set>
#include <vector>

class Solution {
 public:
  std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k) {
    std::vector<double> medians;
    std::multiset<int> window(nums.begin(), nums.begin() + k);
    auto middle = std::next(window.begin(), k / 2);
    for (int i = k; i <= nums.size(); i++) {
      medians.push_back((static_cast<int64_t>(*middle) + *std::prev(middle, 1 - k % 2)) / 2.0);
      if (i == nums.size()) {
        break;
      }

      // Insert nums[i]
      window.insert(nums[i]);

      // i -> N, middle -> M, i - k -> X
      // 1) X <= M <= N, middle++
      // 2) N < M < X, middle--
      // 3) X <= M && N < M, middle++, middle--
      // 4) M < X && M <= N, middle--, middle++
      if (nums[i] < *middle) {
        // N < M
        middle--;
      }
      if (nums[i - k] <= *middle) {
        // X <= M
        middle++;
      }
      window.erase(window.lower_bound(nums[i - k]));
    }
    return medians;
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  std::vector<double> medians = Solution().medianSlidingWindow(nums, 3);
  for (const double val : medians) {
    printf("%f ", val);
  }
  printf("\n");
  return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  two_out_of_three.cpp
 *
 *    Description:  2032. Two Out of Three.
 *                  https://leetcode.com/problems/two-out-of-three
 *
 *        Version:  1.0
 *        Created:  10/10/2021 22:30:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>
#include <map>
#include <set>
#include <vector>

class Solution {
 public:
  std::vector<int> twoOutOfThree(std::vector<int>& nums1, std::vector<int>& nums2,
                                 std::vector<int>& nums3) {
    std::map<int, int> nums_map;
    auto insert = [&](const std::vector<int>& nums) {
      const std::set<int> s(nums.begin(), nums.end());
      for (const int v : s) {
        nums_map[v]++;
      }
    };

    insert(nums1);
    insert(nums2);
    insert(nums3);

    std::vector<int> vals;
    for (const auto e : nums_map) {
      if (e.second > 1) {
        vals.push_back(e.first);
      }
    }
    return vals;
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums1 = {1, 1, 3, 2};
  std::vector<int> nums2 = {2, 3, 2};
  std::vector<int> nums3 = {3};
  std::vector<int> vals = Solution().twoOutOfThree(nums1, nums2, nums3);
  std::copy(vals.begin(), vals.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  return 0;
}

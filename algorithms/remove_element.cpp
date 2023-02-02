/*
 * =====================================================================================
 *
 *       Filename:  remove_element.cpp
 *
 *    Description:  27. Remove Element. https://leetcode.com/problems/remove-element/
 *
 *        Version:  1.0
 *        Created:  02/02/2023 14:13:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <vector>

using std::vector;

// Two pointers
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
      if (nums[j] != val) {
        if (i != j) {
          nums[i] = nums[j];
        }
        i++;
      }
    }
    return i;
  }
};

int main(int argc, char* argv[]) {
  vector<int> nums = {3, 2, 2, 3};
  int val = 3;
  const int k = Solution().removeElement(nums, val);
  printf("k = %d\n", k);
  return 0;
}

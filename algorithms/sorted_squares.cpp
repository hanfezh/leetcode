/*
 * =====================================================================================
 *
 *       Filename:  sorted_squares.cpp
 *
 *    Description:  977. Squares of a Sorted Array.
 *                  https://leetcode.com/problems/squares-of-a-sorted-array/
 *
 *        Version:  1.0
 *        Created:  01/31/2023 19:16:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <vector>

using std::vector;

// Two pointers
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> squares(nums.size(), 0);
    int i = 0;
    int j = nums.size() - 1;
    int k = nums.size() - 1;
    while (i <= j) {
      if (std::abs(nums[i]) < nums[j]) {
        squares[k--] = nums[j] * nums[j];
        j--;
      } else {
        squares[k--] = nums[i] * nums[i];
        i++;
      }
    }
    return squares;
  }
};

int main(int argc, char* argv[]) {
  vector<int> nums = {-7, -3, 2, 3, 11};
  vector<int> squares = Solution().sortedSquares(nums);
  for (const int n : squares) {
    printf("%d ", n);
  }
  printf("\n");
  return 0;
}

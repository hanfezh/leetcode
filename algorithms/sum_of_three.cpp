/*
 * =====================================================================================
 *
 *       Filename:  sum_of_three.cpp
 *
 *    Description:  2177. Find Three Consecutive Integers That Sum to a Given Number.
 *                  https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/
 *
 *        Version:  1.0
 *        Created:  01/25/2023 17:37:50
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

class Solution {
 public:
  vector<long long> sumOfThree(long long num) {
    const long long mid = num / 3;
    if (mid * 3 == num) {
      return vector<long long>({mid - 1, mid, mid + 1});
    }
    return vector<long long>();
  }
};

int main(int argc, char* argv[]) {
  long long num = 51;
  vector<long long> res = Solution().sumOfThree(num);
  for (const auto r : res) {
    printf("%lld ", r);
  }
  printf("\n");
  return 0;
}

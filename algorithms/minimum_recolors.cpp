/*
 * =====================================================================================
 *
 *       Filename:  minimum_recolors.cpp
 *
 *    Description:  2379. Minimum Recolors to Get K Consecutive Black Blocks
 *
 *        Version:  1.0
 *        Created:  03/08/2025 22:53:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <algorithm>
#include <string>
#include <tuple>
#include <vector>

#include "gtest/gtest.h"

using std::string;

class Solution {
 public:
  int minimumRecolors(string blocks, int k) {
    int black_cnt = 0;
    int max_cnt = 0;
    for (int l = 0, r = 0; r < blocks.length(); r++) {
      if (r < k) {
        if (blocks[r] == 'B') {
          max_cnt = ++black_cnt;
        }
      } else {
        if (blocks[r] == 'B') {
          black_cnt++;
        }
        if (blocks[l] == 'B') {
          black_cnt--;
        }
        max_cnt = std::max(max_cnt, black_cnt);
        l++;
      }
    }
    return k - max_cnt;
  }
};

TEST(Solution, minimumRecolors) {
  std::vector<std::tuple<string, int, int>> cases = {
      std::make_tuple("WBBWWBBWBW", 7, 3),
      std::make_tuple("WBWBBBW", 2, 0),
  };
  for (auto& [blocks, k, num] : cases) {
    EXPECT_EQ(Solution().minimumRecolors(blocks, k), num);
  }
}

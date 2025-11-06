/*
 * =====================================================================================
 *
 *       Filename:  random_pick_index.cpp
 *
 *    Description:  528. Random Pick with Weight
 *
 *        Version:  1.0
 *        Created:  11/06/2025 18:34:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <map>
#include <vector>

class Solution {
 public:
  Solution(std::vector<int>& w) {
    for (int i = 0; i < w.size(); i++) {
      sum_ += w[i];
      indexes_[sum_] = i;
    }
    std::srand(std::time(0));
  }

  int pickIndex() {
    int r = std::rand() % sum_;
    auto it = indexes_.upper_bound(r);
    if (it != indexes_.end()) {
      return it->second;
    }
    return (--it)->second;
  }

 private:
  std::map<int, int> indexes_;
  int sum_ = 0;
};

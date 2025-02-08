/*
 * =====================================================================================
 *
 *       Filename:  number_containers.cpp
 *
 *    Description:  2349. Design a Number Container System
 *                  https://leetcode.com/problems/design-a-number-container-system/
 *
 *        Version:  1.0
 *        Created:  02/08/2025 22:15:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <set>
#include <unordered_map>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::set;
using std::unordered_map;

// Hash map + ordered set
class NumberContainers {
 public:
  NumberContainers() {}

  void change(int index, int number) {
    auto it = nums_.find(index);
    if (it != nums_.end()) {
      indexes_[it->second].erase(index);
      it->second = number;
    } else {
      nums_[index] = number;
    }
    indexes_[number].insert(index);
  }

  int find(int number) {
    const auto it = indexes_.find(number);
    if (it != indexes_.end() && it->second.size() > 0) {
      return *(it->second.begin());
    }
    return -1;
  }

 private:
  unordered_map<int, int> nums_;
  unordered_map<int, set<int>> indexes_;
};

TEST(Solution, NumberContainers) {
  NumberContainers nc;
  EXPECT_EQ(nc.find(10),
            -1);     // There is no index that is filled with number 10. Therefore, we return -1.
  nc.change(2, 10);  // Your container at index 2 will be filled with number 10.
  nc.change(1, 10);  // Your container at index 1 will be filled with number 10.
  nc.change(3, 10);  // Your container at index 3 will be filled with number 10.
  nc.change(5, 10);  // Your container at index 5 will be filled with number 10.
  EXPECT_EQ(nc.find(10), 1);  // Number 10 is at the indices 1, 2, 3, and 5. Since the smallest
                              // index that is filled with 10 is 1, we return 1.
  nc.change(1, 20);  // Your container at index 1 will be filled with number 20. Note that index 1
                     // was filled with 10 and then replaced with 20.
  EXPECT_EQ(nc.find(10), 2);  // Number 10 is at the indices 2, 3, and 5. The smallest index that is
                              // filled with 10 is 2. Therefore, we return 2.
}

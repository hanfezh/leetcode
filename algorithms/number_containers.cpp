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

#include <functional>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::greater;
using std::priority_queue;
using std::set;
using std::unordered_map;
using std::vector;

// Hash map + ordered set
class NumberContainers1 {
 public:
  NumberContainers1() {}

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

// Hash map + priority queue
class NumberContainers2 {
 public:
  NumberContainers2() {}

  void change(int index, int number) {
    nums_[index] = number;
    indexes_[number].push(index);
  }

  // Lazy update
  int find(int number) {
    auto it = indexes_.find(number);
    if (it == indexes_.end()) {
      return -1;
    }
    auto& min_queue = it->second;
    while (!min_queue.empty()) {
      const int top = min_queue.top();
      if (nums_[top] != number) {
        min_queue.pop();
      } else {
        return top;
      }
    }
    return -1;
  }

 private:
  unordered_map<int, int> nums_;
  unordered_map<int, priority_queue<int, vector<int>, greater<int>>> indexes_;
};

TEST(Solution, NumberContainers) {
  using NumberContainers = NumberContainers2;
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

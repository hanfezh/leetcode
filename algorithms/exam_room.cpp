/*
 * =====================================================================================
 *
 *       Filename:  exam_room.cpp
 *
 *    Description:  855. Exam Room. https://leetcode.com/problems/exam-room/
 *
 *        Version:  1.0
 *        Created:  01/31/2025 22:17:50
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
#include <utility>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::pair;
using std::set;
using std::unordered_map;

// Leverage ordered set
class ExamRoom {
 public:
  ExamRoom(int n) : seats_(n), segments_(ExamRoom::Compare(n)) { segments_.emplace(-1, n); }

  // O(nlogn)
  int seat() {
    const pair<int, int> cur = *segments_.begin();
    int pos;
    if (cur.first == -1) {
      pos = 0;
    } else if (cur.second == seats_) {
      pos = seats_ - 1;
    } else {
      pos = (cur.first + cur.second) / 2;
    }
    del_segment(cur.first, cur.second);
    add_segment(cur.first, pos);
    add_segment(pos, cur.second);
    return pos;
  }

  // O(nlogn)
  void leave(int p) {
    auto left_it = left_neighbours_.find(p);
    auto right_it = right_neighbours_.find(p);
    if (left_it == left_neighbours_.end() || right_it == right_neighbours_.end()) {
      return;
    }
    const int prev = left_it->second;
    const int next = right_it->second;
    del_segment(prev, p);
    del_segment(p, next);
    add_segment(prev, next);
  }

 private:
  void add_segment(const int a, const int b) {
    segments_.emplace(a, b);
    left_neighbours_[b] = a;
    right_neighbours_[a] = b;
  }

  void del_segment(const int a, const int b) {
    segments_.erase(std::make_pair(a, b));
    left_neighbours_.erase(b);
    right_neighbours_.erase(a);
  }

  struct Compare {
    const int seats_;

    Compare(const int seats) : seats_(seats) {}

    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
      const int dis1 = distance(a);
      const int dis2 = distance(b);
      if (dis1 == dis2) {
        return a.first < b.first;
      }
      return dis1 > dis2;
    }

    int distance(const pair<int, int>& seg) const {
      if (seg.first == -1 || seg.second == seats_) {
        return seg.second - seg.first - 1;
      }
      return (seg.second - seg.first) / 2;
    }
  };

 private:
  const int seats_;
  set<pair<int, int>, Compare> segments_;
  unordered_map<int, int> left_neighbours_;
  unordered_map<int, int> right_neighbours_;
};

TEST(Solution, ExamRoom) {
  ExamRoom examRoom(10);
  EXPECT_EQ(examRoom.seat(),
            0);  // return 0, no one is in the room, then the student sits at seat number 0.
  EXPECT_EQ(examRoom.seat(), 9);  // return 9, the student sits at the last seat number 9.
  EXPECT_EQ(examRoom.seat(), 4);  // return 4, the student sits at the last seat number 4.
  EXPECT_EQ(examRoom.seat(), 2);  // return 2, the student sits at the last seat number 2.
  examRoom.leave(4);
  EXPECT_EQ(examRoom.seat(), 5);  // return 5, the student sits at the last seat number 5.
}

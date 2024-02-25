/*
 * =====================================================================================
 *
 *       Filename:  find_all_people.cpp
 *
 *    Description:  2092. Find All People With Secret.
 *                  https://leetcode.com/problems/find-all-people-with-secret/
 *
 *        Version:  1.0
 *        Created:  02/25/2024 17:46:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <map>
#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::tuple;
using std::vector;

class UnionFind {
 public:
  UnionFind(int n) : count_(n), parent_(n), rank_(n) {
    for (int i = 0; i < n; i++) {
      parent_[i] = i;
    }
  }

  int find(int i) const {
    while (i != parent_[i]) {
      i = parent_[i];
    }
    return i;
  }

  void connect(int a, int b) {
    int i = find(a);
    int j = find(b);
    if (i == j) {
      return;
    }
    if (rank_[i] > rank_[j]) {
      parent_[j] = i;
    } else if (rank_[i] < rank_[j]) {
      parent_[i] = j;
    } else {
      parent_[j] = i;
      rank_[i]++;
    }
  }

  void reset(int x) {
    if (parent_[x] != x) {
      parent_[x] = x;
      count_++;
    }
  }

  bool isConnected(int a, int b) const { return find(a) == find(b); }

 private:
  int count_;
  vector<int> parent_;
  vector<int> rank_;
};

class Solution {
 public:
  vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    UnionFind uf(n);
    uf.connect(0, firstPerson);

    // Group meetings in increasing order of time
    std::map<int, vector<std::pair<int, int>>> same_time_mtgs;
    for (vector<int>& m : meetings) {
      same_time_mtgs[m[2]].emplace_back(m[0], m[1]);
    }

    for (auto& [t, mtgs] : same_time_mtgs) {
      for (auto& m : mtgs) {
        uf.connect(m.first, m.second);
      }
      for (auto& m : mtgs) {
        if (!uf.isConnected(0, m.first)) {
          uf.reset(m.first);
          uf.reset(m.second);
        }
      }
    }

    vector<int> people{0};
    for (int i = 1; i < n; i++) {
      if (uf.isConnected(0, i)) {
        people.push_back(i);
      }
    }
    return people;
  }
};

TEST(Solution, findAllPeople) {
  vector<tuple<int, vector<vector<int>>, int, vector<int>>> cases = {
      std::make_tuple(6, vector<vector<int>>{{1, 2, 5}, {2, 3, 8}, {1, 5, 10}}, 1,
                      vector<int>{0, 1, 2, 3, 5}),
      std::make_tuple(4, vector<vector<int>>{{3, 1, 3}, {1, 2, 2}, {0, 3, 3}}, 3,
                      vector<int>{0, 1, 3}),
      std::make_tuple(5, vector<vector<int>>{{3, 4, 2}, {1, 2, 1}, {2, 3, 1}}, 1,
                      vector<int>{0, 1, 2, 3, 4}),
      std::make_tuple(5, vector<vector<int>>{{1, 4, 3}, {0, 4, 3}}, 3, vector<int>{0, 1, 3, 4}),
      std::make_tuple(6, vector<vector<int>>{{0, 2, 1}, {1, 3, 1}, {4, 5, 1}}, 1,
                      vector<int>{0, 1, 2, 3}),
  };
  for (auto& c : cases) {
    EXPECT_THAT(Solution().findAllPeople(std::get<0>(c), std::get<1>(c), std::get<2>(c)),
                testing::UnorderedElementsAreArray(std::get<3>(c)));
  }
}

/*
 * =====================================================================================
 *
 *       Filename:  course_schedule.cpp
 *
 *    Description:  207. Course Schedule. https://leetcode.com/problems/course-schedule/
 *
 *        Version:  1.0
 *        Created:  04/06/23 15:24:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace std;

class Graph {
 public:
  Graph(const int n) : nodes_(n), edges_(n) {}

  void addEdge(const int from, const int to) { edges_[from].push_back(to); }

  bool isAcyclic() const {
    vector<bool> visiting(nodes_, false);
    vector<bool> visited(nodes_, false);
    for (int i = 0; i < nodes_; i++) {
      if (visited[i]) {
        continue;
      }
      if (dfsCyclic(i, visiting, visited)) {
        return false;
      }
    }
    return true;
  }

 private:
  // Traverse and check cycle by dfs
  bool dfsCyclic(const int node, vector<bool>& visiting, vector<bool>& visited) const {
    if (visiting[node]) {
      return true;
    }
    if (visited[node]) {
      return false;
    }
    visiting[node] = true;
    visited[node] = true;
    for (const auto& adj : edges_[node]) {
      if (dfsCyclic(adj, visiting, visited)) {
        return true;
      }
    }
    visiting[node] = false;
    return false;
  }

 private:
  vector<vector<int>> edges_;
  int nodes_;
};

// Depth first search in topological sorting
class Solution {
 public:
  bool canFinish(int num, vector<vector<int>>& prerequisites) {
    Graph g(num);
    for (const auto& p : prerequisites) {
      g.addEdge(p[1], p[0]);
    }
    return g.isAcyclic();
  }
};

TEST(Solution, canFinish) {
  vector<tuple<int, vector<vector<int>>, bool>> cases = {
      make_tuple(2, vector<vector<int>>{{1, 0}}, true),
      make_tuple(2, vector<vector<int>>{{1, 0}, {0, 1}}, false),
  };
  for (auto& [n, p, finish] : cases) {
    EXPECT_EQ(Solution().canFinish(n, p), finish);
  }
}

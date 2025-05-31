/*
 * =====================================================================================
 *
 *       Filename:  cloest_meeting_node.cpp
 *
 *    Description:  2359. Find Closest Node to Given Two Nodes
 *                  https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
 *
 *        Version:  1.0
 *        Created:  05/31/2025 23:58:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <queue>
#include <tuple>
#include <vector>

#include "gtest/gtest.h"

class Solution {
 public:
  int closestMeetingNode(std::vector<int>& edges, int node1, int node2) {
    if (node1 == node2) {
      return node1;
    }

    const int size = edges.size();
    std::vector<int> path1(size, -1);
    std::vector<int> path2(size, -1);

    // Breadth first search from node1, node2
    bfsVisit(edges, node1, path1);
    bfsVisit(edges, node2, path2);

    int min_dis = INT_MAX;
    int index = -1;
    for (int i = 0; i < size; i++) {
      if (path1[i] == -1 || path2[i] == -1) {
        continue;
      }
      const int cur_dis = std::max(path1[i], path2[i]);
      if (cur_dis < min_dis) {
        min_dis = cur_dis;
        index = i;
      }
    }
    return index;
  }

 private:
  void bfsVisit(const std::vector<int>& edges, const int from, std::vector<int>& path) {
    std::queue<int> nodes;
    int distance = 0;
    nodes.push(from);
    while (!nodes.empty()) {
      const int i = nodes.front();
      if (path[i] != -1) {
        // Visited
        break;
      }

      nodes.pop();
      path[i] = distance++;
      if (edges[i] != -1) {
        nodes.push(edges[i]);
      }
    }
  }
};

TEST(Solution, closestMeetingNode) {
  std::vector<std::tuple<std::vector<int>, int, int, int>> cases = {
      {{2, 2, 3, -1}, 0, 1, 2},
      {{1, 2, -1}, 0, 2, 2},
      {{4, 4, 8, -1, 9, 8, 4, 4, 1, 1}, 5, 6, 1},
  };
  for (auto& [edges, node1, node2, index] : cases) {
    EXPECT_EQ(Solution().closestMeetingNode(edges, node1, node2), index);
  }
}

/*
 * =====================================================================================
 *
 *       Filename:  average_of_levels.cpp
 *
 *    Description:  637. Average of Levels in Binary Tree
 *                  https://leetcode.com/problems/average-of-levels-in-binary-tree/
 *
 *        Version:  1.0
 *        Created:  10/09/2025 17:22:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <map>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  std::vector<double> averageOfLevels(TreeNode* root) {
    std::map<int, std::pair<int, int64_t>> sums;
    dfsTraverse(root, 1, sums);

    std::vector<double> averages(sums.size(), 0.0);
    for (auto [key, p] : sums) {
      averages[key - 1] = static_cast<double>(p.second) / p.first;
    }
    return averages;
  }

  void dfsTraverse(TreeNode* root, int level, std::map<int, std::pair<int, int64_t>>& sums) {
    if (root == nullptr) {
      return;
    }

    sums[level].first++;
    sums[level].second += root->val;
    dfsTraverse(root->left, level + 1, sums);
    dfsTraverse(root->right, level + 1, sums);
  }
};

TEST(Solution, averageOfLevels) {
  TreeNode* root = nullptr;
  EXPECT_EQ(Solution().averageOfLevels(root), std::vector<double>{});
}

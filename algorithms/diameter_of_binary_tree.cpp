/*
 * =====================================================================================
 *
 *       Filename:  diameter_of_binary_tree.cpp
 *
 *    Description:  543. Diameter of Binary Tree.
 *                  https://leetcode.com/problems/diameter-of-binary-tree/
 *
 *        Version:  1.0
 *        Created:  02/16/2023 22:12:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <utility>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  static TreeNode* convert(const std::vector<int*>& nums, const int i = 0) {
    if (i >= nums.size() || nums[i] == nullptr) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(*nums[i]);
    root->left = convert(nums, 2 * i + 1);
    root->right = convert(nums, 2 * i + 2);
    return root;
  }
};

// Depth first search
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    dfsTraverse(root, diameter);
    return diameter;
  }

  int dfsTraverse(TreeNode* root, int& diameter) {
    if (root == nullptr) {
      return 0;
    }
    const int l = dfsTraverse(root->left, diameter);
    const int r = dfsTraverse(root->right, diameter);
    diameter = std::max(diameter, l + r);
    return (std::max(l, r) + 1);
  }
};

TEST(Solution, diameterOfBinaryTree) {
#define _N(x) new int(x)
  std::vector<std::pair<TreeNode*, int>> cases = {
      std::make_pair(TreeNode::convert(std::vector<int*>{_N(1), _N(2), _N(3), _N(4), _N(5)}), 3),
      std::make_pair(TreeNode::convert(std::vector<int*>{_N(1), _N(2)}), 1),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().diameterOfBinaryTree(c.first), c.second);
  }
#undef _N
}

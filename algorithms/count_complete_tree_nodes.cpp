/*
 * =====================================================================================
 *
 *       Filename:  count_complete_tree_nodes.cpp
 *
 *    Description:  222. Count Complete Tree Nodes.
 *                  https://leetcode.com/problems/count-complete-tree-nodes/
 *
 *        Version:  1.0
 *        Created:  02/25/23 21:45:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}

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

// Depth first search, O(N)
class Solution1 {
 public:
  int countNodes(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    return (1 + countNodes(root->left) + countNodes(root->right));
  }
};

// Depth first search, O(logN*logN)
class Solution2 {
 public:
  int countNodes(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }

    TreeNode* left = root->left;
    TreeNode* right = root->right;
    int lc = 1;
    int rc = 1;
    while (left != nullptr) {
      lc++;
      left = left->left;
    }
    while (right != nullptr) {
      rc++;
      right = right->right;
    }
    if (lc == rc) {
      return ((1 << lc) - 1);
    }
    return (1 + countNodes(root->left) + countNodes(root->right));
  }
};

TEST(Solution, countNodes) {
#define _N(x) new int(x)
  std::vector<std::pair<TreeNode*, int>> cases = {
      std::make_pair(TreeNode::convert(std::vector<int*>{nullptr}), 0),
      std::make_pair(TreeNode::convert(std::vector<int*>{_N(1)}), 1),
      std::make_pair(TreeNode::convert(std::vector<int*>{_N(1), _N(2), _N(3),
                                                         _N(4), _N(5), _N(6)}),
                     6),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution1().countNodes(c.first), c.second);
    EXPECT_EQ(Solution2().countNodes(c.first), c.second);
  }
#undef _N
}

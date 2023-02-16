/*
 * =====================================================================================
 *
 *       Filename:  balanced_binary_tree.cpp
 *
 *    Description:  110. Balanced Binary Tree.
 *                  Given a binary tree, determine if it is height-balanced.
 *
 *        Version:  1.0
 *        Created:  04/12/19 12:42:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

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

class Solution {
 public:
  bool isBalanced(TreeNode* root) { return (checkHeight(root) != -1); }

 private:
  int checkHeight(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }

    int left = checkHeight(node->left);
    if (left == -1) {
      // Left subtree isn't balanced
      return -1;
    }

    int right = checkHeight(node->right);
    if (right == -1) {
      // Right subtree isn't balanced
      return -1;
    }

    if (std::abs(left - right) > 1) {
      // Current tree isn't balanced
      return -1;
    }

    // Return current tree's height
    return std::max(left, right) + 1;
  }
};

TEST(Solution, isBalanced) {
#define _N(x) new int(x)
  std::vector<std::pair<TreeNode*, bool>> cases = {
      std::make_pair(TreeNode::convert(
                         std::vector<int*>{_N(3), _N(9), _N(20), nullptr, nullptr, _N(15), _N(7)}),
                     true),
      std::make_pair(TreeNode::convert(std::vector<int*>{_N(1), _N(2), _N(2), _N(3), _N(3), nullptr,
                                                         nullptr, _N(4), _N(4)}),
                     false),
      std::make_pair(TreeNode::convert(std::vector<int*>{nullptr}), true),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution().isBalanced(c.first), c.second);
  }
#undef _N
}

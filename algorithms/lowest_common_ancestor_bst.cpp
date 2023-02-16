/*
 * =====================================================================================
 *
 *       Filename:  lowest_common_ancestor_bst.cpp
 *
 *    Description:  235. Lowest Common Ancestor of a Binary Search Tree.
 *
 *        Version:  1.0
 *        Created:  02/16/2023 11:14:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include "gmock/gmock.h"
#include "gtest/gtest.h"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
      return root;
    }

    auto* lnode = lowestCommonAncestor(root->left, p, q);
    auto* rnode = lowestCommonAncestor(root->right, p, q);
    if (lnode != nullptr && rnode != nullptr) {
      return root;
    }
    return (lnode != nullptr ? lnode : rnode);
  }
};

TEST(Solution, lowestCommonAncestor) {
  TreeNode* root = nullptr;
  EXPECT_EQ(Solution().lowestCommonAncestor(root, nullptr, nullptr), nullptr);
}

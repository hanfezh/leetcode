/*
 * =====================================================================================
 *
 *       Filename:  balance_bst.cpp
 *
 *    Description:  1382. Balance a Binary Search Tree
 *                  https://leetcode.com/problems/balance-a-binary-search-tree/
 *
 *        Version:  1.0
 *        Created:  06/29/2024 09:29:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::vector;

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
  TreeNode* balanceBST(TreeNode* root) {
    vector<TreeNode*> inorder;
    inorderTraversal(root, inorder);
    return newBalancedTree(inorder, 0, inorder.size() - 1);
  }

 private:
  void inorderTraversal(TreeNode* root, vector<TreeNode*>& inorder) {
    if (root == nullptr) {
      return;
    }
    inorderTraversal(root->left, inorder);
    inorder.push_back(root);
    inorderTraversal(root->right, inorder);
  }

  TreeNode* newBalancedTree(vector<TreeNode*>& inorder, int start, int end) {
    if (start > end) {
      return nullptr;
    }
    const int mid = start + (end - start) / 2;
    TreeNode* left = newBalancedTree(inorder, start, mid - 1);
    TreeNode* right = newBalancedTree(inorder, mid + 1, end);
    TreeNode* root = inorder[mid];
    root->left = left;
    root->right = right;
    return root;
  }
};

TEST(Solution, balanceBST) {
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2, node1, nullptr);
  TreeNode* root = new TreeNode(3, node2, nullptr);
  EXPECT_EQ(Solution().balanceBST(root), node2);
}

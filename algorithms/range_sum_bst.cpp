/*
 * =====================================================================================
 *
 *       Filename:  range_sum_bst.cpp
 *
 *    Description:  938. Range Sum of BST
 *                  https://leetcode.com/problems/range-sum-of-bst/
 *
 *        Version:  1.0
 *        Created:  08/01/2025 22:40:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Depth-first search
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == nullptr) {
      return 0;
    }
    if (root->val < low) {
      return rangeSumBST(root->right, low, high);
    } else if (root->val > high) {
      return rangeSumBST(root->left, low, high);
    }
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
  }
};

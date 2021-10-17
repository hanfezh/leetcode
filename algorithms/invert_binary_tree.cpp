/*
 * =====================================================================================
 *
 *       Filename:  invert_binary_tree.cpp
 *
 *    Description:  226. Invert Binary Tree
 *                  https://leetcode.com/problems/invert-binary-tree
 *
 *        Version:  1.0
 *        Created:  10/17/2021 15:07:51
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

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
      return root;
    } else {
      TreeNode* tmp = invertTree(root->right);
      root->right = invertTree(root->left);
      root->left = tmp;
      return root;
    }
  }
};

int main(int argc, char* argv[]) {
  TreeNode* root = nullptr;
  root = Solution().invertTree(root);
  return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  validate_binary_search_tree.cpp
 *
 *    Description:  98. Validate Binary Search Tree. Given a binary tree, determine if
 *                  it is a valid binary search tree (BST).
 *
 *        Version:  1.0
 *        Created:  02/28/19 01:50:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <stack>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive
class Solution1 {
 public:
  bool isValidBST(TreeNode* root) { return doValidate(root, NULL, NULL); }

 private:
  bool doValidate(TreeNode* node, TreeNode* min, TreeNode* max) {
    if (node == NULL) {
      return true;
    }
    if ((min != NULL && node->val <= min->val) || (max != NULL && node->val >= max->val)) {
      return false;
    }
    return (doValidate(node->left, min, node) && doValidate(node->right, node, max));
  }
};

// Inorder traversal
class Solution2 {
 public:
  bool isValidBST(TreeNode* root) {
    TreeNode* pre = nullptr;
    std::stack<TreeNode*> nodes;

    while (root != nullptr || !nodes.empty()) {
      while (root != nullptr) {
        nodes.push(root);
        root = root->left;
      }

      root = nodes.top();
      nodes.pop();
      if (pre != nullptr && pre->val >= root->val) {
        return false;
      }
      pre = root;
      root = root->right;
    }

    return true;
  }
};

using Solution = Solution2;

int main(int argc, char* argv[]) {
  TreeNode* root = NULL;
  auto valid = Solution().isValidBST(root);
  printf("Is a valid binary search tree? %s\n", (valid ? "Yes" : "No"));
  return 0;
}

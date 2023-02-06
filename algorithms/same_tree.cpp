/*
 * =====================================================================================
 *
 *       Filename:  same_tree.cpp
 *
 *    Description:  Same Tree. Given two binary trees, write a function to check if they
 *                  are the same or not.
 *
 *        Version:  1.0
 *        Created:  02/21/19 01:46:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <queue>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Recursion
class Solution1 {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
      return true;
    } else if (p == nullptr || q == nullptr) {
      return false;
    } else if (p->val != q->val) {
      return false;
    }
    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
  }
};

// Iteration, preorder traversal
class Solution2 {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    std::queue<TreeNode*> p_nodes;
    std::queue<TreeNode*> q_nodes;
    p_nodes.push(p);
    q_nodes.push(q);
    while (!p_nodes.empty()) {
      p = p_nodes.front();
      q = q_nodes.front();
      if (!checkNode(p, q)) {
        return false;
      }
      p_nodes.pop();
      q_nodes.pop();
      if (p != nullptr) {
        p_nodes.push(p->left);
        p_nodes.push(p->right);
        q_nodes.push(q->left);
        q_nodes.push(q->right);
      }
    }
    return true;
  }

 private:
  bool checkNode(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
      return true;
    } else if (p == nullptr || q == nullptr) {
      return false;
    } else {
      return (p->val == q->val);
    }
  }
};

int main(int argc, char* argv[]) {
  TreeNode* a = nullptr;
  TreeNode* b = nullptr;
  auto is_same = Solution2().isSameTree(a, b);
  printf("Same tree? %s\n", (is_same ? "Yes" : "No"));
  return 0;
}

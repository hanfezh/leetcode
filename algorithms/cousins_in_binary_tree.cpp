/*
 * =====================================================================================
 *
 *       Filename:  cousins_in_binary_tree.cpp
 *
 *    Description:  993. Cousins in Binary Tree.
 *                  https://leetcode.com/problems/cousins-in-binary-tree
 *
 *        Version:  1.0
 *        Created:  10/18/2021 22:14:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
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

// DFS
class Solution {
 public:
  bool isCousins(TreeNode* root, int x, int y) {
    std::queue<TreeNode*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
      bool found_x = false;
      bool found_y = false;
      bool is_cousin = false;
      const int size = nodes.size();
      for (int i = 0; i < size; i++) {
        TreeNode* ptr = nodes.front();
        nodes.pop();
        if ((found_x ^ found_y) && (i % 2 == 0)) {
          is_cousin = true;
        }
        if (ptr == nullptr) {
          continue;
        }
        if (ptr->val == x) {
          found_x = true;
        } else if (ptr->val == y) {
          found_y = true;
        }
        if (found_x && found_y && is_cousin) {
          return true;
        }
        nodes.push(ptr->left);
        nodes.push(ptr->right);
      }
    }
    return false;
  }
};

int main(int argc, char* argv[]) {
  TreeNode* root = nullptr;
  const bool is_cousin = Solution().isCousins(root, 4, 5);
  printf("Is counsin? %s\n", (is_cousin ? "Yes" : "No"));
  return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  binary_tree_level_order_traversal.cpp
 *
 *    Description:  102. Binary Tree Level Order Traversal.
 *                  Given a binary tree, return the level order traversal of its nodes'
 *                  values. (ie, from left to right, level by level).
 *
 *        Version:  1.0
 *        Created:  07/12/2019 02:32:24 PM
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
#include <vector>

using std::vector;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Intuitive DFS
class Solution1 {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> values;
    std::queue<TreeNode*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
      std::vector<int> nums;
      int size = nodes.size();
      while (size-- > 0) {
        TreeNode* ptr = nodes.front();
        nodes.pop();
        if (ptr == nullptr) {
          continue;
        }
        nums.push_back(ptr->val);
        nodes.push(ptr->left);
        nodes.push(ptr->right);
      }
      if (nums.size() > 0) {
        values.push_back(nums);
      }
    }
    return values;
  }
};

// Optimized BFS
class Solution2 {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> values;
    bfsTraverse(root, 0, &values);
    return values;
  }

 private:
  void bfsTraverse(TreeNode* node, int depth, vector<vector<int>>* values) {
    if (node == NULL) {
      return;
    }
    if (depth == values->size()) {
      // Append new element
      values->emplace_back();
    }

    values->at(depth).push_back(node->val);
    bfsTraverse(node->left, depth + 1, values);
    bfsTraverse(node->right, depth + 1, values);
  }
};

using Solution = Solution1;

int main(int argc, char* argv[]) {
  TreeNode* root = NULL;
  auto values = Solution().levelOrder(root);
  printf("Values's size %ld\n", values.size());
  return 0;
}

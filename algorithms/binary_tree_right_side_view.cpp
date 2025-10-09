// =====================================================================================
//
//       Filename:  binary_tree_right_side_view.cpp
//
//    Description:  199. Binary Tree Right Side View. Given a binary tree, imagine
//                  yourself standing on the right side of it, return the values of the
//                  nodes you can see ordered from top to bottom.
//
//        Version:  1.0
//        Created:  09/11/2019 07:47:47 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:
//
// =====================================================================================
#include <stdio.h>
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution1 {
 public:
  std::vector<int> rightSideView(TreeNode* root) {
    if (root == nullptr) {
      return std::vector<int>();
    }

    std::vector<int> values;
    std::queue<TreeNode*> nodes;

    nodes.push(root);
    while (!nodes.empty()) {
      values.push_back(nodes.back()->val);
      int len = nodes.size();
      while (len > 0) {
        auto* cur = nodes.front();
        if (cur->left != nullptr) {
          nodes.push(cur->left);
        }
        if (cur->right != nullptr) {
          nodes.push(cur->right);
        }

        nodes.pop();
        len--;
      }
    }

    return values;
  }
};

// Depth-first search
class Solution1 {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> values;
    dfsTraverse(root, 1, values);
    return values;
  }

  void dfsTraverse(TreeNode* root, int level, vector<int>& values) {
    if (root == nullptr) {
      return;
    }
    if (values.size() < level) {
      values.push_back(root->val);
    }
    dfsTraverse(root->right, level + 1, values);
    dfsTraverse(root->left, level + 1, values);
  }
};

int main(int argc, char* argv[]) {
  TreeNode* root = nullptr;
  auto values1 = Solution1().rightSideView(root);
  auto values2 = Solution2().rightSideView(root);
  printf("Tree's height = %lu\n", values1.size());
  printf("Tree's height = %lu\n", values2.size());
  return 0;
}

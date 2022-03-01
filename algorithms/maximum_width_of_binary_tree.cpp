/*
 * =====================================================================================
 *
 *       Filename:  maximum_width_of_binary_tree.cpp
 *
 *    Description:  662. Maximum Width of Binary Tree
 *                  https://leetcode.com/problems/maximum-width-of-binary-tree/
 *
 *        Version:  1.0
 *        Created:  03/01/2022 09:08:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <queue>
#include <utility>

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
  int widthOfBinaryTree(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }

    uint64_t width = 0;
    std::queue<std::pair<TreeNode*, uint64_t>> nodes;
    nodes.push(std::make_pair(root, 0));
    while (not nodes.empty()) {
      width = std::max(width, nodes.back().second - nodes.front().second + 1);
      int size = nodes.size();
      while (size-- > 0) {
        auto cur = nodes.front();
        if (cur.first->left != nullptr) {
          nodes.push(std::make_pair(cur.first->left, cur.second * 2 + 1));
        }
        if (cur.first->right != nullptr) {
          nodes.push(std::make_pair(cur.first->right, cur.second * 2 + 2));
        }
        nodes.pop();
      }
    }
    return static_cast<int>(width);
  }
};

int main(int argc, char* argv[]) {
  TreeNode* root = nullptr;
  const int width = Solution().widthOfBinaryTree(root);
  assert(width == 0);
  return 0;
}

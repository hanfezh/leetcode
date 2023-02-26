/*
 * =====================================================================================
 *
 *       Filename:  kth_smallest_element.cpp
 *
 *    Description:  230. Kth Smallest Element in a BST.
 *                  https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 *
 *        Version:  1.0
 *        Created:  02/26/23 10:58:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stack>
#include <tuple>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}

  static TreeNode *convert(const std::vector<int *> &nums, const int i = 0) {
    if (i >= nums.size() || nums[i] == nullptr) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(*nums[i]);
    root->left = convert(nums, 2 * i + 1);
    root->right = convert(nums, 2 * i + 2);
    return root;
  }
};

// Inorder traversal by breadth first search
class Solution {
 public:
  int kthSmallest(TreeNode *root, int k) {
    std::stack<TreeNode *> nodes;
    while (root != nullptr || !nodes.empty()) {
      while (root != nullptr) {
        nodes.push(root);
        root = root->left;
      }

      root = nodes.top();
      if (--k == 0) {
        return root->val;
      }
      nodes.pop();
      root = root->right;
    }

    return -1;
  }
};

TEST(Solution, kthSmallest) {
#define _N(x) new int(x)
  std::vector<std::tuple<TreeNode *, int, int>> cases = {
      std::make_tuple(TreeNode::convert(std::vector<int *>{_N(3), _N(1), _N(4),
                                                           nullptr, _N(2)}),
                      1, 1),
      std::make_tuple(
          TreeNode::convert(std::vector<int *>{_N(5), _N(3), _N(6), _N(2),
                                               _N(4), nullptr, nullptr, _N(1)}),
          3, 3),
  };
  for (auto &c : cases) {
    EXPECT_EQ(Solution().kthSmallest(std::get<0>(c), std::get<1>(c)),
              std::get<2>(c));
  }
#undef _N
}

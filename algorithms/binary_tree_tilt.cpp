/*
 * =====================================================================================
 *
 *       Filename:  binary_tree_tilt.cpp
 *
 *    Description:  563. Binary Tree Tilt.
 *                  https://leetcode.com/problems/binary-tree-tilt/
 *
 *        Version:  1.0
 *        Created:  02/25/23 10:25:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <utility>
#include <vector>

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

// Depth first search
class Solution {
 public:
  int findTilt(TreeNode *root) {
    int tilt = 0;
    dfsSum(root, tilt);
    return tilt;
  }

  int dfsSum(TreeNode *root, int &tilt) {
    if (root == nullptr) {
      return 0;
    }

    const int a = dfsSum(root->left, tilt);
    const int b = dfsSum(root->right, tilt);
    tilt += std::abs(a - b);
    return (root->val + a + b);
  }
};

TEST(Solution, findTilt) {
#define _N(x) new int(x)
  std::vector<std::pair<TreeNode *, int>> cases = {
      std::make_pair(TreeNode::convert(std::vector<int *>{_N(1), _N(2), _N(3)}),
                     1),
      std::make_pair(TreeNode::convert(std::vector<int *>{
                         _N(4), _N(2), _N(9), _N(3), _N(5), nullptr, _N(7)}),
                     15),
      std::make_pair(
          TreeNode::convert(std::vector<int *>{
              _N(21), _N(7), _N(14), _N(1), _N(1), _N(2), _N(2), _N(3), _N(3)}),
          9),
  };
  for (auto &c : cases) {
    EXPECT_EQ(Solution().findTilt(c.first), c.second);
  }
#undef _N
}

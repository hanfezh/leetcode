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
#include <queue>
#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  static TreeNode* convert(const std::vector<int*>& nums, const int i = 0) {
    if (i >= nums.size() || nums[i] == nullptr) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(*nums[i]);
    root->left = convert(nums, 2 * i + 1);
    root->right = convert(nums, 2 * i + 2);
    return root;
  }
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

TEST(Solution, isSameTree) {
#define _N(x) new int(x)
  std::vector<std::tuple<TreeNode*, TreeNode*, bool>> cases = {
      std::make_tuple(TreeNode::convert(std::vector<int*>{_N(1), _N(2), _N(3)}),
                      TreeNode::convert(std::vector<int*>{_N(1), _N(2), _N(3)}), true),
      std::make_tuple(TreeNode::convert(std::vector<int*>{_N(1), _N(1), _N(2)}),
                      TreeNode::convert(std::vector<int*>{_N(1), _N(2), _N(1)}), false),
      std::make_tuple(TreeNode::convert(std::vector<int*>{_N(1), nullptr, _N(2)}),
                      TreeNode::convert(std::vector<int*>{_N(1), nullptr, _N(2)}), true),
  };
  for (auto& c : cases) {
    EXPECT_EQ(Solution1().isSameTree(std::get<0>(c), std::get<1>(c)), std::get<2>(c));
    EXPECT_EQ(Solution2().isSameTree(std::get<0>(c), std::get<1>(c)), std::get<2>(c));
  }
#undef _N
}

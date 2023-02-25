/*
 * =====================================================================================
 *
 *       Filename:  recover_binary_search_tree.cpp
 *
 *    Description:  99. Recover Binary Search Tree.
 *                  https://leetcode.com/problems/recover-binary-search-tree/
 *
 *        Version:  1.0
 *        Created:  02/25/23 12:13:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}

  static TreeNode* convert(const std::vector<int*>& nums, const int i = 0) {
    if (i >= nums.size() || nums[i] == nullptr) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(*nums[i]);
    root->left = convert(nums, 2 * i + 1);
    root->right = convert(nums, 2 * i + 2);
    return root;
  }

  static std::vector<int> visitInorder(TreeNode* root) {
    std::vector<int> nums;
    std::stack<TreeNode*> nodes;
    while (root != nullptr || !nodes.empty()) {
      while (root != nullptr) {
        nodes.push(root);
        root = root->left;
      }

      root = nodes.top();
      nums.push_back(root->val);
      nodes.pop();
      root = root->right;
    }
    return nums;
  }
};

// In-order traversal by depth first search
class Solution {
 public:
  void recoverTree(TreeNode* root) {
    dfsTraversal(root);
    std::swap(first->val, second->val);
  }

 private:
  void dfsTraversal(TreeNode* root) {
    if (root == nullptr) {
      return;
    }

    dfsTraversal(root->left);

    if (first == nullptr && prev != nullptr && prev->val > root->val) {
      first = prev;
    }
    if (first != nullptr && prev->val > root->val) {
      second = root;
    }
    prev = root;

    dfsTraversal(root->right);
  }

 private:
  TreeNode* prev = nullptr;
  TreeNode* first = nullptr;
  TreeNode* second = nullptr;
};

TEST(Solution, recoverTree) {
#define _N(x) new int(x)
  std::vector<std::pair<TreeNode*, std::vector<int>>> cases = {
      std::make_pair(TreeNode::convert(std::vector<int*>{_N(1), _N(3), nullptr,
                                                         nullptr, _N(2)}),
                     std::vector<int>{1, 2, 3}),
      std::make_pair(TreeNode::convert(std::vector<int*>{
                         _N(3), _N(1), _N(4), nullptr, nullptr, _N(2)}),
                     std::vector<int>{1, 2, 3, 4}),
  };
  for (auto& c : cases) {
    Solution().recoverTree(c.first);
    EXPECT_THAT(TreeNode::visitInorder(c.first),
                testing::ElementsAreArray(c.second));
  }
#undef _N
}

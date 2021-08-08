// 112. Path Sum: https://leetcode.com/problems/path-sum/
// Author: xianfeng.zhu@gmail.com

#include <cassert>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr) {
      return false;
    } else if (root->left == nullptr && root->right == nullptr) {
      return (sum == root->val);
    }
    sum -= root->val;
    return (hasPathSum(root->left, sum) || hasPathSum(root->right, sum));
  }
};

int main(int argc, char* argv[]) {
  TreeNode* root = nullptr;
  int sum = 0;
  const bool ret = Solution().hasPathSum(root, sum);
  assert(not ret);
  return 0;
}

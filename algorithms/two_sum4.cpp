/*
 * =====================================================================================
 *
 *       Filename:  two_sum4.cpp
 *
 *    Description:  Two Sum IV - Input is a BST.
 *
 *        Version:  1.0
 *        Created:  03/04/19 07:55:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <map>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
 public:
  bool findTarget(TreeNode* root, int target) {
    std::vector<int> numbers;
    traverse(root, numbers);

    for (int low = 0, high = numbers.size() - 1; (low < numbers.size() - 1) && (low < high);) {
      int left = target - numbers[high];
      if (left < numbers[low]) {
        high--;
      } else if (left > numbers[low]) {
        low++;
      } else {
        // left == numbers[low]
        return true;
      }
    }

    return false;
  }

 private:
  void traverse(TreeNode* node, std::vector<int>& numbers) {
    if (node == NULL) {
      return;
    }
    traverse(node->left, numbers);
    numbers.push_back(node->val);
    traverse(node->right, numbers);
  }
};

// Hash table
class Solution2 {
 public:
  bool findTarget(TreeNode* root, int target) {
    std::map<int, int> values;
    traverse(root, values);
    for (const auto& item: values) {
      const int left = target - item.first;
      if (left == item.first) {
        return (item.second > 1);
      }
      const auto iter = values.find(left);
      if (iter != values.end()) {
        return true;
      }
    }
    return false;
  }

  void traverse(TreeNode* node, std::map<int, int>& values) {
    if (node == nullptr) {
      return;
    }
    traverse(node->left, values);
    values[node->val] += 1;
    traverse(node->right, values);
  }
};

using Solution = Solution2;

int main(int argc, char* argv[]) {
  TreeNode* root = NULL;
  auto found = Solution().findTarget(root, 9);
  return 0;
}

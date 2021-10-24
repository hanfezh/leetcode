/*
 * =====================================================================================
 *
 *       Filename:  nary_tree_level_order_traversal.cpp
 *
 *    Description:  429. N-ary Tree Level Order Traversal.
 *                  https://leetcode.com/problems/n-ary-tree-level-order-traversal
 *
 *        Version:  1.0
 *        Created:  10/24/2021 16:44:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cassert>
#include <queue>
#include <vector>

class Node {
 public:
  int val;
  std::vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, std::vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

// BFS traversal
class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(Node* root) {
    std::vector<std::vector<int>> values;
    std::queue<Node*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
      std::vector<int> nums;
      int size = nodes.size();
      while (size-- > 0) {
        Node* ptr = nodes.front();
        nodes.pop();
        if (ptr == nullptr) {
          continue;
        }
        nums.push_back(ptr->val);
        for (Node* node : ptr->children) {
          nodes.push(node);
        }
      }
      if (nums.size() > 0) {
        values.push_back(nums);
      }
    }
    return values;
  }
};

int main(int argc, char* argv[]) {
  Node* root = nullptr;
  auto values = Solution().levelOrder(root);
  assert(values.size() == 0);
  return 0;
}


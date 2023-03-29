/*
 * =====================================================================================
 *
 *       Filename:  clone_graph.cpp
 *
 *    Description:  133. Clone Graph. https://leetcode.com/problems/clone-graph/
 *
 *        Version:  1.0
 *        Created:  03/29/23 21:42:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <queue>
#include <unordered_map>
#include <vector>

using std::queue;
using std::unordered_map;
using std::vector;

class Node {
 public:
  int val;
  vector<Node*> neighbors;

  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }

  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }

  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

// Depth first search
class Solution1 {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return node;
    }

    auto it = all_nodes_.find(node);
    if (it != all_nodes_.end()) {
      return it->second;
    }

    Node* clone = new Node(node->val);
    all_nodes_[node] = clone;
    for (auto* n : node->neighbors) {
      clone->neighbors.push_back(cloneGraph(n));
    }
    return clone;
  }

 private:
  unordered_map<Node*, Node*> all_nodes_;
};

// Breadth first search
class Solution2 {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return node;
    }

    // Visit first node
    unordered_map<Node*, Node*> visited = {{node, new Node(node->val)}};
    queue<Node*> nodes;
    nodes.push(node);

    while (!nodes.empty()) {
      int size = nodes.size();
      while (size-- > 0) {
        Node* p = nodes.front();
        nodes.pop();
        for (auto* n : p->neighbors) {
          auto it = visited.find(n);
          if (it == visited.end()) {
            Node* clone = new Node(n->val);
            visited[n] = clone;
            visited[p]->neighbors.push_back(clone);
            nodes.push(n);
          } else {
            visited[p]->neighbors.push_back(it->second);
          }
        }
      }
    }
    return visited[node];
  }
};

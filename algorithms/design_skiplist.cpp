/*
 * =====================================================================================
 *
 *       Filename:  design_skiplist.cpp
 *
 *    Description:  1206. Design Skiplist, https://leetcode.com/problems/design-skiplist
 *
 *        Version:  1.0
 *        Created:  10/01/2021 14:49:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>

struct Node {
  int val;
  std::vector<Node*> next;
  explicit Node(int num, int size) : val(num), next(size, nullptr) {}
};

// Random level
class Skiplist {
 public:
  Skiplist() : head_(0, kMaxLevel) { std::srand(std::time(nullptr)); }

  bool search(int num) {
    Node* node = &head_;
    for (int i = cur_level_ - 1; i >= 0; i--) {
      node = findClosest(node, i, num);
      if (node->next[i] != nullptr && node->next[i]->val == num) {
        return true;
      }
    }
    return false;
  }

  void add(int num) {
    const int level = randomLevel();
    Node* node = &head_;
    Node* newNode = new Node(num, level);
    for (int i = cur_level_ - 1; i >= 0; i--) {
      node = findClosest(node, i, num);
      if (i < level) {
        if (node->next[i] == nullptr) {
          node->next[i] = newNode;
        } else {
          newNode->next[i] = node->next[i];
          node->next[i] = newNode;
        }
      }
    }
    if (level > cur_level_) {
      for (int i = cur_level_; i < level; i++) {
        head_.next[i] = newNode;
      }
      cur_level_ = level;
    }
  }

  bool erase(int num) {
    std::vector<Node*> prevs(cur_level_);
    Node* node = &head_;
    for (int i = cur_level_ - 1; i >= 0; i--) {
      node = findClosest(node, i, num);
      prevs[i] = node;
    }

    Node* target = prevs[0]->next[0];
    if (target == nullptr || target->val != num) {
      // Not exists
      return false;
    }

    // Erase target node and free memory
    for (int i = 0; i < cur_level_; i++) {
      if (prevs[i]->next[i] == target) {
        prevs[i]->next[i] = target->next[i];
      }
    }
    delete target;

    // Update current level
    while (cur_level_ > 1 && head_.next[cur_level_ - 1] == nullptr) {
      cur_level_--;
    }

    return true;
  }

 private:
  Node* findClosest(Node* head, int level, int val) {
    Node* ptr = head;
    while (ptr->next[level] != nullptr && ptr->next[level]->val < val) {
      ptr = ptr->next[level];
    }
    return ptr;
  }

  int randomLevel() {
    auto factor = []() -> double { return static_cast<double>(std::rand()) / RAND_MAX; };
    int level = 1;
    while (factor() < kRandFactor && level < kMaxLevel) {
      level++;
    }
    return level;
  }

 private:
  const int kMaxLevel = 32;
  const double kRandFactor = 0.25f;
  int cur_level_ = 1;
  Node head_;
};

int main(int argc, char* argv[]) {
  const int target = 3;
  Skiplist sk_list;
  sk_list.add(target);
  const bool exist = sk_list.search(target);
  printf("search %d -> %d\n", target, exist);
  return 0;
}

// =====================================================================================
//
//       Filename:  copy_list_with_random_pointer.cpp
//
//    Description:  138. Copy List with Random Pointer.
//
//        Version:  1.0
//        Created:  09/10/2019 08:34:53 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:
//
// =====================================================================================
#include <cstdio>
#include <unordered_map>

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node() {}

  Node(int _val, Node* _next = nullptr, Node* _random = nullptr) {
    val = _val;
    next = _next;
    random = _random;
  }
};

class Solution1 {
 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) {
      return nullptr;
    }

    int num = 0;
    Node* copy = nullptr;
    Node* ptr1 = head;
    Node* ptr2 = nullptr;
    Node* tail1 = nullptr;
    Node* tail2 = nullptr;

    // Copy linked list
    while (ptr1 != nullptr) {
      auto* node = new Node(ptr1->val, nullptr, nullptr);
      if (ptr2 == nullptr) {
        copy = node;
      } else {
        ptr2->next = node;
      }

      num++;
      ptr2 = node;
      tail1 = ptr1;
      tail2 = ptr2;
      ptr1 = ptr1->next;
    }

    // Link tail and head
    tail1->next = head;
    tail2->next = copy;

    // Copy random pointer
    ptr1 = head;
    ptr2 = copy;
    while (num > 0) {
      if (ptr1->random == nullptr) {
        ptr2->random = nullptr;
      } else {
        auto* p = ptr1;
        auto* q = ptr2;
        while (p != ptr1->random) {
          p = p->next;
          q = q->next;
        }

        // Found random
        ptr2->random = q;
      }

      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
      num--;
    }

    // Unlink tail and head
    tail1->next = nullptr;
    tail2->next = nullptr;

    return copy;
  }
};

// Hash table
class Solution2 {
 public:
  Node* copyRandomList(Node* head) {
    Node dummy(0);
    Node* p = &dummy;
    Node* q = head;
    int i = 0;
    std::unordered_map<Node*, int> indexes;  // index -> address in the original list
    std::unordered_map<int, Node*> mapping;  // node address in the copy list -> index
    while (q != nullptr) {
      p->next = new Node(q->val);
      p = p->next;
      p->random = q->random;
      mapping[i] = p;
      indexes[q] = i++;
      q = q->next;
    }

    p = dummy.next;
    while (p != nullptr) {
      if (p->random != nullptr) {
        p->random = mapping[indexes[p->random]];
      }
      p = p->next;
    }
    return dummy.next;
  }
};

int main(int argc, char* argv[]) {
  Node* head = nullptr;
  Node* copy = Solution2().copyRandomList(head);
  printf("Finish copy: %p\n", copy);
  return 0;
}

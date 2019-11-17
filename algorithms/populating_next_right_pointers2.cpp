// =====================================================================================
//
//       Filename:  populating_next_right_pointers2.cpp
//
//    Description:  117. Populating Next Right Pointers in Each Node II.
//
//        Version:  1.0
//        Created:  08/15/2019 08:51:21 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>

// Definition for a Node.
struct Node
{
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
    {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution
{
public:
    Node* connect(Node* root)
    {
        auto link_node = [](Node** head, Node** tail, Node* node) {
            if (node != nullptr)
            {
                if (*head == nullptr)
                {
                    *head = node;
                }
                if (*tail != nullptr)
                {
                    (*tail)->next = node;
                }
                *tail = node;
            }
        };

        Node* cur = root;
        Node* head = nullptr;
        Node* tail = nullptr;

        while (cur != nullptr)
        {
            head = nullptr;
            tail = nullptr;
            while (cur != nullptr)
            {
                link_node(&head, &tail, cur->left);
                link_node(&head, &tail, cur->right);
                cur = cur->next;
            }

            cur = head;
        }

        return root;
    }
};

int main(int argc, char* argv[])
{
    Node* root = nullptr;
    root = Solution().connect(root);
    return 0;
}

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

// Iterative, BFS
class Solution1
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

// Recursive, DFS
class Solution2
{
public:
    Node* connect(Node* root)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (root->left != nullptr)
        {
            if (root->right != nullptr)
            {
                root->left->next = root->right;
            }
            else
            {
                root->left->next = getNext(root->next);
            }
        }
        if (root->right != nullptr)
        {
            root->right->next = getNext(root->next);
        }

        // Connect subnodes
        connect(root->right);
        connect(root->left);
        return root;
    }

private:
    Node* getNext(Node* node)
    {
        if (node == nullptr) {
            return node;
        } else if (node->left != nullptr) {
            return node->left;
        } else if (node->right != nullptr) {
            return node->right;
        } else {
            return getNext(node->next);
        }
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    Node* root = nullptr;
    root = Solution().connect(root);
    return 0;
}

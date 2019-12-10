// =====================================================================================
//
//       Filename:  populating_next_right_pointers.cpp
//
//    Description:  116. Populating Next Right Pointers in Each Node.
//
//        Version:  1.0
//        Created:  08/15/2019 05:30:52 PM
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

// Recursive
class Solution1
{
public:
    Node* connect(Node* root)
    {
        if (root != nullptr)
        {
            connect(root->left, root->right);
        }

        return root;
    }

private:
    void connect(Node* lnode, Node* rnode)
    {
        if (lnode == nullptr)
        {
            return;
        }

        lnode->next = rnode;
        connect(lnode->left, lnode->right);
        
        if (rnode != nullptr)
        {
            connect(lnode->right, rnode->left);
            connect(rnode->left, rnode->right);
        }
    }
};

// Iterative
class Solution2
{
public:
    Node* connect(Node* root)
    {
        if (root == nullptr)
        {
            return root;
        }

        Node* pre = root;
        Node* cur = nullptr;
        while (pre->left != nullptr)
        {
            cur = pre;
            while (cur != nullptr)
            {
                cur->left->next = cur->right;
                if (cur->next != nullptr)
                {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            pre = pre->left;
        }

        return root;
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    Node* root = nullptr;
    root = Solution().connect(root);
    return 0;
}

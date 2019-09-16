/*
 * =====================================================================================
 *
 *       Filename:  binary_tree_inorder_traversal.cpp
 *
 *    Description:  94. Binary Tree Inorder Traversal. Given a binary tree, return the 
 *                  inorder traversal of its nodes' values.
 *
 *        Version:  1.0
 *        Created:  07/09/2019 02:25:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stack>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive
class Solution1
{
public:
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> values;
        inorderTraversal(root, &values);
        return values;
    }

private:
    void inorderTraversal(TreeNode* node, std::vector<int>* values)
    {
        if (node == nullptr)
        {
            return;
        }

        inorderTraversal(node->left, values);
        values->push_back(node->val);
        inorderTraversal(node->right, values);
    }
};

// Non-recursive
class Solution2
{
public:
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> values;
        std::stack<TreeNode*> nodes;
        TreeNode* ptr = root;

        while (ptr != nullptr || !nodes.empty())
        {
            while (ptr != nullptr)
            {
                nodes.push(ptr);
                ptr = ptr->left;
            }

            // Visit current node
            ptr = nodes.top();
            values.push_back(ptr->val);
            ptr = ptr->right;
            nodes.pop();
        }

        return values;
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    TreeNode* root = nullptr;
    auto values = Solution().inorderTraversal(root);
    printf("Size: %ld\n", values.size());
    return 0;
}

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
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
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
        if (node == NULL)
        {
            return;
        }

        inorderTraversal(node->left, values);
        values->push_back(node->val);
        inorderTraversal(node->right, values);
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = NULL;
    auto values = Solution().inorderTraversal(root);
    printf("Size: %ld\n", values.size());
    return 0;
}

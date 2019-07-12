/*
 * =====================================================================================
 *
 *       Filename:  binary_tree_level_order_traversal.cpp
 *
 *    Description:  102. Binary Tree Level Order Traversal. 
 *                  Given a binary tree, return the level order traversal of its nodes' 
 *                  values. (ie, from left to right, level by level).
 *
 *        Version:  1.0
 *        Created:  07/12/2019 02:32:24 PM
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

using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> values;
        if (root == NULL)
        {
            return values;
        }

        levelOrder(vector<TreeNode*>(1, root), &values);
        return values;
    }

private:
    void levelOrder(const vector<TreeNode*>& parents, vector<vector<int>>* values)
    {
        if (parents.size() == 0)
        {
            return;
        }

        vector<TreeNode*> children;
        vector<int> nums;
        for (auto node: parents)
        {
            nums.push_back(node->val);
            if (node->left != NULL)
            {
                children.push_back(node->left);
            }
            if (node->right != NULL)
            {
                children.push_back(node->right);
            }
        }

        values->push_back(nums);
        levelOrder(children, values);
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = NULL;
    auto values = Solution().levelOrder(root);
    printf("Values's size %ld\n", values.size());
    return 0;
}

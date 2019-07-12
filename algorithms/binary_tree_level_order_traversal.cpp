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

        vector<TreeNode*> parents(1, root);
        levelOrder(&parents, &values);
        return values;
    }

private:
    void levelOrder(vector<TreeNode*>* parents, vector<vector<int>>* values)
    {
        if (parents->size() == 0)
        {
            return;
        }

        vector<int> nums;
        int len = parents->size();
        for (int i = 0; i < len; i++)
        {
            auto node = parents->at(0);
            nums.push_back(node->val);
            if (node->left != NULL)
            {
                parents->push_back(node->left);
            }
            if (node->right != NULL)
            {
                parents->push_back(node->right);
            }
            parents->erase(parents->begin());
        }

        values->push_back(nums);
        levelOrder(parents, values);
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = NULL;
    auto values = Solution().levelOrder(root);
    printf("Values's size %ld\n", values.size());
    return 0;
}

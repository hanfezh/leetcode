/*
 * =====================================================================================
 *
 *       Filename:  path_sum3.cpp
 *
 *    Description:  Path Sum III.
 *                  You are given a binary tree in which each node contains an integer 
 *                  value. Find the number of paths that sum to a given value.
 *
 *        Version:  1.0
 *        Created:  07/02/18 01:50:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string>
#include <vector>

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }

    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    int pathSum(TreeNode* root, int sum)
    {
        if (root == NULL)
        {
            return 0;
        }

        int count = innerSum(root, sum);
        if (root->left != NULL)
        {
            count += pathSum(root->left, sum);
        }
        if (root->right != NULL)
        {
            count += pathSum(root->right, sum);
        }

        return count;
    }

private:
    int innerSum(TreeNode* root, int sum)
    {
        int count = 0;
        if ((sum - root->val) == 0)
        {
            count = 1;
        }

        if (root->left != NULL)
        {
            count += innerSum(root->left, (sum - root->val));
        }
        if (root->right != NULL)
        {
            count += innerSum(root->right, (sum - root->val));
        }

        return count;
    }
};

TreeNode* CreateTree(const std::vector<std::string>& strs)
{
    TreeNode** nodes = new TreeNode*[strs.size()];
    for (size_t i = 0; i < strs.size(); i++)
    {
        nodes[i] = NULL;
    }

    TreeNode* root = NULL;
    for (size_t i = 0; i < strs.size(); i++)
    {
        if (strs[i] == "null")
        {
            continue;
        }

        int val = atoi(strs[i].c_str());
        nodes[i] = new TreeNode(val);

        int parent = (i + 1) / 2 - 1;
        if (parent < 0)
        {
            continue;
        }
        else if (((parent + 1) * 2 - 1) == i)
        {
            nodes[parent]->left = nodes[i];
        }
        else
        {
            nodes[parent]->right = nodes[i];
        }
    }

    root = nodes[0];
    delete[] nodes;
    return root;
}

void DeleteTree(TreeNode* root)
{
    if (root->left != NULL)
    {
        DeleteTree(root->left);
    }
    if (root->right != NULL)
    {
        DeleteTree(root->right);
    }

    delete root;
}

int main(int argc, char* argv[])
{
    std::vector<std::string> strs = {"10", "5", "-3", "3", "2", "null", "11", "3", "-2", "null", "1"};
    if (argc > 1)
    {
        strs.clear();
        for (int i = 1; i < argc; i++)
        {
            strs.push_back(argv[i]);
        }
    }

    TreeNode* root = CreateTree(strs);
    int count = Solution().pathSum(root, 8);
    printf("count of path: %d\n", count);

    DeleteTree(root);
    return 0;
}


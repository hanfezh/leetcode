/*
 * =====================================================================================
 *
 *       Filename:  unique_binary_search_trees2.cpp
 *
 *    Description:  95. Unique Binary Search Trees II. 
 *                  Given an integer n, generate all structurally unique BST's (binary 
 *                  search trees) that store values 1 ... n.
 *
 *        Version:  1.0
 *        Created:  05/03/19 03:39:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
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
    std::vector<TreeNode*> generateTrees(int n)
    {
        if (n < 1)
        {
            return std::vector<TreeNode*>();
        }
        return buildTrees(1, n);
    }

private:
    std::vector<TreeNode*> buildTrees(int start, int end)
    {
        if (start > end)
        {
            return std::vector<TreeNode*>(1, (TreeNode*)NULL);
        }
        else if (start == end)
        {
            TreeNode* node = new TreeNode(start);
            return std::vector<TreeNode*>(1, node);
        }

        std::vector<TreeNode*> trees;
        for (int i = start; i <= end; i++)
        {
            auto left_trees = buildTrees(start, i - 1);
            auto right_trees = buildTrees(i + 1, end);
            for (auto& left_node: left_trees)
            {
                for (auto& right_node: right_trees)
                {
                    TreeNode* cur_root = new TreeNode(i);
                    cur_root->left = left_node;
                    cur_root->right = right_node;
                    trees.push_back(cur_root);
                }
            }
        }

        return trees;
    }
};

int main(int argc, char* argv[])
{
    auto trees = Solution().generateTrees(3);
    printf("Total number of trees: %zd\n", trees.size());
    return 0;
}

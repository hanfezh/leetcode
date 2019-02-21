/*
 * =====================================================================================
 *
 *       Filename:  binary_tree_paths.cpp
 *
 *    Description:  Binary Tree Paths. 
 *                  Given a binary tree, return all root-to-leaf paths.
 *
 *        Version:  1.0
 *        Created:  02/21/19 12:30:11
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
    std::vector<std::string> binaryTreePaths(TreeNode* root)
    {
        std::vector<std::string> paths;
        binaryTreePaths(root, std::string("->"), paths);
        return paths;
    }

private:
    void binaryTreePaths(TreeNode* node, const std::string& prefix, std::vector<std::string>& paths)
    {
        if (node == NULL)
        {
            return;
        }
        else if (node->left == NULL && node->right == NULL)
        {
            auto new_path = prefix + std::to_string(node->val);
            new_path = new_path.substr(2);
            paths.push_back(new_path);
        }
        else
        {
            auto new_pre = prefix + std::to_string(node->val) + "->";
            binaryTreePaths(node->left, new_pre, paths);
            binaryTreePaths(node->right, new_pre, paths);
        }
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = NULL;
    auto paths = Solution().binaryTreePaths(root);
    return 0;
}

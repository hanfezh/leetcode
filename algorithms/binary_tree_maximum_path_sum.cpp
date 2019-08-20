// =====================================================================================
//
//       Filename:  binary_tree_maximum_path_sum.cpp
//
//    Description:  124. Binary Tree Maximum Path Sum. 
//                  Given a non-empty binary tree, find the maximum path sum.
//
//        Version:  1.0
//        Created:  08/19/2019 08:16:52 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <limits.h>
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int maxPathSum(TreeNode* root)
    {
        int extra = INT_MIN;
        (void)maxPathSum(root, &extra);
        return extra;
    }

private:
    int maxPathSum(TreeNode* node, int* extra)
    {
        if (node == nullptr)
        {
            return INT_MIN;
        }

        int a = std::max(0, maxPathSum(node->left, extra));
        int b = std::max(0, maxPathSum(node->right, extra));
        *extra = std::max(a + b + node->val, *extra);
        return std::max(a, b) + node->val;
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = nullptr;
    int sum = Solution().maxPathSum(root);
    printf("Maximum path sum: %d\n", sum);
    return 0;
}

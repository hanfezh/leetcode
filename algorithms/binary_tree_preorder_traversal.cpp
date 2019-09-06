// =====================================================================================
//
//       Filename:  binary_tree_preorder_traversal.cpp
//
//    Description:  144. Binary Tree Preorder Traversal. Given a binary tree, return 
//                  the preorder traversal of its nodes' values. Recursive solution is 
//                  trivial, could you do it iteratively?
//
//        Version:  1.0
//        Created:  09/06/2019 04:45:53 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

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
    vector<int> preorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> nodes;
        vector<int> values;

        if (root == nullptr)
        {
            return values;
        }

        nodes.push(root);
        while (!nodes.empty())
        {
            auto* cur = nodes.top();
            nodes.pop();
            values.push_back(cur->val);
            if (cur->right != nullptr)
            {
                nodes.push(cur->right);
            }
            if (cur->left != nullptr)
            {
                nodes.push(cur->left);
            }
        }

        return values;
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = nullptr;
    auto values = Solution().preorderTraversal(root);
    if (values.size() > 0)
    {
        for (auto val: values)
        {
            printf("%d ", val);
        }
    }
    return 0;
}

// =====================================================================================
//
//       Filename:  binary_tree_postorder_traversal.cpp
//
//    Description:  145. Binary Tree Postorder Traversal. Given a binary tree, return 
//                  the postorder traversal of its nodes' values. Recursive solution is 
//                  trivial, could you do it iteratively?
//
//        Version:  1.0
//        Created:  09/06/2019 05:07:02 PM
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> nodes;
        vector<int> values;

        if (root == nullptr)
        {
            return values;
        }

        // Traversal strategy: reverse of root -> right -> left
        nodes.push(root);
        while (!nodes.empty())
        {
            auto* cur = nodes.top();
            nodes.pop();
            values.insert(values.begin(), cur->val);
            if (cur->left != nullptr)
            {
                nodes.push(cur->left);
            }
            if (cur->right != nullptr)
            {
                nodes.push(cur->right);
            }
        }

        return values;
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = nullptr;
    auto values = Solution().postorderTraversal(root);
    if (values.size() > 0)
    {
        for (auto val: values)
        {
            printf("%d ", val);
        }
    }
    return 0;
}

// 236. Lowest Common Ancestor of a Binary Tree
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive, DFS
class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }

        auto* lnode = lowestCommonAncestor(root->left, p, q);
        auto* rnode = lowestCommonAncestor(root->right, p, q);
        if (lnode != nullptr && rnode != nullptr)
        {
            return root;
        }
        return (lnode != nullptr ? lnode : rnode);
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = nullptr;
    TreeNode* p = nullptr;
    TreeNode* q = nullptr;
    auto* ancestor = Solution().lowestCommonAncestor(root, p, q);
    printf("Lowest common ancestor is %p\n", ancestor);
    return 0;
}

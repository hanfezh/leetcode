// =====================================================================================
//
//       Filename:  binary_search_tree_iterator.cpp
//
//    Description:  173. Binary Search Tree Iterator.
//
//        Version:  1.0
//        Created:  09/12/2019 06:12:59 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Non-recursive traversal
class BSTIterator
{
public:
    BSTIterator(TreeNode* root)
    {
        ptr_ = root;
    }

    // @return the next smallest number
    int next()
    {
        while (ptr_ != nullptr)
        {
            nodes_.push(ptr_);
            ptr_ = ptr_->left;
        }

        int val = 0;
        ptr_ = nodes_.top();
        val = ptr_->val;
        ptr_ = ptr_->right;
        nodes_.pop();

        return val;

    }

    // @return whether we have a next smallest number
    bool hasNext()
    {
        return (ptr_ != nullptr || !nodes_.empty());
    }

private:
    TreeNode* ptr_ = nullptr;
    std::stack<TreeNode*> nodes_;
};

int main(int argc, char* argv[])
{
    TreeNode* root = nullptr;
    BSTIterator iterator(root);
    printf("Has next? %s\n", (iterator.hasNext() ? "Yes" : "No"));
    return 0;
}

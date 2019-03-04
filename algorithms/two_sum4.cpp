/*
 * =====================================================================================
 *
 *       Filename:  two_sum4.cpp
 *
 *    Description:  Two Sum IV - Input is a BST.
 *
 *        Version:  1.0
 *        Created:  03/04/19 07:55:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
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
    bool findTarget(TreeNode* root, int target)
    {
        std::vector<int> numbers;
        traverse(root, numbers);

        for (int low = 0, high = numbers.size() - 1; (low < numbers.size() - 1) && (low < high); )
        {
            int left = target - numbers[high];
            if (left < numbers[low])
            {
                high--;
            }
            else if (left > numbers[low])
            {
                low++;
            }
            else
            {
                // left == numbers[low]
                return true;
            }
        }

        return false;
    }

private:
    void traverse(TreeNode* node, std::vector<int>& numbers)
    {
        if (node == NULL)
        {
            return;
        }
        traverse(node->left, numbers);
        numbers.push_back(node->val);
        traverse(node->right, numbers);
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = NULL;
    auto found = Solution().findTarget(root, 9);
    return 0;
}

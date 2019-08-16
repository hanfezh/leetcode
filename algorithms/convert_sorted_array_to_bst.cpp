// =====================================================================================
//
//       Filename:  convert_sorted_array_to_bst.cpp
//
//    Description:  108. Convert Sorted Array to Binary Search Tree.
//
//        Version:  1.0
//        Created:  08/09/2019 02:44:02 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <vector>

using std::vector;

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
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return sortedArrayToBST(nums, 0, nums.size());
    }

private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int size)
    {
        if (size <= 0)
        {
            return nullptr;
        }

        int mid = start + (size / 2);
        auto* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid - start);
        root->right = sortedArrayToBST(nums, mid + 1, start + size - mid - 1);
        return root;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {1, 3, 5, 7, 9};
    auto* root = Solution().sortedArrayToBST(nums);
    printf("root = %p\n", root);
    return 0;
}

// =====================================================================================
//
//       Filename:  pascal_triangle2.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  08/16/2019 02:48:31 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using std::vector;

// Non-recursive
class Solution1
{
public:
    vector<int> getRow(int row_idx)
    {
        vector<int> nums(row_idx + 1, 0);
        nums[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = i; j > 0; j--)
            {
                nums[j] = nums[j] + nums[j - 1];
            }
        }
        
        return nums;
    }
};

// Recursive
class Solution2
{
public:
    vector<int> getRow(int row_idx)
    {
        vector<int> nums(row_idx + 1, 0);
        generate(nums, row_idx);
        return nums;
    }

private:
    void generate(vector<int>& nums, int  row_idx)
    {
        if (row_idx == 0)
        {
            nums[0] = 1;
            return;
        }

        generate(nums, row_idx - 1);
        for (int i = row_idx; i >= 0; i--)
        {
            nums[i] = nums[i];
            if (i > 0)
            {
                nums[i] += nums[i - 1];
            }
        }
    }
};

using Solution = Solution2;

int main(int argc, char* argv[])
{
    int row_idx = 3;
    if (argc > 1)
    {
        row_idx = atoi(argv[1]);
    }

    auto nums = Solution().getRow(row_idx);
    for (const auto& item: nums)
    {
        printf("%d ", item);
    }
    printf("\n");

    return 0;
}

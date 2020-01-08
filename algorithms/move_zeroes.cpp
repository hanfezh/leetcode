// 283. Move Zeroes: https://leetcode.com/problems/move-zeroes
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <algorithm>
#include <vector>

class Solution
{
public:
    void moveZeroes(std::vector<int>& nums)
    {
        int zero_idx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                if (i != zero_idx)
                {
                    std::swap(nums[i], nums[zero_idx]);
                }
                zero_idx++;
            }
        }
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {0, 1, 0, 3, 12};
    Solution().moveZeroes(nums);
    for (auto val: nums)
    {
        printf("%d ", val);
    }
    printf("\n");
    return 0;
}

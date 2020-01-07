// 189. Rotate Array: https://leetcode.com/problems/rotate-array
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <algorithm>
#include <vector>

// Cyclic replacement
class Solution
{
public:
    void rotate(std::vector<int>& nums, int k)
    {
        int size = nums.size();
        if (size == 0 || (k % size) == 0)
        {
            return;
        }

        k %= size;
        int count = 0;

        for (int idx = 0; count < size; idx++)
        {
            int start = idx;
            int value = nums[idx];
            do {
                start = (start + k) % size;
                std::swap(value, nums[start]);
                count++;
            } while (start != idx);
        }
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 2;
    Solution().rotate(nums, k);
    for (auto val: nums)
    {
        printf("%d ", val);
    }
    printf("\n");
    return 0;
}


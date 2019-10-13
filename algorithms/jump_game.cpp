// 55. Jump Game: https://leetcode.com/problems/jump-game
// Author: xianfeng.zhu@gmail.com
#include <stdio.h>
#include <algorithm>
#include <vector>

// Backtracking, time limit exceeded
class Solution1
{
public:
    bool canJump(std::vector<int>& nums)
    {
        return canJump(nums, 0);
    }

private:
    bool canJump(std::vector<int>& nums, int start)
    {
        if (start >= nums.size() - 1)
        {
            return true;
        }

        int end = start + nums[start];
        for (int i = end; i > start; i--)
        {
            if (canJump(nums, i))
            {
                return true;
            }
        }

        return false;
    }
};

// Dynamic programming
class Solution2
{
public:
    enum JumpState
    {
        kBad,
        kGood,
    };

    bool canJump(std::vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return true;
        }

        std::vector<JumpState> states(nums.size(), kBad);
        states[nums.size() - 1] = kGood;

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            int end = std::min(nums[i] + i, (int)(nums.size() - 1));
            for (int j = i + 1; j <= end; j++)
            {
                if (states[j] == kGood)
                {
                    states[i] = kGood;
                    break;
                }
            }
        }

        return (states[0] == kGood);
    }
};

// Greedy
class Solution3
{
public:
    bool canJump(std::vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return true;
        }

        int last_idx = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] + i >= last_idx)
            {
                last_idx = i;
            }
        }

        return (last_idx == 0);
    }
};

using Solution = Solution3;

int main(int argc, char* argv[])
{
    std::vector<int> nums = {3, 2, 1, 0, 4};
    bool is_jump = Solution().canJump(nums);
    printf("Can jump? %s\n", (is_jump ? "Yes" : "No"));
    return 0;
}

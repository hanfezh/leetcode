// 1. Two Sum: https://leetcode.com/problems/two-Sum
// Author: xianfeng.zhu@gmail.com
#include <stdio.h>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++)
        {
            indices[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = indices.find(target - nums[i]);
            if (iter != indices.end() && iter->second != i)
            {
                return std::vector<int>({i, iter->second});
            }
        }

        return std::vector<int>();
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto indices = Solution().twoSum(nums, target);
    for (const auto idx: indices)
    {
        printf("%d ", idx);
    }
    printf("\n");
    return 0;
}

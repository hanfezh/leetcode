// 384. Shuffle an Array: https://leetcode.com/problems/shuffle-an-array
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
public:
    Solution(vector<int>& nums): nums_(nums)
    {
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return nums_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> nums(nums_);
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            int j = rand() % size;
            std::swap(nums[i], nums[j]);
        }
        return nums;
    }

private:
    vector<int> nums_;
};

int main(int argc, char* argv[])
{
    vector<int> nums = {1, 2, 3};
    auto digits = Solution(nums).shuffle();
    for (const auto val: digits)
    {
        printf("%d ", val);
    }
    printf("\n");
    return 0;
}

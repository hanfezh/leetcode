/*
 * =====================================================================================
 *
 *       Filename:  sort_colors.cpp
 *
 *    Description:  75. Sort Colors. Given an array with n objects colored red, white or 
 *                  blue, sort them in-place so that objects of the same color are 
 *                  adjacent, with the colors in the order red, white and blue.
 *
 *        Version:  1.0
 *        Created:  04/21/19 13:31:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <vector>

class Solution
{
public:
    enum Color
    {
        Red   = 0,
        White = 1,
        Blue  = 2,
    };

    void sortColors(std::vector<int>& nums)
    {
        int i = 0;
        int head = 0;
        int tail = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++)
        {
            // Swap current blue and right red/white
            while (nums[i] == Blue && i < tail)
            {
                if (nums[tail] != Blue)
                {
                    swapColor(&nums[i], &nums[tail]);
                }
                tail--;
            }

            // Swap current red and left white/blue
            while (nums[i] == Red && i > head)
            {
                if (nums[head] != Red)
                {
                    swapColor(&nums[i], &nums[head]);
                }
                head++;
            }
        }
    }

private:
    void swapColor(int* a, int* b)
    {
        int c = *a;
        *a = *b;
        *b = c;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution().sortColors(nums);
    for (auto n: nums)
    {
        printf("%d ", n);
    }
    printf("\n");
    return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  trapping_rain_water.cpp
 *
 *    Description:  42. Trapping Rain Water. Given n non-negative integers representing 
 *                  an elevation map where the width of each bar is 1, compute how much 
 *                  water it is able to trap after raining.
 *
 *        Version:  1.0
 *        Created:  04/20/19 15:08:53
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
#include <algorithm>
#include <vector>

class Solution
{
public:
    int trap(std::vector<int>& height)
    {
        if (height.size() < 3)
        {
            return 0;
        }

        std::vector<int> left_max(height.size(), 0);
        std::vector<int> right_max(height.size(), 0);

        left_max[0] = height[0];
        for (int i = 1; i < height.size(); i++)
        {
            left_max[i] = std::max(left_max[i - 1], height[i]);
        }

        right_max[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--)
        {
            right_max[i] = std::max(right_max[i + 1], height[i]);
        }

        int sum = 0;
        for (int i = 1; i < height.size() - 1; i++)
        {
            sum += std::min(left_max[i], right_max[i]) - height[i];
        }

        return sum;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    if (argc > 2)
    {
        height.clear();
        for (int i = 1; i < argc; i++)
        {
            height.push_back(atoi(argv[i]));
        }
    }
    auto sum = Solution().trap(height);
    printf("Total water: %d\n", sum);
    return 0;
}

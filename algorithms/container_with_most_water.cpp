/*
 * =====================================================================================
 *
 *       Filename:  container_with_most_water.cpp
 *
 *    Description:  Given n non-negative integers a1, a2, ..., an, where each represents 
 *                  a point at coordinate (i, ai). n vertical lines are drawn such that 
 *                  the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, 
 *                  which together with x-axis forms a container, such that the container 
 *                  contains the most water.
 *
 *        Version:  1.0
 *        Created:  06/28/18 08:45:27
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

class Solution
{
public:
    int maxArea(const std::vector<int>& heights)
    {
        if (heights.size() < 2)
        {
            return 0;
        }

        int max_area = 0;
        int i = 0;
        int j = heights.size() - 1;
        while (i < j)
        {
            int cur_area = (j - i) * std::min(heights[i], heights[j]);
            if (cur_area > max_area)
            {
                max_area = cur_area;
            }

            if (heights[i] < heights[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return max_area;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> heights = {1, 2, 1};
    int area = Solution().maxArea(heights);
    printf("max area: %d\n", area);

    return 0;
}

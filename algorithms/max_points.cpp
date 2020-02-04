// 149. Max Points on a Line: https://leetcode.com/problems/max-points-on-a-line
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <map>
#include <vector>

using std::vector;

class Solution
{
public:
    int maxPoints(vector<vector<int>>& points)
    {
        int max_num = 0;
        
        for (int i = 0; i < points.size(); i++)
        {
            std::map<std::pair<int, int>, int> nums;
            int dup_num = 1;
            
            for (int j = i + 1; j < points.size(); j++)
            {
                if (points[j][0] == points[i][0] && points[j][1] == points[i][1])
                {
                    dup_num += 1;
                    continue;
                }
                
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int dz = gcd(dx, dy);
                nums[std::make_pair(dx / dz, dy / dz)] += 1;
            }
            
            max_num = std::max(max_num, dup_num);
            for (const auto& item: nums)
            {
                max_num = std::max(item.second + dup_num, max_num);
            }
        }
        
        return max_num;
    }
    
private:
    int gcd(int a, int b)
    {
        return ((b == 0) ? a : gcd(b, a % b));
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> points = {
        {1, 1},
        {2, 2},
        {3, 3},
    };

    int num = Solution().maxPoints(points);
    printf("Output: %d\n", num);
    return 0;
}

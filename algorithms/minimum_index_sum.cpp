/*
 * =====================================================================================
 *
 *       Filename:  minimum_index_sum.cpp
 *
 *    Description:  Minimum Index Sum of Two Lists.
 *
 *        Version:  1.0
 *        Created:  02/25/19 08:15:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<std::string> findRestaurant(const std::vector<std::string>& list1, const std::vector<std::string>& list2)
    {
        std::unordered_map<std::string, int> indexes;
        std::vector<std::string> rests;
        int least = list1.size() + list2.size();

        for (size_t i = 0; i < list1.size(); i++)
        {
            indexes[list1[i]] = i;
        }

        for (size_t j = 0; j < list2.size(); j++)
        {
            auto iter = indexes.find(list2[j]);
            if (iter == indexes.end())
            {
                continue;
            }

            int sum = iter->second + j;
            if (sum > least)
            {
                continue;
            }
            else if (sum < least)
            {
                rests.clear();
            }

            // sum <= least
            rests.push_back(list2[j]);
            least = sum;
        }

        return rests;
    }
};

int main(int argc, char* argv[])
{
    std::vector<std::string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    std::vector<std::string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};

    auto rests = Solution().findRestaurant(list1, list2);
    for (const auto& item: rests)
    {
        printf("%s ", item.c_str());
    }
    printf("%s\n", (rests.size() > 0) ? "" : "None");

    return 0;
}

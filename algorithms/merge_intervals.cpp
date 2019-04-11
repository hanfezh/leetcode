/*
 * =====================================================================================
 *
 *       Filename:  merge_intervals.cpp
 *
 *    Description:  56. Merge Intervals. 
 *                  Given a collection of intervals, merge all overlapping intervals.
 *
 *        Version:  1.0
 *        Created:  04/11/19 01:39:40
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

// Definition for an interval.
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
    std::vector<Interval> merge(std::vector<Interval>& intervals)
    {
        auto cmp_func = [](const Interval& a, const Interval& b) -> bool {
            return a.start < b.start;
        };
        std::sort(intervals.begin(), intervals.end(), cmp_func);
        
        std::vector<Interval> merges;
        for (int i = 0; i < intervals.size(); )
        {
            int low = intervals[i].start;
            int high = intervals[i].end;
            int next = i + 1;
            while ((next < intervals.size()) && (intervals[next].start <= high))
            {
                high = std::max(high, intervals[next].end);
                next++;
            }

            i = next;
            merges.push_back(Interval(low, high));
        }

        return merges;
    }
};

int main(int argc, char* argv[])
{
    std::vector<Interval> intervals = {
        Interval(1, 3),
        Interval(2, 6),
        Interval(8, 10),
        Interval(15, 18),
    };

    auto merges = Solution().merge(intervals);
    for (int i = 0; i < merges.size(); i++)
    {
        if (i != 0)
        {
            printf(" ,");
        }
        printf("[%d, %d]", merges[i].start, merges[i].end);
    }
    printf("\n");

    return 0;
}

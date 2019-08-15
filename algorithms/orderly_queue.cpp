// =====================================================================================
//
//       Filename:  orderly_queue.cpp
//
//    Description:  899. Orderly Queue.
//
//        Version:  1.0
//        Created:  08/15/2019 11:49:00 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>

using std::string;

class Solution
{
public:
    string orderlyQueue(const string& s, int k)
    {
        if (k < 1)
        {
            return s;
        }
        else if (k == 1)
        {
            string src = s + s;
            string dst = s;
            for (int i = 1; i < s.size(); i++)
            {
                auto sub = src.substr(i, s.size());
                if (sub < dst)
                {
                    dst = sub;
                }
            }
            return dst;
        }

        // k > 1, sort string
        string d = s;
        std::sort(d.begin(), d.end());
        return d;
    }
};

int main(int argc, char* argv[])
{
    string s = "cba";
    int k = 1;
    if (argc > 2)
    {
        s = argv[1];
        k = atoi(argv[2]);
    }
    auto d = Solution().orderlyQueue(s, k);
    printf("%s, %d -> %s\n", s.c_str(), k, d.c_str());
    return 0;
}

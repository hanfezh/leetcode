// =====================================================================================
//
//       Filename:  rotate_string.cpp
//
//    Description:  796. Rotate String.
//
//        Version:  1.0
//        Created:  08/15/2019 10:02:18 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Zhu Xianfeng (), xianfeng.zhu@gmail.com
//   Organization:  
//
// =====================================================================================
#include <stdio.h>
#include <string>

using std::string;

class Solution
{
public:
    bool rotateString(string& a, string& b)
    {
        if (a.size() != b.size())
        {
            return false;
        }

        string c = a + a;
        return (c.find(b) != string::npos);
    }
};

int main(int argc, char* argv[])
{
    string a = "abcde";
    string b = "cdeab";
    if (argc > 2)
    {
        a = argv[1];
        b = argv[2];
    }
    bool ok = Solution().rotateString(a, b);
    printf("%s, %s -> %s\n", a.c_str(), b.c_str(), (ok ? "true" : "false"));
    return 0;
}

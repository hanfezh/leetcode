// 93. Restore IP Addresses: https://leetcode.com/problems/restore-ip-addresses
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    vector<string> restoreIpAddresses(string& s)
    {
        vector<string> addrs;
        string cur;
        dfsRestore(s, 0, cur, 0, addrs);
        return addrs;
    }

private:
    void dfsRestore(const string& s, int start, string& cur, 
                    int count, vector<string>& addrs)
    {
        if (start == s.size() || count == 4)
        {
            if (start == s.size() && count == 4)
            {
                addrs.push_back(cur);
            }
            return;
        }

        int len = (s[start] == '0' ? 1 : 3);
        for (int i = 1; (i <= len && i + start <= s.size()); i++)
        {
            string part = s.substr(start, i);
            if (atoi(part.c_str()) > 255)
            {
                break;
            }

            auto idx = cur.size();
            if (count != 0)
            {
                cur += ".";
            }
            cur += part;
            dfsRestore(s, (i + start), cur, (count + 1), addrs);
            cur.erase(idx);
        }
    }
};

int main(int argc, char* argv[])
{
    string s = "25525511135";
    auto addrs = Solution().restoreIpAddresses(s);
    if (addrs.size() == 0)
    {
        printf("No valid ip address found\n");
    }
    for (const auto& ip: addrs)
    {
        printf("%s\n", ip.c_str());
    }
    return 0;
}

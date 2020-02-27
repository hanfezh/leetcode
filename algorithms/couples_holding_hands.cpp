// 765. Couples Holding Hands: https://leetcode.com/problems/couples-holding-hands
// Author: xianfeng.zhu@gmail.com

#include <stdio.h>
#include <vector>

using std::vector;

class UnionFind
{
public:
    UnionFind(int count): count_(count), couples_(count)
    {
        for (int i = 0; i < count; i++)
        {
            couples_[i] = i;
        }
    }

    virtual ~UnionFind() = default;

    int find(int idx) const
    {
        while (couples_[idx] != idx)
        {
            idx = couples_[idx];
        }
        return idx;
    }


    void connect(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            couples_[a] = b;
            count_--;
        }
    }

    bool isConnected(int a, int b) const
    {
        return find(a) == find(b);
    }

    int getCount() const
    {
        return count_;
    }

private:
    vector<int> couples_;
    int count_;
};

class Solution
{
public:
    int minSwapsCouples(const vector<int>& row)
    {
        int count = row.size() / 2;
        UnionFind uf(count);
        for (int i = 0; i < row.size(); i += 2)
        {
            uf.connect(row[i] / 2, row[i + 1] / 2);
        }
        return count - uf.getCount();
    }
};

int main(int argc, char* argv[])
{
    vector<int> row = {0, 2, 1, 3};
    int swaps = Solution().minSwapsCouples(row);
    printf("Input: row = [");
    for (int i = 0; i < row.size(); i++)
    {
        printf("%s%d", (i != 0 ? ", " : ""), row[i]);
    }
    printf("]\n");
    printf("Output: %d\n", swaps);
    return 0;
}

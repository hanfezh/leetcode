/*
 * =====================================================================================
 *
 *       Filename:  design_hashmap.cpp
 *
 *    Description:  Design HasMap. 
 *                  Design a HasMap without using amy built-in hash table libraries.
 *
 *        Version:  1.0
 *        Created:  02/26/19 01:49:18
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

class MyHashMap
{
public:
    MyHashMap()
    {
        size_ = 1000000 + 1;
        buf_ = new int[size_];
        std::fill_n(buf_, size_, -1);
    }

    ~MyHashMap()
    {
        delete[] buf_;
    }

    void put(int key, int value)
    {
        if (key < size_)
        {
            buf_[key] = value;
        }
    }

    int get(int key)
    {
        if (key < size_)
        {
            return buf_[key];
        }
        return -1;
    }

    void remove(int key)
    {
        if (key < size_)
        {
            buf_[key] = -1;
        }
    }

private:
    int size_;
    int* buf_;
};

int main(int argc, char* argv[])
{
    MyHashMap my_map;
    my_map.put(10, 20);
    printf("%d\n", my_map.get(10));
    return 0;
}

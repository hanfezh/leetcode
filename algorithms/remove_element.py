#!/usr/bin/env python
# encoding: utf8

# Remove Element
# Given an array and a value, remove all instances of that value in place and return the new length.
# The order of elements can be changed. It doesn't matter what you leave beyond the new length.

__author__ = "Zhu Xianfeng <xianfeng.zhu@gmail.com>"

class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        count = 0
        last  = -1
        idx   = -1
        for val in A:
            idx += 1
            if val == elem:
                if last == -1:
                    last = idx
                count += 1
            elif last != -1:
                # val not equals elem && last index is not -1
                A[last] = val
                last += 1
        return (idx + 1) - count

def main():
    num = [1, 3, 2, 3, 9, 2, 10]
    sol = Solution()
    count = sol.removeElement(num, 2)
    print num
    print count

if __name__ == "__main__":
    main()

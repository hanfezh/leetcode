#!/usr/bin/env python
# encoding: utf8

# Remove Duplicates from Sorted Array
# Given a sorted array, remove the duplicates in place such 
# that each element appear only once and return the new length.
# Do not allocate extra space for another array, you must do 
# this in place with constant memory.

__author__ = "Zhu Xianfeng <xianfeng.zhu@gmail.com>"

class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        if len(A) == 0:
            return 0
        last = 0
        for i in xrange(1, len(A)):
            if A[i] != A[last]:
                last += 1
                A[last] = A[i]
        return (last + 1)

def main():
    num = [1, 2, 2, 2, 3, 4, 5, 5, 6]
    sol = Solution()
    ret = sol.removeDuplicates(num)
    print ret
    print num

if __name__ == "__main__":
    main()

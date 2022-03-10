#!/usr/bin/env python
# encoding: utf8

# You are given two linked lists representing two non-negative numbers. 
# The digits are stored in reverse order and each of their nodes contain 
# a single digit. Add the two numbers and return it as a linked list.
# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8

__author__ = "Zhu Xianfeng <xianfeng.zhu@gmail.com>"

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def __str__(self):
        s = "%d" % (self.val)
        node = self.next
        while node is not None:
            s = s + (", %d" % (node.val))
            node = node.next
        return s

    @staticmethod
    def convert(nums):
        ptr = dummy = ListNode(0)
        for n in nums:
            ptr.next = ListNode(n)
            ptr = ptr.next
        return dummy.next

    @staticmethod
    def deserialize(s):
        a = s.find('{')
        b = s.find('}')
        s = s[a + 1: b]
        return ListNode(int(s))

class Solution:
    def addTwoNumbers(self, l1, l2):
        ptr = dummy = ListNode(0)
        carry = 0
        while l1 or l2 or carry:
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next
            carry, val = divmod(carry, 10)
            ptr.next = ListNode(val)
            ptr = ptr.next
        return dummy.next

def main():
    l1 = ListNode.convert([2, 4, 6])
    l2 = ListNode.convert([5, 6, 4])
    print l1
    print l2

    l3 = Solution().addTwoNumbers(l1, l2)
    print l3

if __name__ == "__main__":
    main()

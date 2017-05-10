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
    def deserialize(s):
        a = s.find('{')
        b = s.find('}')
        s = s[a + 1: b]
        return ListNode(int(s))

class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        head = None
        prev = None
        node = None
        val  = 0
        while l1 is not None and l2 is not None:
            val += l1.val + l2.val
            node = ListNode(val % 10)
            val /= 10
            l1 = l1.next
            l2 = l2.next
            if head is None:
                head = node
            if prev is not None:
                prev.next = node
            prev = node

        l3 = None
        if l1 is not None:
            l3 = l1
        elif l2 is not None:
            l3 = l2

        if l3 is not None:
            while l3 is not None:
                val += l3.val
                node = ListNode(val % 10)
                val /= 10
                l3 = l3.next
                if head is None:
                    head = node
                if prev is not None:
                    prev.next = node
                prev = node

        if val > 0:
            node = ListNode(val)
            if prev is not None:
                prev.next = node

        return head

def genListNode(nums):
    head = None
    node = None
    prev = None
    for i in nums:
        node = ListNode(i)
        if head is None:
            head = node
        if prev is not None:
            prev.next = node
        prev = node

    return head

def main():
    l1 = genListNode([2, 4, 3])
    l2 = genListNode([5, 6, 4])
    print l1
    print l2

    sol = Solution()
    l3 = sol.addTwoNumbers(l1, l2)
    print l3

if __name__ == "__main__":
    main()

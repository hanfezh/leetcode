#!/usr/bin/python
# -*- coding: utf-8 -*-
# 206. Reverse Linked List
# https://leetcode.com/problems/reverse-linked-list/

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

// Recursion
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def reverse(p):
            if not p or not p.next:
                return p, p
            h, t = reverse(p.next)
            t.next = p
            p.next = None
            return h, p
        return reverse(head)[0]

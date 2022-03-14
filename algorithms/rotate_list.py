#!/usr/bin/python
# -*- coding: utf-8 -*-
# 61. Rotate List https://leetcode.com/problems/rotate-list/

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        pre, cur = None, head
        count = 0
        while cur:
            count += 1
            pre, cur = cur, cur.next
        if count < 2:
            return head
        pre.next = head
        k = count - k % count
        pre, cur = None, head
        while k > 0:
            pre, cur = cur, cur.next
            k -= 1
        pre.next = None
        return cur

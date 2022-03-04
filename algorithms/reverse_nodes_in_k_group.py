#!/usr/bin/python
# -*- coding: utf-8 -*-
# 25. Reverse Nodes in k-Group
# https://leetcode.com/problems/reverse-nodes-in-k-group/

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        cur, count = head, 0
        while cur and count != k:
            cur, count = cur.next, count + 1
        if count != k:
            return head

        # Reverse list with k + 1 node as head
        rem = self.reverseKGroup(cur, k)

        # Reverse current k-group
        dummy = ListNode(0, rem)
        while head != cur:
            tmp = head.next
            head.next = dummy.next
            dummy.next = head
            head = tmp
        return dummy.next

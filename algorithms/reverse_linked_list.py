#!/usr/bin/python
# -*- coding: utf-8 -*-
# 206. Reverse Linked List
# https://leetcode.com/problems/reverse-linked-list/

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Recursion
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        ptr = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return ptr

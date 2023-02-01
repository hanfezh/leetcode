#!/usr/bin/python
# -*- coding: utf-8 -*-
# 148. Sort List https://leetcode.com/problems/sort-list/

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        right = slow.next
        slow.next = None
        left = self.sortList(head)
        right = self.sortList(right)
        return self.mergeList(left, right)

    def mergeList(self, left: Optional[ListNode], right: Optional[ListNode]) -> ListNode:
        p = dummy = ListNode(0)
        while left and right:
            if left.val < right.val:
                p.next = left
                left = left.next
            else:
                p.next = right
                right = right.next
            p = p.next
        p.next = left or right
        return dummy.next

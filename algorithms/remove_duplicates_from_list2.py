#!/usr/bin/python
# -*- coding: utf-8 -*-
# 82. Remove Duplicates from Sorted List II
# https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        curr = dummy = ListNode()
        left, right = head, head.next
        while left:
            while right and right.val == left.val:
                right = right.next
            if right == left.next:
                curr.next = left
                curr = curr.next
            if not right:
                curr.next = left = None
            else:
                left, right = right, right.next
        return dummy.next

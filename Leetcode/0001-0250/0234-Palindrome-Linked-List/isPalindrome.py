# -*- coding: utf-8 -*-
# @Author: talentwill
# @Date:   2023-05-27 10:13:33
# @Last Modified by:   talentwill
# @Last Modified time: 2023-05-27 10:13:44
# Definition for singly-linked list.

# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        # 空、单结点，直接返回true
        if not head or not head.next:
            return True

        # 拆分链表，长度5，拆分3+2。
        fast = slow = head
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
        second = slow.next
        slow.next = None

        # 迭代法，反转链表
        pre, cur = None, second
        while cur:
            tmp = cur.next
            cur.next = pre
            pre, cur = cur, tmp

        l1, l2 = head, pre
        while l1 and l2:
            if l1.val != l2.val:
                return False
            l1 = l1.next
            l2 = l2.next
        # 最后l2为空，全部比较完成
        return not l2

# -*- coding: utf-8 -*-
# @Author: talentwill
# @Date:   2023-05-23 08:00:00
# @Last Modified by:   talentwill
# @Last Modified time: 2023-06-04 16:18:46

class Solution:
    # 迭代法：用三个指针反转链表
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None  # head的前驱，反转后的头结点
        while head:
            temp = head.next  # 保存后继指针，防止丢失
            head.next = prev  # 反转
            prev, head = head, temp  # 迭代
        return prev  # 返回反转后的头指针


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # 空 or 最后一个节点
        if not head or not head.next:
            return head
        root = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return root

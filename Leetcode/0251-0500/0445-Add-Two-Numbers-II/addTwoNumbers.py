# -*- coding: utf-8 -*-
# @Author: talentwill
# @Date:   2023-05-27 08:52:33
# @Last Modified by:   talentwill
# @Last Modified time: 2023-05-27 08:53:52


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 递归反转链表
        def reverse(node: ListNode) -> ListNode:
            if not node or not node.next:
                return node
            tail = reverse(node.next)
            node.next.next = node
            node.next = None
            return tail
        l1 = reverse(l1)
        l2 = reverse(l2)

        pre = None  # 保存前一次计算后的高位指针
        carry = 0  # 统计进位
        while l1 or l2 or carry:
            val = carry
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next
            carry = val // 10
            cur = ListNode(val % 10, pre)  # 创建高位结点
            pre = cur
        return pre

# https://leetcode.cn/problems/reverse-linked-list/
# @date: 2023-05-23

class Solution:
    # 迭代法：用三个指针反转链表
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None # head的前驱，反转后的头结点
        while head:
            temp = head.next # 保存后继指针，防止丢失
            head.next = prev # 反转
            prev, head = head, temp # 迭代
        return prev # 返回反转后的头指针
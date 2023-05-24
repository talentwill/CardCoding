# https://leetcode.cn/problems/reorder-list/
# 2023-05-24

class Solution:
    def reorderList(self, head: ListNode) -> None:
        if not head or not head.next:
            return head

        # 找到中间结点返回
        def middle(head: ListNode) -> ListNode:
            fast = slow = head
            while fast.next and fast.next.next:
                fast = fast.next.next
                slow = slow.next
            return slow

        # 返回后半段链表
        def split(head: ListNode) -> ListNode:
            mid = middle(head)
            l2 = mid.next
            mid.next = None
            return l2

        # 迭代法反转链表
        def reverse(head: ListNode) -> ListNode:
            pre, cur = None, head
            while cur:
                tmp = cur.next
                cur.next = pre
                pre, cur = cur, tmp
            return pre

        # L1和L2穿插起来
        def link(l1: ListNode, l2: ListNode):
            while l1 and l2:
                tmp1 = l1.next
                tmp2 = l2.next
                l1.next = l2
                l2.next = tmp1
                l1, l2 = tmp1, tmp2

        link(head, reverse(split(head)))  # 一气呵成

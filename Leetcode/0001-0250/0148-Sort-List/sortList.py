# -*- coding: utf-8 -*-
# @Author: talentwill
# @Date:   2023-05-26 22:20:17
# @Last Modified by:   talentwill
# @Last Modified time: 2023-05-26 22:25:44

# Merge Sort Top Down
# Time Complexity: O(nlogn)
# Space Complexity: O(logn)
class Solution:
    def sortList(self, head: ListNode) -> ListNode:

        # 拆分链表，返回第二条链表
        def split(head: ListNode) -> ListNode:
            fast = slow = head
            while fast.next and fast.next.next:
                fast = fast.next.next
                slow = slow.next
            second = slow.next
            slow.next = None
            return second

        # 升序合并两条链表
        def merge(l1: ListNode, l2: ListNode) -> ListNode:
            dummy = ListNode(-1)
            cur = dummy
            while l1 and l2:
                if l1.val < l2.val:
                    cur.next = l1
                    l1 = l1.next
                else:
                    cur.next = l2
                    l2 = l2.next
                cur = cur.next  # 千万别忘记了cur迭代
            cur.next = l1 if l1 else l2
            return dummy.next

        # 排序代码开始，空 或 单结点
        if not head or not head.next:
            return head

        l2 = split(head)
        l1 = self.sortList(head)
        l2 = self.sortList(l2)
        return merge(l1, l2)

// 剑指 Offer 18. 删除链表的节点

// 03/05 双指针直接删除
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }

        if (head->val == val) {
            return head->next;
        }

        ListNode* pre = head;
        ListNode* tmp = pre;
        while (tmp != nullptr) {
            if (tmp->val == val) {
                pre->next = tmp->next;
            }
            pre = tmp;
            tmp = tmp->next;
        }
        return head;
    }
};
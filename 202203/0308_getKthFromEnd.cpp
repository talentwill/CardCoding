// 剑指 Offer 22. 链表中倒数第k个节点

// 03/08 slow-fast pointers
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *p1 = head;
        ListNode *p2 = head;

        for (int i = 0; i < k; ++i)
        {
            p1 = p1->next;
        }

        while (p1 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p2;
    }
};

// 剑指 Offer 24. 反转链表 v1.0 271758514

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* reversedHead = head;
        ListNode* pre = nullptr;
        ListNode* node = head;

        while (node != nullptr) {
            auto next = node->next;
             if (next == nullptr) {
                reversedHead = node;
            }

            node->next = pre;
            pre = node;
            node = next;
        }
        return reversedHead;
    }
};
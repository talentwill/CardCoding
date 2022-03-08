// 剑指 Offer 25. 合并两个排序的链表

// 03/09 递归实现，引入了额外的head，本可以去掉。
class Solution {
public:
    void merge(ListNode*& head, ListNode* l1, ListNode* l2){
        if (l1 != NULL and l2 != NULL) {
            if (l1->val < l2->val) {
                head = l1;
                merge(head->next, l1->next, l2);
            } else {
                head = l2;
                merge(head->next, l1, l2->next);
            }
        }
        else if (l1 != NULL and l2 == NULL) {
            head = l1;
        } 
        else if (l2 != NULL and l1 == NULL) {
            head = l2;
        }
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        merge(head, l1, l2);
        return head;
    }
};

// 剑指 Offer 52. 两个链表的第一个公共节点

// 0314 长度差遍历法实现
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto len = [](ListNode* list) {
            int ret = 0;
            for (auto p = list; p != NULL; p = p->next) {
                ret++;
            }
            return ret;
        };

        int lenA = len(headA);
        int lenB = len(headB);

        auto p1 = headA;
        auto p2 = headB;
        if (lenA > lenB) {
            for (int i = lenA - lenB; i > 0; i--) {
                p1 = p1->next;
            }          
        }else {
            for (int i = lenB - lenA; i > 0; i--) {
                p2 = p2->next;
            }          
        }

        // 细节，要判断指针非空
        while (p1 != nullptr && p2 != nullptr && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
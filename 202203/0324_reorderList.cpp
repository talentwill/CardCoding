// 剑指 Offer II 026. 重排链表

// 0324 寻找链表中点 + 链表逆序 + 合并链表
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        auto middle = middleNode(head);
        auto list2 = middle->next;
        middle->next = nullptr; // break lists
        link(head, iterationReverse(list2));
    }

    void link(ListNode* node1, ListNode* node2) {
        while (node1 != nullptr && node2 != nullptr) {
            auto temp = node2->next;
            node2->next = node1->next;
            node1->next = node2;
            node1 = node2->next;
            node2 = temp;
        }
    }

    // 找到中间节点
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast->next != nullptr) {
                fast = fast->next;
            }
        }
        return slow;
    }

    ListNode* iterationReverse(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* cur = head;
        head = nullptr;

        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = head;
            head = cur;
            cur = next;
        }

        return head;
    }
};

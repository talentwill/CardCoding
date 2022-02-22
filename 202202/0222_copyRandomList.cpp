// 剑指 Offer 35. 复杂链表的复制 v1.0 271711972

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == nullptr)
            return nullptr;

        // clone
        auto node = head;
        while (node != nullptr) {
            auto clone = new Node(*node);
            node->next = clone;
            node = clone->next;
        }

        // connect
        node = head;
        while(node != nullptr) {
            auto clone = node->next;
            if (node->random != nullptr) {
                clone->random = node->random->next;
            }
            node = clone->next;
        }

        // break
        node = head;
        Node* cloneHead = head->next;
        Node* cloneNode = cloneHead;

        while (node != nullptr) {
            cloneNode = node->next;
            node->next = cloneNode->next;
            node = node->next;
            if (node !=nullptr )
                cloneNode->next = node->next;
        }

        return cloneHead;
    }
};
// 剑指 Offer 06. 从尾到头打印链表

// 22/02/13 堆栈缓存

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        auto node = head;
        std::stack<ListNode*> nodes;

        while(node != nullptr)
        {
            nodes.push(node);
            node = node->next;
        }

        vector<int> result;
        while(!nodes.empty())
        {
            node = nodes.top();
            result.emplace_back(node->val);
            nodes.pop();
        }

        return result;
    }
};

// 21/12/25 递归输出
struct Solution
{
    std::vector<int> results;

    void addNode(ListNode *node)
    {
        if (node !=nullptr)
        {
            addNode(node->next);
            results.emplace_back(node->val);
        }
    }

    std::vector<int> reversePrint(ListNode *head)
    {
        addNode(head);
        return results;
    }
};
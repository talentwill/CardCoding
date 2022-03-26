// 剑指 Offer 36. 二叉搜索树与双向链表

// 0326 中序遍历+头尾结点
class Solution {
public:

	Node* listTailer = nullptr;
	Node* listHeader = nullptr;

    void link(Node* node) {
        if (node != nullptr) {
            link(node->left);

            if (listTailer == nullptr) {
            	listTailer = node;
         		listHeader = node;
            } else {
            	listTailer->right = node;
            	node->left = listTailer;
            	listTailer = node;
            }

            link(node->right);
        }
    }

    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return root;
        }
        
        link(root);
        listTailer->right = listHeader;
        listHeader->left = listTailer;
        return listHeader;
    }
};
```
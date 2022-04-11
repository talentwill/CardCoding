// 剑指 Offer II 053. 二叉搜索树中的中序后继

// 0411 中序遍历解法,递归方法
class Solution {
public:
    bool found = false;
    TreeNode* successor = nullptr; // 返回答案
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        inorder(root, p);
        return successor;
    }

    // 中序遍历，模板代码
    void inorder(TreeNode* node, TreeNode* p) { //
        if (successor == nullptr and node != nullptr) {
            inorder(node->left, p);

            // 设置过标记位，遇到下一个节点输出的时候就输出
            if (found and successor == nullptr) {
                successor = node;
                return;
            }

            if (node == p) { // 先找到节点，设置标记位
                found = true;
            }

            inorder(node->right, p);
        }
    }
};

// 0411 利用二叉搜索树的特点，2分排除小于P的节点
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* succcessor = nullptr;
        TreeNode* node = root;
        while (node != nullptr) {
            if (node->val > p->val) {
                succcessor = node; // 当前大于P的节点
                node = node->left; // 继续迭代左子树，可能还有比P大的子节点
            } else {
                node = node->right; 
            }
        }
        return succcessor;
    }
};
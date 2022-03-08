// 剑指 Offer 28. 对称的二叉树

// 03/09 递归比较即可
class Solution {
public:

    bool isSymmetric(TreeNode* a, TreeNode* b) {
        if (a == nullptr and b == nullptr) {
            return true;
        } 
        
        if (a != nullptr and b != nullptr) {
            if (a->val == b->val) {
                return isSymmetric(a->left, b->right) and isSymmetric(a->right, b->left);
            }
        }
        
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }
};
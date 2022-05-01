// 剑指 Offer 68 - I. 二叉搜索树的最近公共祖先

// 0501 递归法
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (max(p->val, q->val) < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (min(p->val, q->val) > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

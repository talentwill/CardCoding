/**
 * @Author: talentwill
 * @Date:   2022-05-01 08:00:00
 * @Last Modified by:   talentwill
 * @Last Modified time: 2023-06-06 12:21:43
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (max(p->val, q->val) < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (min(p->val, q->val) > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

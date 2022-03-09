// 剑指 Offer 27. 二叉树的镜像

// 03/10 遍历的变体
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        swap(root->left, root->right); // 把前序遍历的print改成swap。
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};

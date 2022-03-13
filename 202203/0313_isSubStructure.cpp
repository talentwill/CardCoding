// 剑指 Offer 26. 树的子结构

// 0312 用递归方式解题
class Solution {
public:
    bool compare(TreeNode* A, TreeNode* B) {
        if (B == nullptr) {
            return true;
        } else if (A == nullptr) {
            return false;
        } 

        if (A->val == B->val) {
            return compare(A->left, B->left) and compare(A->right, B->right);
        } 
        return false;
    }

    bool traverse(TreeNode* A, TreeNode* B){
        if (A != nullptr) {
            if (compare(A, B)) {
                return true;
            }else {
                return traverse(A->left, B) or traverse(A->right, B);
            }
        }
        return false;
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (B == nullptr) {
            return false;
        } else {
            return traverse(A, B);
        }
    }
};
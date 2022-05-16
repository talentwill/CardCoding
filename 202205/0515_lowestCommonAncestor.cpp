// 剑指 Offer 68 - II. 二叉树的最近公共祖先

// 0515 从上到下，逐个判断，重复判断
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;

        // 如果p或q是跟结点，直接返回root
        if (root == p or root == q) return root;

        // 判断p或q所在子树的位置
        bool isPLeftChild = isChild(root->left, p);
        bool isQLeftChild = isChild(root->left, q);

        if (isPLeftChild != isQLeftChild) {
            return root;    // p，q 分别在不同的子树上，返回root。
        }
        else if (isQLeftChild) {
            // p, q 都在左子树，那公共结点一定在左子树
            return lowestCommonAncestor(root->left, p, q);
        }
        else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }

    // 通用函数，判断是node是否为root的子结点
    bool isChild(TreeNode* root, TreeNode* node) {
        if (root == nullptr) return false;
        if (root == node) return true;
        return isChild(root->left, node) or isChild(root->right, node);
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
           return root;
        }

        if (root == p or root == q) {
            return root; // 找到q或p都OK，直接返回
        }
		
        // left 是 p，q 其一
        auto left = lowestCommonAncestor(root->left, p, q);
        // right 是 p，q 其一
        auto right = lowestCommonAncestor(root->right, p, q);

        // 自底往上，p, q 分别在两侧，返回 root，根据重要性质
        if (left !=nullptr and right != nullptr) {
            return root;
        }

        // p 或 q 在左侧，不管哪个，直接递归返回上去，
        if (left != nullptr and right == nullptr) {
            return left;
        }
        
        // p 或 q 在右侧，
        if (right != nullptr and left == nullptr) {
            return right;
        }

        // q 或 p 都不在这个子树中
        if (left == nullptr and right == nullptr) {
            return nullptr;
        }

        return root;
    }
};
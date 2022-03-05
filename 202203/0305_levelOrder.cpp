// 面试题32 - I. 从上到下打印二叉树

// 利用广度优先遍历打印
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node != nullptr) {
                res.emplace_back(node->val);
                q.emplace(node->left);
                q.emplace(node->right);
            }
        }
        return res;
    }
};
// 剑指 Offer 32 - III. 从上到下打印二叉树 III

// 0320 double stacks
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {}; // 边界测试，重要！
        }

        stack<TreeNode*> s[2];
        int cur = 0;
        int next = 1;

        vector<vector<int>> ans(1);
        s[cur].push(root);

        while (not s[cur].empty()) {
            TreeNode* node = s[cur].top();
            s[cur].pop();

            ans.back().push_back(node->val);

            if (cur == 0) { // 1,3,5 layer
                if (node->left != nullptr) {
                    s[next].push(node->left);
                }
                if (node->right != nullptr) {
                    s[next].push(node->right);
                }
            } else { //2,4,6 layer
                if (node->right != nullptr) {
                    s[next].push(node->right);
                }
                if (node->left != nullptr) {
                    s[next].push(node->left);
                }
            }

            if (s[cur].empty() and not s[next].empty()) {
                ans.push_back({});
                swap(cur, next);
            }
        }

        return ans;
    }
};

// 剑指 Offer 32 - II. 从上到下打印二叉树 II

// 03/10 广度优先搜索，但是要记录下每一层的个数
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        int curLevelNodes = 1;  // 当前层的节点数
        int nextLevelNodes = 0; // 记录下一层的节点数

        vector<int> nodes;

        while (not q.empty()) {
            auto node = q.front();
            q.pop();
            nodes.push_back(node->val);

            if (node->left != NULL) {
                q.push(node->left);
                nextLevelNodes++;
            }
            if (node->right != NULL) {
                q.push(node->right);
                nextLevelNodes++;
            }

            // 当前层数完，开启新一轮
            if (--curLevelNodes == 0) {
                curLevelNodes = nextLevelNodes;
                nextLevelNodes = 0;
                res.push_back(std::move(nodes));
            }
        }
        return res;
    }
};

/**
 * @Author: talentwill
 * @Date:   2022-03-10 08:00:00
 * @Last Modified by:   talentwill
 * @Last Modified time: 2023-06-04 17:28:58
 */

// 03/10 广度优先搜索，但是要记录下每一层的个数
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;

        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        int curLevelNodes = 1; // 当前层的节点数
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

// 2023-06-04 双队列交换
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (root == nullptr)
            return {}; // 空指针要判断，切记
        queue<TreeNode*> q1, q2;
        q1.emplace(root);

        auto push = [&](auto* node) {
            if (node != nullptr)
                q2.emplace(node);
        };

        vector<vector<int>> ans;
        vector<int> tmp;
        while (not q1.empty()) {
            auto x = q1.front();
            q1.pop();
            tmp.push_back(x->val);

            push(x->left);
            push(x->right);

            if (q1.empty()) {
                q1 = std::move(q2);
                ans.push_back(std::move(tmp));
            }
        }
        return ans;
    }
};
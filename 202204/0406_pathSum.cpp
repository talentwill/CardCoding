// 剑指 Offer 34. 二叉树中和为某一值的路径

// 0406 深度遍历修改，注意路径从根到叶总和
class Solution {
public:
 vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> sum;
        dfs(root, target, sum);
        return ans;
    }

    void dfs(TreeNode* node, int target, vector<int>& sum) {
        if (node != nullptr) {
            sum.emplace_back(node->val);
            if (node->left == nullptr and node->right == nullptr and node->val == target) {
                ans.emplace_back(sum);
            }
            else {
                dfs(node->left, target - node->val, sum);
                dfs(node->right, target - node->val, sum);
            }
            sum.pop_back();
        }
    }

    vector<vector<int>> ans;
};
// 剑指 Offer 07. 重建二叉树

// 03/07 递归解法+建立索引
class Solution
{
public:
    map<int, int> index;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty())
        {
            return NULL;
        }

        for (int i = 0; i < inorder.size(); i++)
        {
            index[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd)
    {
        auto root = new TreeNode(preorder[preStart]);

        if (preStart == preEnd and inStart == inEnd)
        {
            return root;
        }

        int leftLen = index[root->val] - inStart;
        if (leftLen > 0)
        {
            root->left = buildTree(preorder, inorder, preStart + 1, preStart + leftLen, inStart, index[root->val] - 1);
        }
        if (inEnd - inStart > leftLen)
        {
            root->right = buildTree(preorder, inorder, preStart + leftLen + 1, preEnd, index[root->val] + 1, inEnd);
        }
        return root;
    }
};

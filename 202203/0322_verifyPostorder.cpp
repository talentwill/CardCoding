// 剑指 Offer 33. 二叉搜索树的后序遍历序列

// 0322 用递归分治的思想，判断左右子树是否满足搜索树的特点
class Solution {
public:

    bool verify(vector<int>& postorder, int first, int last) {
        if (first == last) {
            return true;
        }

        int root = postorder[last];
        int leftEnd = -1;
        int rightStart = -1;
        for (int i = first; i < last; i++) {
            if (rightStart == -1) {
                if (postorder[i] < root) {
                    leftEnd = i;
                } else {
                    rightStart = i; // find the right sub tree margin
                }
            } else {
                if (postorder[i] < root) {
                    // the numbers of right side should always be less than root
                    return false;
                }
            }
        }

        bool ans = true; // key2: if no left subnodes, it should be true
        if (leftEnd != -1) {
            ans = verify(postorder, first, leftEnd);
        }

        if (ans and rightStart != -1) {
            ans = verify(postorder, rightStart, last - 1); // [last-1] key1: don't forget exclude root
        }
        return ans;
    }

    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty()) {
            return true; // key3: true!
        }

        return verify(postorder, 0, postorder.size()-1);
    }
};

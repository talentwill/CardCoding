// 剑指 Offer II 053. 二叉搜索树中的中序后继

// 0411 中序遍历解法,迭代方法
class Solution {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        Stack<TreeNode> stack = new Stack<>();
        boolean found = false;
        TreeNode cur = root;
        while (cur != null || !stack.isEmpty()) {
            while (cur != null) {
                stack.push(cur);
                cur = cur.left;
            }
            
            cur = stack.pop();
            if (found) {
                break; // 找到后立即返回
            } else if (cur == p) {
                found = true;
            }
            cur = cur.right;
        }
        return cur;
    }
}
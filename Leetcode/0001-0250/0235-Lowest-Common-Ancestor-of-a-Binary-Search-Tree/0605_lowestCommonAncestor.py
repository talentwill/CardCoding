# -*- coding: utf-8 -*-
# @Author: talentwill
# @Date:   2022-05-01 08:00:00
# @Last Modified by:   talentwill
# @Last Modified time: 2023-06-06 12:19:57

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # 比根小，递归左子树
        if p.val < root.val > q.val:
            return self.lowestCommonAncestor(root.left, p, q)
        # 比根大，递归右子树
        if p.val > root.val < q.val:
            return self.lowestCommonAncestor(root.right, p, q)
        return root

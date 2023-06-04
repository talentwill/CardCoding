# -*- coding: utf-8 -*-
# @Author: talentwill
# @Date:   2023-06-04 15:12:51
# @Last Modified by:   talentwill
# @Last Modified time: 2023-06-04 15:13:46

class Solution:
    def buildTree(self, pre: List[int], ino: List[int]) -> TreeNode:
        def dfs(l, r, s, e) -> TreeNode:
            if l <= r:
                m = ino.index(pre[l])  # get index of root in inorder
                return TreeNode(pre[l],
                                dfs(l + 1, l + (m-s), s, m - 1),
                                dfs(l + (m-s) + 1, r, m + 1, e))
        return dfs(0, len(pre) - 1, 0, len(ino) - 1)

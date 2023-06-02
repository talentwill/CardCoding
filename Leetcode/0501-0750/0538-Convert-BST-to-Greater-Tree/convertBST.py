# -*- coding: utf-8 -*-
# @Author: talentwill
# @Date:   2023-06-02 08:00:00
# @Last Modified by:   talentwill
# @Last Modified time: 2023-06-02 15:04:48

class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        stk = []
        cur = root
        path = 0
        while cur or stk:
            while cur:
                stk.append(cur)
                cur = cur.right
            cur = stk.pop()
            path += cur.val  # 加上路径的和
            cur.val = path
            cur = cur.left
        return root

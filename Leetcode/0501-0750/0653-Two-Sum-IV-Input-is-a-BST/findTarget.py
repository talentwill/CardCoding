# -*- coding: utf-8 -*-
# @Author: talentwill
# @Date:   1970-01-01 08:00:00
# @Last Modified by:   talentwill
# @Last Modified time: 2023-06-02 23:26:13

class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        cur, stk, s = root, [], set()
        while cur or stk:
            while cur:
                stk.append(cur)
                cur = cur.left
            cur = stk.pop()
            if k - cur.val in s:
                return True
            s.add(cur.val)
            cur = cur.right
        return


class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        stk, rstk = [], []  # 中序遍历需要的栈
        it = rit = root  # 定义正反两个迭代器

        # 中序遍历方向迭代器（递减）
        def rnext() -> int:
            nonlocal rit
            while rit:
                rstk.append(rit)
                rit = rit.right
            cur = rstk.pop()
            rit = cur.left
            return cur.val

        # 中序遍历正向迭代器（递增）
        def next() -> int:
            nonlocal it
            while it:
                stk.append(it)
                it = it.left
            cur = stk.pop()
            it = cur.right
            return cur.val

        # 反向双指针，逐步缩小空间
        p, q = next(), rnext()
        while p != q:
            if p + q == k:
                return True
            if p + q < k:   # 左指针向右
                p = next()
            else:
                q = rnext()  # 右指针向左
        return False

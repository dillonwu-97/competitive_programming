# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def twoSumBSTs(self, root1: TreeNode, root2: TreeNode, target: int) -> 
        bool:
        l1 = []
        l2 = []
        def f (root, n):
            if root:
                if n == 1:
                    l1.append(root.val)
                else:
                    l2.append(root.val)
                f(root.left, n)
                f(root.right, n)
        f(root1, 1)
        f(root2, 2)
                        d = {}
        def md(root):
            if root:
                d[root.val] = 1
                md(root.left)
                md(root.right)
                if len(l1) >= len(l2):
            md(root1)
            # print(d)
            for i in l2:
                if target - i in d:
                    return True
            return False
        else:
            md(root2)
            # print(d)
            for i in l1:
                if target - i in d:
                    return True
            return False 
            
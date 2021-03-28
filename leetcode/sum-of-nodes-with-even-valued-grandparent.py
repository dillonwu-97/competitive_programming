# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        ret = []
        def solve(root):
            if root:
                if root.val % 2 == 0:
                    if root.left != None:
                        if root.left.left != None:
                            ret.append(root.left.left.val)
                        if root.left.right != None:
                            ret.append(root.left.right.val)
                    if root.right != None:
                        if root.right.left != None:
                            ret.append(root.right.left.val)
                        if root.right.right != None:
                            ret.append(root.right.right.val)
                if root.left != None:
                    solve(root.left)
                if root.right != None:
                    solve(root.right)         
        solve(root)
        return sum(ret)
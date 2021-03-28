# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
                def solve(root, above):
            if root==None:
                return above
            else:
                r = solve(root.right, above)
                root.val += r
                l = solve(root.left, root.val)
                return l
        solve(root, 0)
        return root
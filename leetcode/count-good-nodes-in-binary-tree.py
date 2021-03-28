# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def r (self, m, root):
        if root == None:
            return 0
        if root.val >= m:
            m = root.val
            return 1 + self.r(m, root.left) + self.r( m, root.right)
        else:
            return self.r(m, root.left) + self.r( m, root.right)
            def goodNodes(self, root: TreeNode) -> int:
        m = root.val
        return 1 + self.r( m, root.left) + self.r( m, root.right)
        
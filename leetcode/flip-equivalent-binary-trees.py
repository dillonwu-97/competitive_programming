# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipEquiv(self, root1: TreeNode, root2: TreeNode) -> bool:
                        def solve(root1, root2):
            if not root1 or not root2:
            # if root1 == None or root2 == None:
                return root1 is root2
            elif root1.val != root2.val:
                return False
            return solve(root1.left, root2.right) and solve(root1.right, root2
                .left) or solve(root1.left, root2.left) and solve(root1.right, 
                root2.right)
                    return solve(root1, root2)
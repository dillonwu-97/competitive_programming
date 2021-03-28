from collections import defaultdict
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root == None:
            return []
        d = defaultdict(list)
        def solve(root, level):
            if root:
                d[level].append(root.val)
                solve(root.left, level+1)
                solve(root.right, level+1)
                solve(root, 0)
        l = max(d.keys())
        ret = []
        for i in range(l+1):
            ret.append(d[i][-1])
        return ret
        
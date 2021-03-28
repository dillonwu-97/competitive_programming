# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        d = {}
                def solve(root, level):
            if root == None:
                return 
            else:
                if level in d:
                    d[level].append(root.val)
                else:
                    d[level] = [root.val]
                solve(root.left, level + 1)
                solve(root.right, level + 1)
        solve(root, 0)
        # print(d)
        for i in d.keys():
            if i % 2 == 0:
                if d[i][0] % 2 == 0:
                    return False
                for j in range(1,len(d[i])):
                    if d[i][j] <= d[i][j-1] or d[i][j] % 2 == 0:
                        return False
            else:
                if d[i][0] % 2 == 1:
                    return False
                for j in range(1,len(d[i])):
                    if d[i][j] >= d[i][j-1] or d[i][j] % 2 == 1:
                        return False
                        return True
        
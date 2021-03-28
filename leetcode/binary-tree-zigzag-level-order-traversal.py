# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        d = {}
        def solve(root, num):
            if root == None:
                return
            if num in d:
                d[num].append(root.val)
            else:
                d[num] = [root.val]
            solve(root.left, num + 1)
            solve(root.right, num + 1)
        solve(root, 0)
        ret = []
        for key in d.keys():
            if key % 2 == 1:
                d[key].reverse()
                ret.append(d[key])
            else:
                ret.append(d[key])
        return ret
                    
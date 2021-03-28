"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        d = {}
        def solve(root, num):
            if root == None:
                return
            if num in d:
                d[num].append(root)
            else:
                d[num] = [root]
            solve(root.left, num + 1)
            solve(root.right, num + 1)
        solve(root, 0)
        for key in d.keys():
            for i in range(len(d[key])):
                if i == len(d[key]) - 1:
                    d[key][i].next = None
                else:
                    d[key][i].next = d[key][i+1]
        return root
        
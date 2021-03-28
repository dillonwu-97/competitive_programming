"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None
        , next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
from collections import defaultdict
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        d = defaultdict(list)
        def solve(root, level):
            if root:
                d[level].append(root)
                solve(root.left, level +1)
                solve(root.right, level +1)
                        solve(root, 0)
        for k in d.keys():
            for i in range(len(d[k])):
                if i == len(d[k])-1:
                    d[k][i].next = None
                else:
                    d[k][i].next = d[k][i+1]
        return root
                                    
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""
class Solution:
    def cloneTree(self, root: 'Node') -> 'Node':
        c = None
        def solve(root, clone):
            if root:
                clone = Node(root.val)
                clone.children = []
                for i in root.children:
                    new_node = None
                    # print(new_node.val)
                    new_node = solve(i, new_node)
                    clone.children.append(new_node)
                return clone
        c = solve(root, c)
        # print(c)
        return c
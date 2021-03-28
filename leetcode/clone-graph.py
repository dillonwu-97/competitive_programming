"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""
from collections import deque
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node == None: return None
        ret = Node()
        ret.val = node.val
        q = deque()
        for i in node.neighbors:
            q.append([ret, i])
        d = {node: ret}
        v = {ret: 0}
        # append the parent and child
        while (len(q) > 0):
            # print("next q ", q)
            out = q.popleft()
            prev = out[0]
            cur = out[1]
            if cur not in d:
                new_node = Node()
                new_node.val = cur.val
                d[cur] = new_node
            prev.neighbors.append(d[cur])
            for n in cur.neighbors:
                if d[cur] not in v:
                    q.append([d[cur], n])
            v[ d[cur] ] = 0
        return ret
                    
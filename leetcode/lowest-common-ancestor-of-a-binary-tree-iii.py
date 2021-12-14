"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""
class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        d = {}
                temp = p
        while (temp.parent != None):
            d[temp.val] = temp
            temp = temp.parent
        d[temp.val] = temp            
        temp = q
        while (temp.val not in d):
            temp = temp.parent
                return d[temp.val]
                #         def find_root(p):
#             path = []
#             temp = p
#             while (temp.parent!= None ):
#                 temp = temp.parent
#                 path.append(temp)
#             return path
        #         p_path = find_root(p)
#         q_path = find_root(q)
#         for i in range(p_path):
#             for j in range(q_path):
#                 if q_
                                #         return None
                    
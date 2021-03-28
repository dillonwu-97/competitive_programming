"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if head == None:
            return None
        nodes = []
        old_copy =[]
        temp = head
        while (temp != None):
            # print(temp.random)
            new_node = Node(temp.val, next = None, random = None)
            # print(new_node.val)
            nodes.append(new_node)
            old_copy.append(temp)
            temp = temp.next
        for i in range(len(nodes)):
            if i != len(nodes)-1:
                nodes[i].next = nodes[i+1]
            else:
                nodes[i].next = None
            if old_copy[i].random != None:
                ind = old_copy.index( old_copy[i].random )
                nodes[i].random = nodes[ind]
            else:
                nodes[i].random = None
        return nodes[0]
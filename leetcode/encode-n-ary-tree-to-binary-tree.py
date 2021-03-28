"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
"""
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
"""
from collections import defaultdict
class Codec:
    # Encodes an n-ary tree to a binary tree.
    def encode(self, root: 'Node') -> TreeNode:
        if root == None:
            return None
        v = []
        def solve(root, n):
            if root:
                v.append((root.val, n))
                for i in root.children:      
                    solve(i, n+1)
        solve(root, 0)
        # print(v)
        v = [None] + v
        # 2n, 2n+1 formula
        # print(v)
        for i in range(1,len(v)):
            v[i] = TreeNode(v[i])
            if i == 1: continue
            if i % 2 == 0:
                v[i // 2].left = v[i]
            else:
                v[i // 2].right = v[i]
        return v[1]
                # Decodes your binary tree to an n-ary tree.
    def decode(self, data: TreeNode) -> 'Node':
        if data == None:
            return None
        d = defaultdict(list)
        # have to do level order traversal
        def solve(root,n):
            if root:
                d[n].append(root.val)
                solve(root.left, n+1)
                solve(root.right, n+1)
        solve(data, 0)
        # print(d)
        comp_d = []
        for k in d.keys():
            comp_d += d[k]
        # print(comp_d)
        # reconstruct tree from preorder traversal
        tree = {}
        def construct(a):
            i = 0
            prev = 0
            #[(1, 0), (3, 1), (5, 2), (6, 2), (2, 1), (4, 1)]
            while i < len(a):
                val = a[i][0]
                index = a[i][1]
                new_node = Node(val, children=[])
                if index <= prev:
                    # print(prev, index)
                    tree[index + 1] = new_node
                    # tree[index + ].popleft()
                # if index < prev: # move up the tree
                #     print("in prev ", tree[prev][0].val, prev)
                #     tree[prev].popleft()
                # run next two lines whether moving up or down the tree
                prev = index
                tree[index+1] = new_node
                # print(val, index)
                tree[index].children.append(new_node) # add new child
                i+=1
                                root = Node(comp_d[0][0], children=[])
        tree[1] = root
        construct(comp_d[1:])
        # print(root)
        # return None
                return root
# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(root))
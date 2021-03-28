from collections import defaultdict, deque
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        ret = None
        d = defaultdict(deque) # each dictionary element stores the current 
            one; so pop once its been referenced twice??
        # string, prev length, current length
        def solve(s, prev, root):
            if len(s) == 0:
                return
            current = 0
            i = 0
            while (s[i] == '-'):
                # print(s, s[i], current)
                i+=1
                current +=1
            num = ""
            while(i < len(s) and s[i].isnumeric()):
                num+=s[i]
                i+=1
            new_node = TreeNode(int(num))
            d[current+1] += [new_node, new_node]
            # print(s)
            if current <= prev: # go up
                d[current][0].right = new_node
                d[current].popleft()
            elif current > prev: # left side
                root.left = new_node
                # cull the left side of the list
                while d[current][0] != root:
                    d[current].popleft()
            return solve(s[i:],current,new_node)
                        i = 0
        num = ""
        while(i < len(S) and S[i].isnumeric()):
            num+=S[i]
            i+=1
        ret = TreeNode(int(num))
        d[1] += [ret,ret]
        solve(S[i:], 0, ret)
        return ret
        # [1,401,null,349,88,90]
    # "1-401--349--88---90": [1,401,null,349,88,null,null,90]
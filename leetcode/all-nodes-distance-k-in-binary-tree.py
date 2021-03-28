# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, K: int) -> List[int]
        :
        # go through all nodes and store distance = 2 nodes in dictionary
        def find_path (root, node, a):
            if root:
                if root == node:
                    a.append(root)
                    return a
                else:
                    left = find_path(root.left, node, a + [root])
                    right = find_path(root.right, node, a+[root])
                    if len(left) == 0:
                        return right
                    else:
                        return left
            else:
                return []
                # node path 1, node path 2
        def distance(np1, np2):
            i = 0
            while (i < min(len(np1), len(np2))):
                if np1[i] == np2[i]:
                    i+=1
                else:
                    # lca at i - 1
                    break
            return len(np1) - i + len(np2) - i
                ret = []
        tpath = find_path(root, target, [])
        def solve(root, a, k):
            if root:
                a.append(root)
                d = distance(a,tpath)
                # print(root.val, len(a), len(tpath))
                if d == k:
                    # for i in a:
                    #     print("val ", i)
                    # print(d)
                    ret.append(root.val)
                solve(root.left, a, k)
                solve(root.right, a, k)
                a.pop()
                        solve(root, [], K)
        return ret
                                
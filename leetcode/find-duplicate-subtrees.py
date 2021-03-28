import collections
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        vals = []
        d = {}
        count = collections.Counter()
        trees = collections.defaultdict()
        trees.default_factory = trees.__len__
        def solve(root):
            if root:
                # temp = str(root)
                temp = trees[root.val, solve(root.left), solve(root.right)]
                count[temp] +=1
                # print(str(root))
                # if count[temp] == 2 and temp not in d:
                if count[temp] == 2:
                    d[temp] = root
                return temp
                # print(root)
                # solve(root.left)
                # solve(root.right)
        solve(root)
        # print(count)
        vals = [d[i] for i in d.keys()]
        return vals
'''
vals = []
        trees = collections.defaultdict()
        trees.default_factory = trees.__len__
        count = collections.Counter()
        def solve(root):
            if root:
                uid = trees[root, solve(root.left), solve(root.right)]
                print(uid, trees)
                count [uid] += 1
                if count [uid] > 2:
                    vals.append(root)
        print(count)
        solve(root)
        return vals
'''
                '''
        i = 0
        j = 1
        ret = []
        d = {} # seen 
        save = 0
        while (i < len(vals)):
            save = i
            j = i + 1
            print(i, j)
            flag = 0
            while (j < len(vals)):
                if vals[i] == vals[j]:
                    flag = 1
                    i+=1
                    j+=1
                elif flag == 1 and vals[i] != vals[j]:
                    j+=1
                elif flag == 0 and vals[i] != vals[j]:
                    break
                                if (save != i and str(vals[save:i+1]) not in d):
                ret.append( vals[save:i+1])
                temp = str( vals[save:i+1])
                d [ temp ] = 1
            i = save + 1
'''             
                
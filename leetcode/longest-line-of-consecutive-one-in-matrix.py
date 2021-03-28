import numpy as np
import itertools
import collections
class Solution:
    def longestLine(self, M: List[List[int]]) -> int:
        if len(M) == 0: return 0
        def find(a):
            if len(a) == 0: return 0
            i = 0
            m = 0
            start = 999999999
            if a[0] == 1:
                start = 0
            for i in range(1,len(a)):
                if a[i]!= a[i-1]:
                    if a[i] == 0:
                        m = max(m, i - start)
                        # print(m)
                    start = i
            if a[i] == 1:
                m = max(m, i+1 - start)
            return m
        A = M
        if not A: return 0
        def score(line):
            return max(len(list(v)) if k else 0 
                for k, v in itertools.groupby(line))
        groups = collections.defaultdict(list)
        for r, row in enumerate(A):
            for c, val in enumerate(row):
                groups[0, r] += [val]
                groups[1, c] += [val]
                groups[2, r+c] += [val]
                groups[3, r-c] += [val]
        return max(map(score, groups.values()))
                ##### slow
        #         m = 0
#         for i in range(len(M)):
#             m = max(find(M[i]), m)
#         col = np.array(M).T
#         for i in range(len(col)):
#             # print(col[i])
#             m = max(find(col[i]), m)
#             # print(m)
#         # diags = [matrix[::-1,:].diagonal(i) for i in range(-3,4)]
#         # diags.extend(matrix.diagonal(i) for i in range(3,-4,-1))
#         # print [n.tolist() for n in diags]
#         matrix = np.array(M)
#         start = -(min(len(M), len(M[0]))-1)
#         end = max(len(M), len(M[0]))
#         # print(start, end)
#         # print(m)
#         l = [matrix[::-1].diagonal(i) for i in range(start, end)]
#         l2 = [matrix.diagonal(i) for i in range(start, end)]
#         for i in range(len(l)):
#             # print(l, l2)
#             m = max(m, find(l[i]), find(l2[i]))
            #         return m
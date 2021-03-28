class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime
        : List[int]) -> int:
        if n == 1:
            return 0
        t = 0
        m = {}
        for i in range(len(manager)):
            # m[i].append(i)
            if manager[i] in m:
                m[ manager[i] ].append( i )
            else:
                m[ manager[i] ] = [ i ]
        q = []
        q.append((headID,informTime[headID]))
        hi = 0 # max value
        while (len(q) > 0):
            # print(q)
            out = q.pop(0)
            index = out[0]
            cost = out[1]
            hi = max(cost, hi)
            if index in m:
                q += [(i, cost+informTime[i]) for i in m[index]]
        #         children = [[] for i in range(n)]
#         for i, m in enumerate(manager):
#             if m >= 0: children[m].append(i)
#         def dfs(i):
#             # print(i, max([dfs(j) for j in children[i]] or [0]) + 
    informTime[i] )
#             return max([dfs(j) for j in children[i]] or [0]) + informTime[i]
#         return dfs(headID)
                return hi
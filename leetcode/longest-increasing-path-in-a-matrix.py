import heapq
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        # use pque to solve problem
        # m = max(map(max, matrix))
        q = []
        xdir = [-1,1,0,0]
        ydir = [0,0,-1,1]
        ml = 0
        dp = [[-1]*len(matrix[0]) for i in range(len(matrix))]
        for k in range(len(matrix)):
            for j in range(len(matrix[0])):
                q = []
                # v = [[0]*len(matrix[0]) for i in range(len(matrix))]
                # print(v)
                # print(k, j, m)
                heappush(q, (0, [k, j, 1]))
                # v[k][j] = 1
                current = 0
                while(len(q) > 0):
                    out = heappop(q)
                    o = out[0]
                    r = out[1][0]
                    c = out[1][1]
                    length = out[1][2]
                    if length > ml:
                        ml = length
                    if length > current:
                        current = length
                    for i in range(len(xdir)):
                        newr = r+xdir[i]
                        newc = c + ydir[i]
                        # print("val to add ", newr, newc, matrix[newr][newc])
                        # print(o)
                        if newr < 0 or newr >= len(matrix) or\
                        newc < 0 or newc >= len(matrix[0]) or\
                        matrix[r][c] <= matrix[ newr ][ newc ]:
                            # v[ newr ][ newc ] == 1 or\
                            continue
                        # print("val to add ", matrix[newr][newc])
                        if (dp[newr][newc] != -1):
                            if (length + dp[newr][newc] > ml):
                                ml = length + dp[newr][newc]
                            if length + dp[newr][newc] > current:
                                current = length + dp[newr][newc]
                        else:
                            heappush(q, (o - matrix[newr][newc], [newr, newc, 
                                length+1] ))
                # print(ml)
                dp[k][j] = current
        return ml
                                                         
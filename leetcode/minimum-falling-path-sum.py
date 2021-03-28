class Solution:
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        ret = [0] * len(A[0])
        for i in range(len(A)):
            d = ret.copy()
            for j in range(len(A[0])):     
                if i == 0:
                    ret[j] = A[i][j]
                    continue
                if j == 0:
                    ret[j] = min(d[j], d[j+1])
                elif j == len(A[0]) - 1:
                    ret[j] = min(d[j], d[j-1])
                else:
                    ret[j] = min(d[j], d[j+1], d[j-1])
                ret[j] += A[i][j]
            # print(d)
        return min(ret)
                                    
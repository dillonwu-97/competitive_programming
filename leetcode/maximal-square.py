class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        d = [[0] * len(matrix[0]) for i in range(len(matrix))]
        ret = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                matrix[i][j] = int(matrix[i][j])
                if i == 0 or j == 0:
                    d[i][j] = matrix[i][j]
                    if d[i][j] > ret:
                        ret = d[i][j]
                    continue
                if matrix[i][j] == 1:
                    # print(d[i][j])
                    d[i][j] = min(d[i-1][j], d[i-1][j-1], d[i][j-1]) + 1
                    if d[i][j] > ret:
                        ret = d[i][j]
        # print(matrix)
        # print(d)
        return ret ** 2
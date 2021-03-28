class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        ret = 0
        total = [[0] * len(matrix[0]) for i in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 1:
                    if i == 0 or j == 0: 
                        total[i][j] += 1
                    elif total[i-1][j] == 0 or total[i][j-1] == 0:
                        total[i][j] += 1
                    # elif total[i-1][j] != 0 and total[i][j-1] != 0:
                    else:
                        total[i][j] = min(total[i-1][j-1], total[i-1][j], 
                            total[i][j-1]) + 1
                ret += total[i][j]
        # print(total)
                            return ret
        #[[1,1,1,1],[1,1,1,1],[1,1,1,1],[1,0,1,1]]
        
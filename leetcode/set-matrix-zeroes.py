class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        rows = []
        cols = []
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    rows.append(i)
                    cols.append(j)
        rows = list(set(rows))
        cols = list(set(cols))
        for i in range(len(rows)):
            matrix[rows[i]] = [0] * len(matrix[0])
        # print(len(matrix[0]))
        # print(matrix)
        for j in range(len(cols)):
            for i in range(len(matrix)):
                # print(i,j)
                matrix[i][cols[j]] = 0
                    
class Solution:
    def matrixBlockSum(self, mat: List[List[int]], K: int) -> List[List[int]]:
        # subset sum of columns and rows
        k =K
        # col = [[0] * len(mat) for i in range(len(mat[0]))]
        row = [[0] * len(mat[0]) for i in range(len(mat))]
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                row[i][j] = row[i][j-1]+ mat[i][j]
                # col[i][j] = col[i][j-1] + mat[j][i]
        for i in range(1,len(mat)):
            for j in range(len(mat[0])):
                row[i][j]+= row[i-1][j]
        for i in range(len(row)):
            row[i] = [0] + row[i]
        row = [[0] * (len(mat[0]) + 1)] + row
        # print(row)
        ret = [[0]* len(mat[0]) for i in range(len(mat))]
        # ret = [[0] * (len(mat[0]) + 1)] * (len(mat)+1)
        for i in range(1,len(mat)+1):
            for j in range(1,len(mat[0])+1):
                br, ur = max(0, i-k-1), min(len(mat), i+k)
                bc, uc = max(0, j-k-1), min(len(mat[0]), j+k)
                # print(ur, uc, br, bc, i-1 , j-1, row[ur][uc] - row[br][bc])
                # print(row[ur][uc], row[br][bc])
                if br != 0 or bc != 0:
                    ret[i-1][j-1] = row[ur][uc]
                    # print('hi', row[br][uc], 0, row[br][bc], row[ur][bc], 
                        ret[i-1][j-1])
                    ret[i-1][j-1] -= (row[br][uc] - row[0][0])
                    ret[i-1][j-1] -= (row[ur][bc] - row[br][bc]) 
                    # print('hi', ur, uc, br, bc, i-1 , j-1, ret[i-1][j-1])
                else:
                    # print('hello', ur, uc, br, bc, i-1 , j-1, ret[i-1][j-1])
                    ret[i-1][j-1] = row[ur][uc] - row[br][bc]
        # print(ret)
        # print(row)
        # print(col)
        return ret
        
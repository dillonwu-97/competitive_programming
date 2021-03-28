import numpy as np
class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        rows = {}
        cols = {}
        flag = "true"
        col_num = 0
        # col / row check
        for i in range(len(board)):
            rows = {}
            cols = {}
            for j in range(len(board)):
                # print(j, rows, cols)
                if board[i][j] not in rows and board[i][j] != '.':
                    rows[ board[i][j] ] = 0
                elif board[i][j] != '.':
                    return False
                if board[j][i] not in cols and board[j][i] != '.':
                    cols[ board[j][i] ] = 0
                elif board[j][i] != '.':
                    return False
                    # flag = "false"
        box = {}
        scale_x = 0
        scale_y = 0
        for a in range(3): 
            for b in range(3): 
                box = {}
                for j in range(3):
                    for k in range(3):
                        # print('board val is ', board[a*3 +j][b*3 + k])
                        if board[a * 3 + j][b*3 + k] not in box and board[a * 
                            3 + j][b*3 + k] != '.':
                            # print('what')
                            box[ board[a * 3 + j][b*3 + k] ] = 0
                        elif board[a * 3 + j][b*3 + k] != '.':
                            return False
        return True
                    
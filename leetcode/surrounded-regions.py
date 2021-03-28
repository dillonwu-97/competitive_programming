class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if len(board) == 0:
            return []
        visited = [[0] * len(board[0]) for i in range(len(board))]
        # print(visited)
                def solve(start, j, board):
            q = []
            q.append((start, j))
            while(len(q) != 0) :
                # print(q)
                out = q.pop(0)
                x = out[0]
                y = out[1]
                board[x][y] = 'A'
                # print(x,y)
                if  x > 0 and visited[x-1][y] == 0 and board[x-1][y] == 'O': 
                    q.append((x -1, y))
                    visited[x-1][y] = 1
                if  x < len(board) - 1 and visited[x+1][y] == 0  and board[x
                    +1][y] == 'O': 
                    q.append((x+1, y))
                    visited[x+1][y] = 1
                if  y > 0 and visited[x][y-1] == 0 and board[x][y-1] == 'O': 
                    q.append((x, y-1))
                    visited[x][y-1] = 1
                if y < len(board[0])-1 and  visited[x][y+1] == 0 and 
                    board[x][y+1] == 'O': 
                    q.append((x, y+1))   
                    visited[x][y+1] = 1
        # everything not on the border is flipped
        # bfs / dfs from all 0's on the border and then flip everything else
        for j in range(len(board[0])):
            visited[0][j] = 1
            if len(board) > 1: visited[len(board)-1][j] = 1
            if (board[0][j] == 'O'):
                solve(0, j, board)
            if len(board) > 1 and (board[ len(board) - 1 ][j] == 'O'):
                solve(len(board)-1, j, board)
                for j in range(len(board)):
            visited[j][0] = 1
            if len(board[0]) > 1: visited[j][len(board[0])-1] = 1
            if (board[j][0] == 'O'):
                solve(j, 0, board)
            if len(board[0]) > 1 and (board[ j ][len(board[0]) - 1] == 'O'):
                solve(j, len(board[0]) - 1, board)
                        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                if board[i][j] == 'A':
                    board[i][j] = 'O'
                                        
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # check = []
        for i in range(len(board)):
            for j in range(len(board[0])):
                                if board[i][j] == word[0]:
                    g = []
                    visited = []
                    g.append((board[i][j], (i,j), 0))
                    # visited.append((i,j))
                    # need to fix visited
                    while (len(g) > 0):
                        # print(g)
                        # print(visited)
                        val = g.pop() # dfs / using a stack
                        pos = val[1]
                        x = pos[0]
                        y = pos[1]
                        b_letter = val[0] # board letter
                        w_letter = val[2] # word letter
                        # print(word[w_letter])
                        # print(w_letter)
                        # check.append(w_letter)
                        if w_letter < len(visited):
                            visited = visited[:w_letter]
                        if b_letter == word[w_letter]:
                            # append value to visited
                            # append adjacent values
                            if w_letter + 1 == len(word):
                                return True
                            visited.append((x,y))
                            # print(g)
                            if x > 0:
                                if (x-1,y) not in visited:
                                    g.append((board[x-1][y], (x-1,y), w_letter
                                       +1))
                            if x < len(board)-1:
                                if (x+1, y) not in visited:
                                    g.append((board[x+1][y], (x+1,y), w_letter
                                       +1))
                            if y > 0:
                                if (x, y-1) not in visited:
                                    g.append((board[x][y-1], (x, y-1), 
                                       w_letter+1))
                            if y < len(board[0])-1:
                                if (x, y+1) not in visited:
                                    g.append((board[x][y+1], (x, y+1), 
                                       w_letter+1))
                        else:
                            if (w_letter == len(visited)-1):
                                visited.pop()
                return False
from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        #bfs, each with depth value
        v = [[0] * len(grid[0]) for i in range(len(grid))]
        q = deque()
        ret = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    q.append((i, j, 0)) # position and depth value
        d = 0
        while(len(q)) > 0:
            # print(q)
            out = q.popleft()
            x = out[0]
            y = out[1]
            d = out[2]
            if x+1 < len(grid) and v[x+1][y] == 0 and grid[x+1][y] == 1: 
                v[x+1][y] = 1
                q.append((x+1, y, d + 1))
            if y+1 < len(grid[0]) and v[x][y+1] == 0 and grid[x][y+1] == 1:
                v[x][y+1] = 1
                q.append((x, y+1, d+1))
            if x-1 >= 0 and v[x-1][y] == 0 and grid[x-1][y] == 1:
                v[x-1][y] = 1
                q.append((x-1, y, d+1))
            if y-1 >= 0 and v[x][y-1] == 0 and grid[x][y-1] == 1:
                v[x][y-1] = 1
                q.append((x, y-1, d+1))
        ret = d
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                # print(grid, v)
                if grid[i][j] == 1 and v[i][j] == 0:
                    return -1
        return ret
                            
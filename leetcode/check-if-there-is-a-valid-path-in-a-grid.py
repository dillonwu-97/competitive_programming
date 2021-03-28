from collections import deque
class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        # possible connections:
        # 1-1, 1-3, 1-5 (l -> r)
        # 2-2, 2-6, 2-5 (t -> bottom)
        # 3-5, 3-6, 3-2 (t -> b)
        # 4-5, 4-6, 4-2 (t->b)
        # 5-
                v = [[0] * len(grid[0]) for i in range(len(grid))]
        q = deque()
        start = [0,0]
        finish = [len(grid) - 1, len(grid[0])-1]
        q.append(start)
        xdir = [1,-1,0,0] # bottom, up # row + 1, -1
        ydir = [0,0,1,-1] # right, left 
        v[0][0] = 1
        while (len(q) > 0):
            # print(q)
            out = q.popleft()
            r, c = out[0], out[1]
            if r == finish[0] and c == finish[1]:
                return True
            for i in range(len(xdir)):
                rn = r + xdir[i]
                cn = c + ydir[i]
                if rn < 0 or cn < 0 or rn >= len(grid) or cn >= len(grid[0])\
                or v[rn][cn] == 1:
                    continue
                if i == 2: # looking at the cell to the right
                    if (grid[r][c] == 1 or grid[r][c] == 4 or grid[r][c] == 6) 
                        and (grid[rn][cn] == 3 or grid[rn][cn] == 5 or 
                        grid[rn][cn] == 1):
                        v[rn][cn] = 1
                        q.append([rn, cn])
                if i == 3: # looking at cell to the left
                    if (grid[r][c] == 1 or grid[r][c] == 3 or grid[r][c] == 5) 
                        and (grid[rn][cn] == 1 or grid[rn][cn] == 4 or 
                        grid[rn][cn] == 6):
                        v[rn][cn] = 1
                        q.append([rn, cn])
                if i == 0: # bottom
                    # print(grid[r][c], grid[rn][cn])
                    if (grid[r][c] == 2 or grid[r][c]==4 or grid[r][c]==3 ) 
                        and (grid[rn][cn] == 2 or grid[rn][cn] == 6 or 
                        grid[rn][cn] == 5):
                        q.append([rn, cn])
                        v[rn][cn] = 1
                if i == 1:
                    if (grid[r][c] == 2 or grid[r][c] == 6 or grid[r][c]== 5) 
                        and (grid[rn][cn] == 2 or grid[rn][cn] == 4 or 
                        grid[rn][cn]==3):
                        q.append([rn,cn])
                        v[rn][cn] = 1
        return False
                                                                    
class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        # backtracking / dfs
        q = []
        start = None
        end = None
        total_covered = 0
        ret = [0]
        v = [[0] * len(grid[0]) for i in range(len(grid))]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    start = (i,j,0)
                if grid[i][j] == 2:
                    end = (i,j)
                if grid[i][j] == 0:
                    total_covered +=1
        v[start[0]][start[1]] = 1
        # def solve(x, y, tc, debug):
        def solve(x, y, tc):
            if x == end[0] and y == end[1] and tc == total_covered+1:
                # print(debug)
                ret[0] +=1
            else:
                if grid[x][y] == 0 or grid[x][y]==1:
                    if x > 0 and v[x-1][y] == 0:
                        v[x-1][y] = 1
                        solve(x-1, y,tc+1)
                        # solve(x-1, y,tc+1,debug + [(x-1,y)])
                        v[x-1][y] = 0
                    if y > 0 and v[x][y-1] == 0:
                        v[x][y-1] = 1
                        solve(x, y-1,tc+1)
                        # solve(x, y-1,tc+1, debug+[(x,y-1)])
                        v[x][y-1] = 0
                    if x < len(grid)-1 and v[x+1][y]==0:
                        v[x+1][y] = 1
                        solve(x+1, y,tc+1)
                        # solve(x+1, y,tc+1, debug + [(x+1,y)])
                        v[x+1][y] = 0
                    if y < len(grid[0])-1 and v[x][y+1]==0:
                        v[x][y+1] = 1
                        solve(x, y+1,tc+1)
                        # solve(x,y+1,tc+1, debug+[(x,y+1)])
                        v[x][y+1] = 0
        solve(start[0], start[1], 0)
        # q.append(start)
        # while (len(q) > 0):
        #     out = q.pop()
        #     x = out[0]
        #     y = out[1]
        #     tc = out[2]
        #     print(tc)
        #     if tc == total_covered:
        #         ret +=1
        #     if grid[x][y] == 0 or grid[x][y]==1:
        #         if x > 0:
        #             q.append((x-1, y,tc+1))
        #         if x < len(grid)-1:
        #             q.append((x+1, y,tc+1))
        #         if y > 0:
        #             q.append((x, y-1,tc+1))
        #         if y < len(grid[0])-1:
        #             q.append((x, y+1,tc+1))
        return ret[0]
                                                                
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if len(grid) == 0:
            return 0
        count = 0
        ubound = 0
        dbound = len(grid[0]) - 1
        lbound = 0
        rbound = len(grid) - 1
        q = []
        v = [] # visited
        for i in range(len(grid)):
            for j in range (len(grid[0])):
                if grid[i][j] == "0":
                    continue
                else: 
                    t = (i,j)
                    count+=1
                    q.append(t)
                    while (len(q) > 0):
                        curr = q.pop()
                        # print("count is %d" %(count))
                        # print(i)
                        # print(j)
                        # print("curr is " + str(curr))
                        x = curr[0]
                        y = curr[1]
                        #udlr
                        if x+1 <= rbound and grid[x + 1][y] == "1":
                            grid[x+1][y] = "0"
                            q.append((x+1, y))
                        if x - 1 >= lbound and grid[x-1][y] == "1":
                            grid[x-1][y] = "0"
                            q.append((x-1, y))
                        if y - 1 >= ubound and grid[x][y-1] == "1":
                            grid[x][y-1] = "0"
                            q.append((x, y-1))
                        if y+1 <= dbound and grid[x][y+1] == "1":
                            grid[x][y+1] = "0"
                            q.append((x, y+1))
        return count
                                                                                        
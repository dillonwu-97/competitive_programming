from collections import defaultdict
class Solution:
    def countCornerRectangles(self, grid: List[List[int]]) -> int:
        # t = [[0] * len(grid[0]) for i in range(grid)]
        d = defaultdict(list)
        for i in range(len(grid[0])): # for each column, counter the row 
            for j in range(len(grid)): 
                if grid[j][i] == 1:
                    d[i].append(j)
                ret = 0
        for i in range(len(grid[0])):
            for j in range(i+1, len(grid[0])):
                temp = set(d[i]).intersection(d[j])
                # print(i, j, temp)
                if len(temp) >= 2:
                    ret += (len(temp) - 1) * len(temp) // 2
        # print(d)
        return ret
                    
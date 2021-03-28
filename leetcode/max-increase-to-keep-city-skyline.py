import numpy as np
class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        t = 0
        rm = []
        cm =[]
        for i in grid:
            rm.append(max(i))
        for i in np.array(grid).T:
            cm.append(max(i))
        # print(rm, cm)
        for i in range(len(grid)):
            for j in range(len(grid)):
                t += abs(min(rm[i],cm[j]) - grid[i][j])
        return t
import numpy as np
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        # Alternate between searching rows and columns 
        # keep looking for element less than or equal to target in rows
        # look for element greater than or equal to target in columns 
        if len(matrix) == 0:
            return False
        col = len(matrix[0])-1
        row = 0
        while row >= 0 and col >=0 and row < len(matrix) and col < len
            (matrix[0]):
            # print(matrix[row][col])
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                col -=1
            elif matrix[row][col] < target:
                row +=1
        return False
                    
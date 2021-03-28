import numpy as np
class Solution(object):
    def luckyNumbers (self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        mini = []
        for i in matrix:
            mini.append((min(i)))
        mini = set(mini)
                m = np.asarray(matrix)
        m2 = np.transpose(m).tolist()
                maxi = []
        for i in m2:
            maxi.append((max(i)))
                    return set(maxi).intersection(mini) 
                                        
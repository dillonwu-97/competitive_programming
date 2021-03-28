class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        # upper bound 
        # lower bound
        # left bound
        # right bound
        # go left -> go down -> go right -> go up -> repeat
        if len(matrix) == 0:
            return []
        s = len(matrix[0]) * len(matrix)
                upper = 0
        lower = len(matrix)-1
        left = 0
        right = len(matrix[0])-1
                total = 0
        ret = []
        i=1
        while (len(ret) != s and (left!= right or lower!= upper)):
            # print(left, right, upper, lower)
            current = left
            while (len(ret) != s and current != right):
                ret.append(matrix[upper][current])
                current +=1
            current = upper
            while (len(ret) != s and current != lower):
                ret.append(matrix[current][right])
                current +=1
            current = right
            while(len(ret) != s and current != left):
                ret.append(matrix[lower][current])
                current -=1
            current = lower
            while(len(ret) != s and current != upper):
                ret.append(matrix[current][left])
                current-=1
            # updating limits
            right-=1
            left+=1
            lower -=1
            upper +=1
            # print(ret)
        if len(ret) != s:
            ret.append(matrix[left][right])
        return ret
                    
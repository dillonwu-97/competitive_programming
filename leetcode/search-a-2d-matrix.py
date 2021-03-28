class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # binary search
        up = 0 # row left
        down = len(matrix)
        left = 0
        right = len(matrix[0])
                # guidepost
        def bst(a, l, r, t):
            if l > r:
                return -1
            m = (l + r) // 2
            if (a[m] < t):
                bst(a, m + 1, r, t)
            elif a[m] > t:
                bst(a, l, m, t)
            else:
                return m
                    # log(n) search on first column
        def find_row (a, l, r, t) :
            # bisect right
            if l >= r:
                return l-1
            m = (l + r) // 2
            if a[m][0] < t:
                return find_row(a, m+1, r, t)
            elif a[m][0] > t:
                return find_row(a, l, m, t)
            else:
                return m
                    def find_t(a, l, r, t):
            if (l >= r):
                return False
            m = (l + r) // 2
            if ( a[m] < t):
                return find_t(a, m+1, r, t)
            elif (a[m] > t):
                return find_t(a, l, m, t)
            else:
                return True
                if target > matrix[len(matrix) - 1][0]:
            return find_t(matrix[len(matrix)-1], 0, len(matrix[0]), target)
        elif target < matrix[0][0]:
            return False
        else:
            row = find_row(matrix, 0, len(matrix), target)
            return find_t(matrix[row], 0, len(matrix[row]), target)
                # log(m) search on that row
                                # could also just flatten matrix and search
        # but the point is to do a more efficient search 
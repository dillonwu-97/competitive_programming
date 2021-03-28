class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        # [1 2 3 4 5] 3 123 124 125 134 so bruteforce / recursion swap
        ret = []
        def solve(l, start, n, k):
            if k == 0:
                ret.append(l.copy())
                return
            for i in range(start,n+1):
                l.append(i)
                solve(l, i+1, n, k-1)
                l.pop()
        solve([], 1, n, k)
        return ret
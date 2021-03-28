class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        a = [p[0] for p in points]
        a.sort()
        b = [a[i] - a[i-1] for i in range(1, len(a))]
        return max(b)
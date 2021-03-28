from collections import Counter
class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        a = [min(i[0], i[1]) for i in rectangles]
        b = Counter(a)
        return b[max(b.keys())]
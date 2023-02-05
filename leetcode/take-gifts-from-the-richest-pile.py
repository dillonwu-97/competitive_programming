import heapq
import math
class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        gifts = [-1 * i for i in gifts]
        heapq.heapify(gifts)
        for i in range(k):
            o = -1 * math.isqrt(-1 * heapq.heappop(gifts))
            heapq.heappush(gifts, o)
        ret = 0
        for i in gifts:
            ret += (-1 * i)
        return ret
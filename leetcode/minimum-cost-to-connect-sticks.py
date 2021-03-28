import heapq
class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        #4, 9, 17
        # use heaps
                        h = []
        for i in sticks:
            heappush(h, i)
        ret = 0
        while (len(h) > 1):
            a = heappop(h)
            b = heappop(h)
            i = a + b
            heappush(h, i)
            ret += i
        return ret
            
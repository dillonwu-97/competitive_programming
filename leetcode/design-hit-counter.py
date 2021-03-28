import bisect
class HitCounter:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.h = []
            def hit(self, timestamp: int) -> None:
        """
        Record a hit.
        @param timestamp - The current timestamp (in seconds granularity).
        """
        self.h.append(timestamp)
            def getHits(self, timestamp: int) -> int:
        """
        Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity).
        """
        # past five minutes means getting rid of the first elements
        if timestamp > 300: 
            s = timestamp - 300 + 1
        else: 
            s = 0
        e = timestamp
        # print(s, e, bisect.bisect_left(self.h,s), self.h)
        return len(self.h) - bisect.bisect_left(self.h, s)
        # Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)
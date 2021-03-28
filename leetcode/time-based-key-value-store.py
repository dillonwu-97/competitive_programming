from collections import defaultdict
from bisect import bisect_right
class TimeMap:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.time = defaultdict(list)
        self.vals = defaultdict(list)
            def set(self, key: str, value: str, timestamp: int) -> None:
        # print(key, value, timestamp)
        self.time[key].append(timestamp)
        self.vals[key].append(value)
            def get(self, key: str, timestamp: int) -> str:
        # get requires binary search
        if (len(self.time[key])== 0):
            return ""
        else:
            t = -1
            # print("time is ", self.time)
            # print("val is ", self.vals)
            # for i in range(len(self.time[key])):
            #     if self.time[key][i] > t and timestamp >= self.time[key][i]:
            #         # print(timestamp, self.time[key][i])
            #         t = i
            ret = bisect_right(self.time[key], timestamp) - 1
            # print(timestamp, ret, self.time[key])
            if ret == -1:
                return ""
            else:
                # print(self.vals[key], self.vals[key][t])
                return self.vals[key][ret]
# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
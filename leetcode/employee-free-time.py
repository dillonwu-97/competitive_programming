"""
# Definition for an Interval.
class Interval:
    def __init__(self, start: int = None, end: int = None):
        self.start = start
        self.end = end
"""
import heapq
class Solution:
    def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
        ret = []
        q = []
        for i in range(len(schedule)):
            for j in range(len(schedule[i])):
                # print(schedule[i][j].start)
                heappush(q, (schedule[i][j].start, schedule[i][j].end))
                # print(q)
        # print(q)
        max_val = -1
        while (len(q) > 0):
            out = heappop(q)
            current_min = out[0]
            current_max = out[1]
            if current_min > max_val:
                ret.append(Interval(start=max_val, end=current_min))
            if current_max > max_val:
                max_val = current_max
        ret = ret[1:]
        return ret
                
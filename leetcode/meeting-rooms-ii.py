class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if len(intervals) == 0: return 0
                # just have to find the number in the range of the most numbers
        q = []
        for i in range(len(intervals)):
            q.append((intervals[i][0], 0))
            q.append((intervals[i][1], 1))
        q = sorted(q, key=lambda x: (x[0], -x[1]))
        # print(q)
        current = 0
        m = 0
        # print(q)
        for i in range(len(q)):
            if q[i][1] == 0: # start
                current+=1
            else:
                if current > m: m = current
                current-=1
        return m
        # too slow
        # start = [i[0] for i in intervals]
        # end = [i[1] for i in intervals]
        # t = [0]*max(end)
        # for i,j in enumerate(start):
        #     t[start[i]:end[i]] = map(lambda x: x+1, t[start[i]:end[i]])
        # # print(t)
        # return max(t)
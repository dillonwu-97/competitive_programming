from collections import deque
class Solution:
    def trap(self, height: List[int]) -> int:
        d = deque([0])
        ret = 0
        for i in range(1, len(height)):
            # if d is of size 2
            while len(d) > 1 and height[i] > height[ d[-1] ]:
                d.pop()
            d.append(i)
            if height[ d[ -1 ]] >= height [ d[0] ]:
                start = d.popleft()
                end = i
                for j in range(start, end):
                    ret += height[start] - height[j]
                # descending slope case
        while len(d) > 1:
            start = d.popleft()
            end = d[0]
            for j in range(start+1, end):
                ret += height[end] - height[j]
        return ret
                                    
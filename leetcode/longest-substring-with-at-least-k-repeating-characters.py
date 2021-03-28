from collections import Counter
class Solution(object):
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        def solve(s, k):
            d = Counter(s)
            thresh = dict((i,0) for i in d.keys() if d[i] < k)
            m = -1
            prev = 0
            # print(thresh)
            if len(thresh) == 0:
                return sum(d.values())
            elif len(s) < k:
                return 0
            for i in range(0,len(s)):
                if s[i] in thresh:
                    # print("iter through ", s[prev:i])
                    temp = solve(s[prev:i], k)
                    prev = i
                    if temp > m:
                        m = temp
            # last one / edge case
            # print("edge case ", prev, i, s[prev+1:i+1])
            m = max (solve(s[prev+1:i+1], k), m)
            return m
                        ret = solve(s,k)
                    return ret
                                                                                    
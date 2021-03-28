class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0: return 0
        if len(s) == 1: return 1
        d = {}
        d[s[0]] = 0
        m = 1
        start = 0
        for i in range(1,len(s)):
            # print(d)
            if s[i] in d:
                # print(i, start, d[s[i]])
                temp = i - start
                start = max(start, d[s[i]] + 1)
                if temp > m:
                    m = temp 
            d[s[i]] = i
        # print(i, start)
        return max(m, i+1 - start)
                    
class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        if k == 0: return 0
        d = {}
        count = 0
        i = 0
        j = 0
        ret = 0
        while (i < len(s)):
            # print(d)
            if len(d) <= k:
                if s[i] in d:
                    d[ s[i]] += 1
                else:
                    d[ s[i] ] = 1
                count += 1
            while len(d) > k and j < i:
                d[ s[j] ] -=1
                count -=1
                if d[ s[j] ] == 0:
                    del d[ s[j] ]
                j+=1
            if count > ret:
                ret = count
            i+=1
        return ret
            
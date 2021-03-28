from collections import Counter
class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        # solution: start from largest and work to smallest
        words.reverse()
        wordlist = Counter(words)
        d = {}
                def solve(word):
            hi = 0
            if word not in wordlist:
                return 0
            for i in range(len(word)): 
                temp = word[:i] + word[i+1:] 
                if temp in wordlist:
                    if temp in d:
                        hi = max(d[ temp ], hi)
                    else:
                        current = solve(temp)
                        hi = max(hi, current)
            d[ word ] = hi+1
            return hi + 1
        ret = 0
        for i in range(len(words)):
            if words[i] not in d:
                length = solve(words[i])
                ret = max(ret, length)
            else:
                ret = max(ret, d[words[i]])
        # print(d)
        return ret
                        
from collections import Counter
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        d = Counter(s)
        return sum (i % 2 for i in d.values()) < 2
                # d = Counter()
        # for i in s:
        #     d[i] += 1
        # parity = 0
        # for i in d.keys():
        #     if d[i] % 2 == 1:
        #         parity += 1
        #     if parity > 1:
        #         return False
        # return True
            
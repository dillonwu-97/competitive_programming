from collections import Counter
class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
                        d = set(jewels)
        return sum(s in d for s in stones)
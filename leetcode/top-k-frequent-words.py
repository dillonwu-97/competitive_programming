from collections import Counter
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        d = Counter(words)
        a = sorted(d.items(), key=lambda item: (-item[1], item[0]))
        a = a[:k]
        ret = []
        for i in range(len(a)):
            ret.append(a[i][0])
        return ret
        
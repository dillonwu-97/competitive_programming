from collections import Counter
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        d = {}
        for i in range(len(order)):
            d[ order[i] ] = i
                # shorter words before longer words
        for i in range(1,len(words)):
            a = words[i-1]
            b = words[i]
            j = 0
            k = 0
            while (j < len(a) and k < len(b)):
                if d[ a[j] ] > d[ b[k] ]:
                    return False
                # found a letter that is correct
                elif d[ a[j] ] < d[ b[k] ]:
                    break
                j+=1
                k+=1
            if k == len(b) and j != len(a):
                return False
                        return True
                    
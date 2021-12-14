from collections import Counter
class Solution:
    def originalDigits(self, s: str) -> str:
        # a = ["zero", "one", "two", "three", "four", "five","six", "seven", "eight", "nine"]
        # a = ["z", "on", "w", "ee", "fr", "fv", "x", "sv", "g", "nn"] # unique identifiers
        # "one", "three", "four", "five" "seven" "nine"
                    # count all of the characters 
        # prune all the letters with one identifier
        # prune seven since it is the only one with an s
        # prune five since it is the only one with v
        # prune four since it is the only one with f
        # prune three since it is the only one with r
        # prune nine since it is the only one with i
        # prine one
                a = ["zero", "two", "six", "eight", "seven", "five", "four", "three", "nine", "one"]
        b = ["z", "w", "x", "g", "s", "v", "f", "r", "i", "o"]
        c = [0, 2, 6, 8, 7, 5, 4, 3, 9, 1]
        d = Counter(s)
        ret = {}
        for i in range(len(a)):
            # print(d)
            if b[i] in d and d[b[i]] > 0:
                temp = d[b[i]]
                for j in range(len(a[i])):
                    d[ a[i][j] ] -= temp
                ret[c[i]] = temp
        s = ""
        for k in sorted(ret.keys()):
            s += str(k) * ret[k]
        return s
                                                                
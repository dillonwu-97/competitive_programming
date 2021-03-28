class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        count = 0
        a = []
        b= []
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                count +=1
                a.append(s1[i])
                b.append(s2[i])
        if count == 2:
            if a[0] == b[1] and a[1] == b[0]:
                return True
            return False
        if count == 0:
            return True
        return False
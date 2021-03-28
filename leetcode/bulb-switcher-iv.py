class Solution:
    def minFlips(self, target: str) -> int:
        if len(target) == 0:
            return 0
        start = target[0]
        if start == "0":
            ret = 0
        else:
            ret = 1
                for i in range(1,len(target)):
            if target[i] == start:
                continue
            else:
                ret +=1
                start = target[i]
        return ret
                    
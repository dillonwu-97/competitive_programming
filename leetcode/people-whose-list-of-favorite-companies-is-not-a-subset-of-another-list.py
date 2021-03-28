class Solution:
    def peopleIndexes(self, fc: List[List[str]]) -> List[int]:
        h1 = []
        ret = []
        for i in range(len(fc)):
            flag = 0 
            for j in range(len(h1)):
                if set(fc[i]).issuperset(set(h1[j])):
                    flag = 1
                    h1[j] = fc[i]
                    ret[j] = i
                elif set(fc[i]).issubset(set(h1[j])):
                    flag = 1
                    break
            if flag == 0:
                h1.append(fc[i])
                ret.append(i)
        ret = list(set(ret))
        ret.sort()
        return ret
            
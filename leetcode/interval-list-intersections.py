class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: 
        List[List[int]]) -> List[List[int]]:
        i= 0
        j = 0
        ret = []
        while (i < len(firstList) and j < len(secondList)):
            if firstList[i][0] > secondList[j][1]:
                j+= 1
                continue
            elif secondList[j][0] > firstList[i][1]:
                i+=1
                continue
            ret.append([max(firstList[i][0], secondList[j][0]), min
                (firstList[i][1], secondList[j][1])])
            if (firstList[i][1] > secondList[j][1]):
                j+=1
            else:
                i+=1
        return ret
        
class Solution(object):
    def groupThePeople(self, groupSizes):
        """
        :type groupSizes: List[int]
        :rtype: List[List[int]]
        """
        all_groups = {}
        for i in range(len(groupSizes)):
            if groupSizes[i] not in all_groups:
                all_groups[ groupSizes[i] ] = [i]
            else: all_groups [groupSizes[i]].append(i)
        result = []
        flag = True
        while (flag == True):
            flag = False
            for i in all_groups.keys():
                if len(all_groups [i] ) == i: 
                    result.append( all_groups[i])
                    all_groups[i] = []
                elif len(all_groups[i]) > i:
                    result.append (all_groups[i][0:i])
                    all_groups[i] = all_groups[i][i:]
                    flag = True
        print(result)
        return result
                
class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
         # Cycle detection
        d = {}
        counter = [0] * numCourses
        for i in prerequisites:
            if i[0] not in d:
                d[i[0]] = [i[1]]
            else:
                d[i[0]].append(i[1])
            counter[i[1]] +=1
        # print(d)
        visited = [-1] * numCourses # previously visited
        sol = []
        for i in range(len(visited)):
            # print(visited[i])
            if visited[i] != -1:
                continue
            else:
                visiting = {}
                current = [i]
                while (len(current) > 0):
                    # print(visiting)
                    temp = current[-1]
                    if temp not in d:
                        visited[temp] = 0
                        current.pop()
                        sol.append(temp)
                        continue
                    # if temp is in d
                    count = 0
                    for k in d[temp]:
                        if visited[k] != 0:
                            counter[k] -=1 
                            if counter == 0:
                                sol.append(k) 
                            if counter[k] < 0:
                                return []
                            current.append(k)
                            count +=1
                    if count == 0:
                        current.pop()
                        visited[temp] = 0
                        sol.append(temp)
                        sol = list(dict.fromkeys(sol))
        return sol
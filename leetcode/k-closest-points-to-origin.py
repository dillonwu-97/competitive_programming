class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        d = {}
        for i in range(len(points)):
            dis = points[i][0] ** 2 + points[i][1]**2
            if dis not in d:
                d[dis] = [points[i]]
            else:
                d[dis].append(points[i])
        dsorted = [i for k, v in sorted(d.items(), key= lambda item: item[0]) 
            for i in v ]
        # print(d)
        return dsorted[:K]
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        # bfs works
        # dsu also works
        v = [0] * len(isConnected)
                def solve(index, value):
            # print(index, value, v)
            for i in range(len(isConnected[index])):
                if v[i] != 0:
                    continue
                if i == index:
                    # print(i, index)
                    v[i] = value
                elif isConnected[index][i] == 1:
                    solve(i, value)
                            count = 1
        for i in range(len(isConnected)):
            # print(v)
            if v[i] == 1:
                continue
            solve(i, count)
            count += 1
        # print(v)
        return len(set(v))
#         count =1
#         for i in range(len(isConnected)):
#             for j in range(len(isConnected)):
#                 if v[i] == 0 and i == j:
#                     v[i] = count
#                     count +=1
#                 if isConnected[i][j] == 1:
#                     v[j] = v[i]
                    #         print(v)
#         return len(set(v))
                                
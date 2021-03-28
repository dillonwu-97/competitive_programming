from collections import defaultdict
class Solution:
    def deleteTreeNodes(self, nodes: int, parent: List[int], value: List[int]) 
        -> int:
        d = defaultdict(list)
        zero_count = 0
                q = []
        for i in range(len(value)):
            d[parent[i]].append(i)
        # print(d)
                q.append(0)
        iterate = []
        while(len(q) > 0):
            out = q.pop(0)
            iterate.append(out)
            q+= d[out]
        # print(iterate)
                zero_count = 0
        # print(iterate)
        total_size = [0] * len(iterate) # size of each subtree
        for j in range(len(iterate)-1, -1, -1):
            i = iterate[j]
            if value[i] != 0:
                value[parent[i]] += value[i]
                total_size[parent[i]] += total_size[i] + 1
            else:
                # print(i)
                zero_count += total_size[i] + 1
                total_size[i] = 0
        return len(value) - zero_count
            # heappush(q, (parent[i] * -1, i))
        # while(len(q) > 0):
        #     out = heappop(q)
        #     parent = out[0] * -1
        #     i = out[1]
        #     if value[i] != 0:
        #         d[parent].append(i)
        #         value[parent] += value[i]
        #     else:
        #         zero_count += 1
        #         zero_count += len(d[i])
        #     print(parent, i, value[i])
        return len(value) - zero_count
                #             38
# [-1,7,0,2,22,25,2,0,7,14,25,22,25,14,0,22,22,2,14,14,22,14,25,2,14,0,32,2,2
    ,32,25,22,0,2,2,22,14,14]
# [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
    ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
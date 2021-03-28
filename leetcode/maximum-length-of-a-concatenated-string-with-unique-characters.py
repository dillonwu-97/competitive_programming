from collections import Counter
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        ret = [set()]
        for i in range(len(arr)):
            if len(arr[i]) > len(set(arr[i])): continue
            # print(arr[i], ret)
            a = set(arr[i])
            for j in ret:
                if len(j&a) > 0: 
                    # print("not appending ", j, a)
                    continue
                else: 
                    # print("appending ", j, a)
                    ret.append(j | a)
        # print(ret)
        return max(len(i) for i in ret)
                                                # brute force is bad
        # brute force solution
#         store = {}
#         def solve(arr, start, w):
#             ret = w
#             d = Counter(ret)
#             if w in store:
#                 return store[w]
#             for i in range(start, len(arr)):
#                 temp = d.copy()
#                 flag = 0
#                 for ch in arr[i]:
#                     if ch not in temp:
#                         temp[ch] = 1
#                     else:
#                         flag = 1
#                         break
#                 if flag == 0:
#                     d = temp.copy()
#                     current = solve(arr, i + 1, w + arr[i])
#                     store[w + arr[i]] = current
#                     if (len(current) > len(ret)):
#                         ret = current
#                 current = solve(arr, i + 1, w)
#                 store[w] = current
#                 if (len(current) > len(ret)):
#                     ret = current
#                 # print("same pointers?")
#                 # print(temp)
#                 # print(d)
#             if ret not in store:
#                 store[ret] = len(ret)
#             return ret
#         ret = ""
#         # for i in range(len(arr)):
#         current = solve(arr, 0, "")
#         if len(current) > len(ret):
#             ret = current
        #         return len(ret)
                
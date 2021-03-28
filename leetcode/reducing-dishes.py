class Solution(object):
    def maxSatisfaction(self, satisfaction):
        """
        :type satisfaction: List[int]
        :rtype: int
        """
        # o(n)
        satisfaction.sort()
        ss = [0] * (len(satisfaction)+1)
        start = 0
        for i in range(len(satisfaction)):
            ss[i+1] = ss[i] + satisfaction[i]
                # print(satisfaction)
        # print(ss)
        # [a b c] c + before > 0 and 
        index = -1
        for i in range(len(ss)-1):
            prev = ss[-2] - ss[i]
            # print(prev, satisfaction[-1])
            if satisfaction[-1] + prev > 0:
                index = i        
                break
        # print("index is ", index)
        if index == -1:
            return 0
        ret = 0
        m = 1
        for i in range(index, len(satisfaction)):
            ret += satisfaction[i] * m
            m+=1
        return max(ret, 0)
                                # on^2
#         satisfaction.sort()
#         # print(satisfaction)
#         ret = [0] * len(satisfaction)
#         for i in range(len(satisfaction)):
#             start = 1
#             running = 0
#             for j in range(i, len(satisfaction)):
#                 if j == i:
#                     running = start * satisfaction[j]
#                     ret[j] = max(ret[j], running)
#                 else: 
#                     running += start * satisfaction[j]
#                     ret[j] = max(ret[j], running)
#                 start +=1
#         # print(ret)
#         # print(satisfaction)
#         return ret[-1]
        
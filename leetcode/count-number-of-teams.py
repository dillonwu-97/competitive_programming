class Solution:
    def numTeams(self, rating: List[int]) -> int:
        # naiive: 
        # three for loops
                # idea: sort by index 
                # two loops
        q = []
        qback = []
        ret = 0
        for i in range (len(rating)):
            for j in range(i, len(rating)):
                if rating[j] > rating[i]:
                    q.append(j)
                if rating[j] < rating[i]:
                    qback.append(j)
                for i in range(len(q)):
            for j in range(q[i], len(rating)):
                if rating[j] > rating [ q[i] ]:
                    ret +=1
                        for i in range(len(qback)):
            for j in range(qback[i], len(rating)):
                if rating[j] < rating [ qback[i] ]:
                    ret +=1
        return ret